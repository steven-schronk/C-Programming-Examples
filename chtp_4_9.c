#include <stdio.h>

int main()
{
	int count, num, avg, sum;
	printf("Enter number count:");
	scanf("%d", &count);
	for(int i = 1; i < count+1; i++)
	{
		printf("Enter %d number:", i);
		scanf("%d:", &num);
		sum += num;
	}
	avg = sum/count;
	printf("Sum: %d\n", sum);
	printf("Avg: %d\n", avg);
}
