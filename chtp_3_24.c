#include <stdio.h>

int main()
{
	printf("N\tN2\tN3\tN4\n");
	for(int i = 0; i <= 10; i++)
	{
		printf("%d\t%d\t%d\t%d\n", i, i*i, i*i*i, i*i*i*i);
	}
	return 0;
}
