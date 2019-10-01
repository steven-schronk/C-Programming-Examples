#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int i, x, col;

	printf("\n%s\n%s",
		"Some randomly distributed integers. ",
		"How many to print? ");
	scanf("%d", &x);
	printf("How many columns? ");
	scanf("%d", &col);

	for(i=0; i < x; ++i)
	{
		if(i % col == 0) { printf("\n"); }
		printf("%d", rand()%10);
	}
	printf("\n");

	return 0;
}
