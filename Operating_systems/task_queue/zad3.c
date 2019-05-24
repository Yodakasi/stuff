#include<linux/module.h>
#include"queue.h"

struct _workqueue_struct *queue;
struct _workqueue_struct *queue2;

static int flag = 1;
struct _work_struct norm_struct;

void normal_handler(struct _work_struct *work) {
        pr_info("it works!");
        if(flag)
                if(!add_to_queue(queue, work))
                        pr_alert("work already in queue");
}

void normal_handler_2(struct _work_struct *work) {
        pr_info("it works 2!");
}

_DECLARE_WORK(norm_struct_2, normal_handler_2);
_DECLARE_WORK(norm_struct_3, normal_handler_2);
_DECLARE_WORK(norm_struct_4, normal_handler_2);
_DECLARE_WORK(norm_struct_5, normal_handler_2);

static int __init mod_queue_init(void) {
        create_simple_workqueue(&queue);
        init_work(&norm_struct, normal_handler);
        if(!add_to_queue(queue, &norm_struct))
                pr_alert("work already in queue");
        if(!add_to_queue(queue, &norm_struct))
                pr_alert("work already in queue");
        create_simple_workqueue(&queue2);
        if(!add_to_queue(queue2, &norm_struct_2))
                pr_alert("work already in queue");
        if(!add_to_queue(queue2, &norm_struct_3))
                pr_alert("work already in queue");
        if(!add_to_queue(queue2, &norm_struct_4))
                pr_alert("work already in queue");
        if(!add_to_queue(queue2, &norm_struct_5))
                pr_alert("work already in queue");
        return 0;
}

static void __exit mod_queue_exit(void) {
        flag = 0;
        destroy_simple_workqueue(queue);
        destroy_simple_workqueue(queue2);

}

module_init(mod_queue_init);
module_exit(mod_queue_exit);

MODULE_LICENSE("GPL"); 
