#include"queue.h"
#include<linux/module.h>
#include<linux/kthread.h>
#include<linux/wait.h>
#include<linux/mutex.h>
#include<linux/slab.h>

enum thread_index {WAKING_THREAD, THREAD};

int scheduling_thread(void *data) {
        struct _work_struct *el, *ne;
        struct _worker *do_later, *el2, *ne2;
        struct _workqueue_struct *queue = (struct _workqueue_struct *)data;
        DEFINE_WAIT(wait);
        for(;;) {
                mutex_lock(&queue->lock);
                list_for_each_entry_safe(el, ne, &queue->worklist, entry) {
                        el->pending = 0;
                        list_del(&el->entry);
                        do_later = kmalloc(sizeof(struct _worker), GFP_KERNEL);
                        if(IS_ERR(do_later))
                                return -ENOMEM;
                        do_later->work_to_do = el;
                        INIT_LIST_HEAD(&do_later->entry);
                        list_add_tail(&do_later->entry, &queue->scheduled);
                }
                mutex_unlock(&queue->lock);
                list_for_each_entry_safe(el2, ne2, &queue->scheduled, entry) {
                        el2->work_to_do->func(el2->work_to_do);
                        list_del(&el2->entry);
                        kfree(el2);
                }
                add_wait_queue(&(queue->wait_queue), &wait);
                while(!queue->condition) {
                        prepare_to_wait(&(queue->wait_queue), &wait, TASK_INTERRUPTIBLE);
                        if(kthread_should_stop()) {
                                pr_alert("stopping scheduling thread");
                                return 0;
                        }
                        pr_info("[scheduler]: awake");
                        schedule();
                }
                queue->condition = false;
                finish_wait(&(queue->wait_queue), &wait);

        }

}

int waking_thread(void *data) {
        struct _workqueue_struct *queue = (struct _workqueue_struct *)data;
        for(;;) {
                if(kthread_should_stop()) {
                        pr_alert("stopping waking thread");
                        return 0;
                }
                set_current_state(TASK_INTERRUPTIBLE);
                if(schedule_timeout(5*HZ))
                        pr_info("Signal received");
                queue->condition = true;
                wake_up_all(&(queue->wait_queue));
        }
}


int create_simple_workqueue(struct _workqueue_struct **queue) {
        *queue = kmalloc(sizeof(struct _workqueue_struct), GFP_KERNEL);
        if(IS_ERR(*queue)) {
                pr_alert("Error allocating memory");
                return -ENOMEM;
        }
        mutex_init(&(*queue)->lock);
        INIT_LIST_HEAD(&(*queue)->scheduled);
        INIT_LIST_HEAD(&(*queue)->worklist);
        init_waitqueue_head(&((*queue)->wait_queue));
        (*queue)->thread[THREAD] = kthread_run(scheduling_thread, *queue, "scheduling thread");
        (*queue)->thread[WAKING_THREAD] = kthread_run(waking_thread, *queue, "waking thread");
        return 0;

}

void destroy_simple_workqueue(struct _workqueue_struct *queue) {
        struct _work_struct *el, *ne;
        struct _worker *el2, *ne2;
        if(!IS_ERR(queue)) {
                kthread_stop(queue->thread[WAKING_THREAD]);
                kthread_stop(queue->thread[THREAD]);
                list_for_each_entry_safe(el, ne, &queue->worklist, entry) {
                        list_del(&el->entry);
                }
                list_for_each_entry_safe(el2, ne2, &queue->scheduled, entry) {
                        list_del(&el2->entry);
                        kfree(el2);
                }
                kfree(queue);
        }
}

bool add_to_queue(struct _workqueue_struct *queue, struct _work_struct *work) {
        if(work->pending == 1)
                return false;
        work->pending = 1;
        mutex_lock(&queue->lock);
        INIT_LIST_HEAD(&work->entry);
        list_add_tail(&work->entry, &queue->worklist);
        mutex_unlock(&queue->lock);
        return true;
}

void init_work(struct _work_struct *work, void (*funct)(struct _work_struct *)) {
        work->func = funct;
        work->pending = 0;
}

 
