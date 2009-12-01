#include <stdio.h>

int temp_conv(int c);

main()
{

	int i;

	for(i = 0 ; i < 300; ++i)
		printf("%d -> %d\n", i, temp_conv(i));
	return 0;
}

int temp_conv(int c)
{
	int answer = 5 * (c-32) / 9;
	return answer;
}
