#include <stdio.h>

int main()
{
	unsigned int number, largest;
	number = largest = 0;
	for(int counter = 1; counter <= 10; counter++)
	{
		printf("Enter Number %d:", counter);
		scanf("%d", &number);
		if(number > largest) { largest = number; }
	}
	printf("Largest: %d\n", largest);
}
