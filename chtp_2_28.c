#include <stdio.h>

int main()
{
	int age;
	int max;
	printf("Enter Your Age:");
	scanf("%d", &age);

	max = 220 - age;
	
	printf("Max Rate: %d\n", max);
	printf("Range:  %f -> %f\n", max * .5, max * .85);
}
