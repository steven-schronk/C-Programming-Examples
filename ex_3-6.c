#include <stdio.h>

void print_array(char s[])
{
	int i;
	for(i = 0; i <= strlen(s)-1; i++)
	{
		putchar(s[i]);
	}
}

/* reverse chars in array */
void reverse(char s[])
{
	int c,i,j;
	for(i = 0, j = strlen(s)-1; i < j; i++, j--)
	{
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
}

/* convert ingteger into a string of chars */
void itoa(int n, char s[])
{
	int i, sign;
	if((sign = n)< 0)
		n = -n;
	i = 0;
	do {
		s[i++] = n % 10 + '0';
	} while ((n /= 10 ) > 0 );
	if(sign < 0)
		s[i++] = '-';
	s[i] = '\0';
	reverse(s);
}

int main()
{
	int n = 123422;
	char s[100];

	itoa(n, s);
	print_array(s);
	return 0;
}
