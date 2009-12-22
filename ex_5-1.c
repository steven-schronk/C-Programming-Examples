#include <stdio.h>
#include <ctype.h>

#define BUFSIZE 100

char buf[BUFSIZE];
int bufp = 0;

/*

NOTE: getchar and ungetch work in tandem:

This allows the user to get a character from standard in, have a look at it
and then determine to use it or place it back into a buffer for later use.

If this buffer has any chars inside, thise will be poped off first 
before getting more input from stdin.

*/

int getch(void);
void ungetch(int);

/* reads from buffer if buffer contains chars or calls getchar otherwise */
int getch(void)
{	
	return (bufp > 0) ? buf[--bufp] : getchar();
}

/* places pushed-back characters into a char array shared buffer */
void ungetch(int c)
{
	if(bufp >= BUFSIZE)
		printf("ungetch: too many characters\n");
	else
		buf[bufp++] = c;
}

/* get next integer from input and put into *pn */
int getint(int *pn)
{
	int c, sign, signed_num;

	while(isspace(c = getch()))
		;
	if(!isdigit(c) && c != EOF && c != '+' && c != '-')
	{
		ungetch(c);
		return 0;
	}

	sign = (c == '-') ? -1 : 1;
	if((signed_num = (c == '+' || c == '-')))
		c = getch();
	if(!isdigit(c))
	{
		ungetch(c);
		if(signed_num)
			ungetch((sign == -1) ? '-' : '+');
		return 0;
	}

	for(*pn = 0; isdigit(c); c = getch())
		*pn = 10 * *pn + (c - '0');
	*pn *= sign;
	if(c != EOF)
		ungetch(c);
	return c;
}

int main()
{
	int n[5];
	int retval = '\0';

	retval = getint(n);

	printf("Retval: %c\n", retval);

	int i;
	for(i = 0; i < 5; i++)
	{
		printf("%d", n[i]);
	}
	

	printf("\n");

	return 1;
}
