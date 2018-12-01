#include "test.h"

int main()
{
    int retval;
    int size=5;
    int my_pid=getpid();
    int password=234123;
    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    printf("Check 1 Start");
	TASSERT((retval=is_changeable(-3)) == -1,
            "is_changeable: should return -1 when pid is negative (retval=%d)",retval);
    TASSERT(errno == ESRCH,
            "is_changeable: should set errno=ESRCH when pid is negative (errno=%d)",errno);
	
	printf("Check 2 Start");		
	TASSERT((retval=make_changeable(-3)) == -1,
            "make_changeable: should return -1 when pid is negative (retval=%d)",retval);
    TASSERT(errno == ESRCH,
            "make_changeable: should set errno=ESRCH when pid is negative (errno=%d)",errno);
	
	printf("Check 3 Start");
	TASSERT((retval=get_policy(my_pid)) == -1,
            "get_policy: should return -1 when process is not SC (retval=%d)",retval);
    TASSERT(errno == EINVAL,
            "get_policy: should set errno=EINVAL when process is not SC (errno=%d)",errno);		
		
	printf("Check 4 Start");	
	TASSERT((retval=make_changeable(my_pid)) == 0,
            "make_changeable: should return 0 on success (retval=%d)",retval);

	printf("Check 5 Start");		
	TASSERT((retval=make_changeable(my_pid)) == -1,
            "make_changeable: should return -1 when calling process is already SC (retval=%d)",retval);
    TASSERT(errno == EINVAL,
            "make_changeable: should set errno=EINVAL when calling process is already SC (errno=%d)",errno);		
	
	printf("Check 6 Start");
	TASSERT((retval=get_policy(my_pid)) == 0,
            "get_policy: should return 0 on success and regime is off (retval=%d)",retval);
    TASSERT(errno == EINVAL,
            "get_policy: should return 0 on success and regime is off (errno=%d)",errno);	
	
	printf("Check 7 Start");
    TASSERT((retval=change(2)) == -1,
            "change: should return -1 when val is not 0 or 1 (retval=%d)",retval);
    TASSERT(errno == EINVAL,
            "change: should set errno=EINVAL when val is not 0 or 1 (errno=%d)",errno);
	
	printf("Check 8 Start");
	TASSERT((retval=change(0)) == 0,
            "change: should return 0 on success (retval=%d)",retval);	
	
	printf("Check 9 Start");
	TASSERT((retval=change(1)) == 0,
            "change: should return 0 on success (retval=%d)",retval);	

	printf("Check 10 Start");		
	TASSERT((retval=get_policy(my_pid)) == 1,
            "get_policy: should return 1 on success and regime is on (retval=%d)",retval);
    TASSERT(errno == EINVAL,
            "get_policy: should return 1 on success and regime is on (errno=%d)",errno);			
	
change(0);

    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	return 0;
}