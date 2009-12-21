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
void rev_array(char s[])
{
	int c, i, j;
	for(i = 0, j = strlen(s)-1; i < j; i++, j--)
	{
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
}

/* helper function - performs the recursion */
int rec_rev(char s[], int i, int j)
{
	char c;

	c = s[i];
	s[i] = s[j];
	s[j] = c;

	if(i < j)
	{
		i++;
		j--;
		rec_rev(s, i, j);
	}

	return 1;
}

/* reverse contents of array recursively in place */
void rev_array_rec(char s[])
{
	int i = 0;
	int j = strlen(s)-1;
	rec_rev(s, i, j);
}


int main()
{
	char s[10] = { "Reverse Me" };

	print_array(s);
	rev_array_rec(s);
	print_array(s);	
	return 1;
}
