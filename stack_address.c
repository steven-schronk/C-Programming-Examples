/*
	Program illustrates stack randomization of operating systems.

	Operating systems attempt to prevent security vulnerability by
	randomizing the stack location when a program starts.

	This helps prevent buffer overflow attacks.

	To test and see if this security measure is built into your
	system, run this program several times; if the stack address
	changes each time, it is likely that this is implemented on 
	your system.
*/

#include <stdio.h>

int main()
{
	int local;
	printf("local at %p\n", &local);
	return 0;
}
