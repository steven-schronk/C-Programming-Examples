#include <stdio.h>

int main()
{
	int in  = 0;
	int temp = 0;
	int out = 0;
	printf("Enter 4 digit number: ");
	scanf("%d", &in);

	temp = in / 1000;
	in -= temp * 1000;
	out += temp;

	temp = in / 100;
	in -= temp * 100;
	out += temp;

	temp = in / 10;
	in -= temp * 10;
	out += temp;

	out += temp;

	printf("Sum of digits %d\n", out);
}

