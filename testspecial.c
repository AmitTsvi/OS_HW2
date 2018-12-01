#include "test.h"

int main()
{
    int retval;
    int size=5;
    int my_pid=getpid();
    int password=234123;
    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    
	printf("Check x1 Start");
	TASSERT((retval=change(1)) == 0,
            "change: should return 0 on success (retval=%d)",retval);
	
	printf("Check x2 Start");		
	TASSERT((retval=make_changeable(my_pid)) == -1,
            "make_changeable: should return -1 when pid is negative (retval=%d)",retval);
    TASSERT(errno == ESRCH,
            "make_changeable: should set errno=ESRCH when pid is negative (errno=%d)",errno);
	
	change(0);
    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	return 0;
}