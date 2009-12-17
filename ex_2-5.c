/*

Returns first location of in data string where any character from test string occurs or -1 if none found.

*/

#include <stdio.h>

int any(char test[], char data[])
{
	int i,j;

	for(i = 0; data[i] != '\0'; i++)
	{
		j=0;
		
		while(test[j] != '\0')
		{
			if(test[j] == data[i]) { return i; } else { j++; }
		}
	}
	return -1;
}

char test[] = "ax";
char data[] = "123bcx";

int main()
{
	int ans = any(test, data);
	printf("%d\n", ans);
	return 0;
}
