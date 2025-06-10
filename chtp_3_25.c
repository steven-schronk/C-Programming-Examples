#include <stdio.h>

int main()
{
	int current = 7;
	
	printf("N\tN+3\tN+6\tN+9\n\n");
	for(int i = 0; i < 5; i++)
	{
		for(int j = 0; j <= 9; j += 3)
		{
			printf("%d\t", current +j);
		}
		current += 7;
		printf("\n");
	}
	
	return 0;
}
