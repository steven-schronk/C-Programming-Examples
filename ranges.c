/*

Prints ranges of data types in C

*/

#include <stdio.h>
#include <limits.h>

int main()
{
	printf("\n\nThis Computer Supports the following\n");
	printf("Datatype specifications:\n\n");

	int i = sizeof(int);
	printf("Size of Int: %d\n", i);
	printf("INT_MIN: %d\n", INT_MIN);
	printf("INT_MAX: %d\n", INT_MAX);
	printf("\n");

	i = sizeof(char);
	printf("Size of Char: %d\n", i);
	printf("CHAR_BIT: %d\n", CHAR_BIT);
	printf("CHAR_MAX: %d\n", CHAR_MAX);
	printf("CHAR_MIN: %d\n", CHAR_MIN);
	printf("\n");

	i = sizeof(double);
	printf("Size of Double: %d\n", i);
	printf("\n");

	i = sizeof(long);
	printf("Size of Long: %d\n", i);	
	printf("LONG_MIN: %ld\n", LONG_MIN);
	printf("LONG_MAX: %ld\n", LONG_MAX);
	printf("\n");

	i = sizeof(short);
	printf("Size of Short: %d\n", i);
	printf("SHRT_MIN: %d\n", SHRT_MIN);
	printf("SHRT_MAX: %d\n", SHRT_MAX);
	printf("\n");

	return 0;
}
