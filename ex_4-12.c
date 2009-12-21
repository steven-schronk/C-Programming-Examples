#include <string.h>
#include <stdio.h>

/* print contents of array */
void print_array(char s[])
{
        int i;
        for(i = 0; i < strlen(s); i++)
                printf("%c", s[i]);
        printf("\n");
}

/* reverse contents of array in place */
void reverse_array(char s[])
{
	int c, i, j;
	for(i = 0, j = strlen(s)-1; i < j; i++, j--)
	{
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
}

/* convert int n into chars in s[] - page 64*/
void itoa(int n, char s[])
{
	int i, sign;

	if((sign = n) < 0) 	// record sign
		n = -n;		// reverse sign
	i = 0;
	do {				// generates digits in reverse order
		s[i++] = n % 10 + '0';	// get next digit and load into array
	} while ((n /= 10) > 0);	// delete each digit as we move along
	if(sign < 0)
		s[i++] = '-';
	s[i] = '\0';
	reverse_array(s);
}

/* recursive version of itoa - book has not covered pointers yet :( */
int itoa_rec(int n, char s[], int i)
{
	if(n < 0)
	{
		s[i++] = '-';
		n = -n;
	}
	if(n / 10)
		i = itoa_rec(n/10, s,i);

	s[i++] = (n % 10 + '0');
	s[i] = '\0';
	return i;
}

int main()
{
	char s[10]; // must have plenty of space here...
	int n = -1024;

	itoa(n, s);
	print_array(s);

	itoa_rec(n, s, 0);
	print_array(s);	
	return 1;
}
