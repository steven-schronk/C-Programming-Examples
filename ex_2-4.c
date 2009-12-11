/*

Delete each char in string test that matches any char in string key.

*/

#include <stdio.h>

#define FALSE 0;
#define TRUE 1;

char key[] = "abc";
char test[] = "abc123";

int squeeze(char test[], char key[])
{
	int t,k,x;
	for(k = 0; test[k] != '\0'; k++)
	{
		x = TRUE;
		for(t = 0; key[t] != '\0'; t++)
		{	
			if(test[k] == key[t]){ x = FALSE; }
		}
		if(x == 1) { putchar(test[k]); }
	}
	printf("\n");
	return 0;
}

int main()
{
	squeeze(test, key);
	return 0;
}

