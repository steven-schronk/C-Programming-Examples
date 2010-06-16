#include <stdio.h>
#include <stdbool.h>

int isPrime(int);

int main(void)
{
	int num = 2;
	int max;

	printf("Input Maximum Prime: ");
	scanf("%d", &max);

	while ( num < max )
	{
		if(isPrime(num)) { printf("%d\n", num); }
		num++;
	}
	return 0;
}

int isPrime(int n)
{
	int dev = 2;
	n = n / 2;		/* optimization for algorithm */
	while(dev < n)
	{
		if(n % dev == 0) { return false; }
		dev++;
	}
	return true;
}
