#ifndef _QUEUE_H_
#define _QUEUE_H_

#include<linux/module.h>
#include<linux/list.h>
#include<linux/kthread.h>
#include<linux/mutex.h>

struct _work_struct {
        void (*func)(struct _work_struct *);
        struct list_head entry;
        int pending;
};

struct _worker {
        struct _work_struct *work_to_do;
        struct list_head entry;
};

struct _workqueue_struct {
        struct list_head worklist;
        struct list_head scheduled;
        struct task_struct *thread[2];
        wait_queue_head_t wait_queue;
        bool condition;
        struct mutex lock;
};

#define _DECLARE_WORK(n, f) \
        struct _work_struct n = {.func = f, .pending = 0}

int scheduling_thread(void *data);
int waking_thread(void *data);
int create_simple_workqueue(struct _workqueue_struct **qeueu);
void destroy_simple_workqueue(struct _workqueue_struct *queue);
bool add_to_queue(struct _workqueue_struct *queue, struct _work_struct *work);
void init_work(struct _work_struct *work, void (*func)(struct _work_struct *));

#endif
 
