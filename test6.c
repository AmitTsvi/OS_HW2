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
    /* ~~~~~~~~~~~~ Stress tests ~~~~~~~~~~~~~~~ */
     struct sched_param param;
        param.sched_priority = 0;
        int i;
    for (i = 0; i < 1000000 ; i++) {
        TASSERT( is_changeable(getpid()) == 0,
        "Stress tests: is_changeable has failed", __LINE__);
        TASSERT( get_policy(getpid()) == -1,
        "Stress tests: get_policy has failed ", __LINE__);
        TASSERT( errno==EINVAL,
        "Stress tests: get_policy has failed", __LINE__);
        TASSERT( make_changeable(getpid()) == 0,
        "Stress tests: make_changeable has failed", __LINE__);
        TASSERT( get_policy(getpid()) == 0,
        "Stress tests: get_policy has failed ", __LINE__);
        TASSERT( change(1) == 0, 
        "Stress tests: change has failed ", __LINE__);
        TASSERT( get_policy(getpid()) == 1,
        "Stress tests: get_policy has failed ", __LINE__);
        TASSERT( change(0) == 0,
        "Stress tests: change has failed ", __LINE__);
        TASSERT( is_changeable(getpid()) == 1,
        "Stress tests: is_changeable has failed ", __LINE__);
        sched_setscheduler(getpid(), SCHED_OTHER, & param);
        TASSERT( is_changeable(getpid()) == 0,
        "Stress tests: is_changeable has failed ", __LINE__);
        TASSERT( make_changeable(getpid()) == 0,
        "Stress tests: make_changeable has failed ", __LINE__);
        TASSERT( get_policy(getpid()) == 0,
        "Stress tests: get_policy has failed ", __LINE__);
        sched_setscheduler(getpid(), SCHED_OTHER, & param);
    }
    printf("Test 6 passed\n");
}
