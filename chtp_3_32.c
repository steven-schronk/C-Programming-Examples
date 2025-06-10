#include <stdio.h>

int main()
{
	int squares = 0;
	printf("How many squares: ");
	scanf("%d", &squares);
	for(int i = 0; i < squares; ++i)
	{
		for(int j = 0; j < squares; ++j)
		{
			printf("*");
		}
		printf("\n");
	}
}
