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
	
	return 0;
}