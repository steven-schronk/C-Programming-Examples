#include <stdio.h>

int main()
{
	int test;

	test = getchar() != EOF;

	printf("%d\n", test);
}
