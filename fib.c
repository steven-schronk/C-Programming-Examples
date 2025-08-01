#include <stdio.h>

unsigned long long int fib(int n);

int main(void){
	for(int number = 0; number <= 40; number++)
	{
		printf("Fib: %d = %llu\n", number, fib(number));
	}
}
unsigned long long int fib(int n){
	if(0==n||1==n)
	{
		return n;
	} else {
		return fib(n-1)+fib(n-2);
	}
}
