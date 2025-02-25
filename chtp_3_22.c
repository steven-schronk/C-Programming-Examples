#include <stdio.h>

int main()
{
	int val;
	int count;
	printf("Enter an integer: ");
	scanf("%d", &val);
	count = val - 1;
	while(count > 1)
	{
		if((val % count) == 0) { printf("Not Prime\n"); return 0; }
		count--;
	}
	printf("Prime\n");
}
