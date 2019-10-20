#include<stdio.h>
#include<stdlib.h>

int fact(int ele)
{
	if(ele==1)
	return 1;
	else return ele*fact(ele-1);
}
int main()
{
	int n;
	printf("\nEnter the number: ");
	scanf("%d",&n);
	printf("Factorial of %d is %d: ",n,fact(n));
}
