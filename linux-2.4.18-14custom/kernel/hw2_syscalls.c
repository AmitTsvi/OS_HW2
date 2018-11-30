#include <linux/kernel.h>
#include <linux/sched.h>
#include <linux/slab.h>
#include <asm/uaccess.h>

typedef struct task_struct task_tt;

int sys_is_changeable(pid_t pid){
    task_tt *p = find_task_by_pid(pid);
    if(!p){
        return -ESRCH;
    }
    return p->policy == SCHED_CHANGEABLE;
}

int sys_make_changeable(pid_t pid){
    task_tt *p = find_task_by_pid(pid);
    if(!p){
        return -ESRCH;
    }
    if(current->policy == SCHED_CHANGEABLE || p->policy == SCHED_CHANGEABLE){
        return -EINVAL;
    }
    runqueue_t *rq = this_rq();
    spin_lock_irq(rq);
    sc_enqueue_task(p);
    spin_unlock_irq(rq);
    p->policy = SCHED_CHANGEABLE;
    return 0;
}

int sys_change(int val){
    if(val != 1 && val != 0){
        return -EINVAL;
    }
    runqueue_t *rq = this_rq();
    rq->regime=val;
    if(current->policy == SCHED_CHANGEABLE)
        current->need_resched=1;
    return 0;
}

int sys_get_policy(pid_t pid){
    task_tt *p = find_task_by_pid(pid);
    if(!p){
        return -ESRCH;
    }
    if(p->policy != SCHED_CHANGEABLE){
        return -EINVAL;
    }
    runqueue_t *rq = this_rq();
    return rq->regime;
}
