#include <errno.h>
#include <sched.h>
#include "hw2_syscalls.h"
#include <sys/types.h>
#include <unistd.h>
#include "stdio.h"
#include "assert.h"
#include "stdio.h"
#include "test.h"
int main(){
    FILE* file = fopen("test7.txt","w");
     struct sched_param param;
        param.sched_priority = 0;
        pid_t lowest=getpid();
         TASSERT( make_changeable(getpid())==0,
        "make_changeable: should return 0 when process is now CS ",__LINE__);
        TASSERT( change(1)==0,"change: should return 0 on success ",__LINE__);
        pid_t p = fork();
    int j=0;
    if(p==0){
        for(j=0;j<1000;j++){
            pid_t p1=fork();
            if(p1!=0){
                wait(NULL);
                goto out;
            }
        }
    }
    else{//father,lower pid
        wait(NULL);
    }
        out:
           TASSERT( is_changeable(getpid())==1,
    "is_changeable: should return 1 when process is CS ",__LINE__);
            TASSERT( get_policy(getpid())==1,
        "%d get_policy: should return 1 when policy enabled ",__LINE__);
        sched_setscheduler(getpid(), SCHED_OTHER, & param);
         TASSERT( is_changeable(getpid())==0,
    "is_changeable: should return 0 when process is not CS after setscheduler ",__LINE__);
     
        param.sched_priority=99;
        sched_setscheduler(getpid(), SCHED_FIFO, & param);
TASSERT( is_changeable(getpid())==0,
    "is_changeable: should return 0 when process is not CS after setscheduler ",__LINE__);
        TASSERT( make_changeable(getpid())==-1,
        "make_changeable: should return -1 when process is Real time process ",__LINE__);
        param.sched_priority=0;
        TASSERT( sched_setscheduler(getpid(), 3, & param) < 0,
        "setscheduler: should return negative when process is Real time process trying to become SC ",__LINE__);
        TASSERT( is_changeable(getpid())==0,
    "is_changeable: should return 0 when process is not CS after setscheduler ",__LINE__);
        sched_setscheduler(getpid(), SCHED_OTHER, & param);
        sched_setscheduler(getpid(), 3, & param);
        TASSERT( is_changeable(getpid())==1,
    "is_changeable: should return 1 when process is CS after setscheduler ",__LINE__);
    fprintf(file,"%d\n",get_policy(getpid()));
        return 0;
}
