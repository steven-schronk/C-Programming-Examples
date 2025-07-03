#include <stdio.h>

int main()
{
	int squares = 0;
	printf("How many squares: ");
	scanf("%d", &squares);
	for(int i = 0; i < squares; ++i)
	{
		if(i == 0 || i == squares - 1)
		{
			for(int j = 0; j < squares; ++j)
			{
				printf("*");
			}
		} else {
			for(int j = 0; j < squares; ++j)
			{
				if(j == 0 || j == squares - 1) 
				{
					printf("*");
				} else {
					printf(" ");
				}
			}
		}
		printf("\n");
	}
}
