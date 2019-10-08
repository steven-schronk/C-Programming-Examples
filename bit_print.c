/*

Prints out the bits contained in an integer value.

*/

#include <stdio.h>
#include <limits.h>

void bit_print(int a)
{
	int itr;
	int n = sizeof(int) * CHAR_BIT;  /* find size of ints for this macine */
	int mask = 1 << (n - 1); /* set mask to 1000000...000 */

	for(itr = 1; itr <= n; ++i)
	{
		putchar(((a & mask) == 0) ? '0' : '1');
		a <<= 1; /* shift over by 1 bit */
		if(itr % CHAR_BIT == 0 && itr < n)
			putchar(' ');
	}
	putchar('\n');

}

int main()
{
	int number;

	for(number = 0; number <= 16; ++number)
	{
		bit_print(number);
	}

	return 0;
}
