#include <stdio.h>
int main()
{
	int x;
	printf("%s", "Enter an integer in the range of 1-20:");
	scanf("%d", &x);
	for(int i = 1; i <= x; i++) {
		for(int j = 1; j <= x; j++) {
			if(j==i)
				printf("%c", '@');
			else
				printf(" ");
		}
		printf("\n");
	}
}
