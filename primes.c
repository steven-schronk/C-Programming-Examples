//This C Program takes a input for printing all the prime numbers that are below the input number

#include <stdio.h>
#include <stdbool.h>

//Function Declared of checking a number is prime or not
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

////Function Defined of checking a number is prime or not
int isPrime(int n)
{
        int dev;

        for(dev = 2; dev <= n/2; dev++)
        {
                if((n % dev) == 0) { return false; }
        }
	return true;
}
