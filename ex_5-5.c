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

/*

Copy at most n chars of string source into string dest.
Pad with '\0' if source has fewer chars than dest.

*/
char *ss_strncpy(char *dest, const char *source, int n)
{
	char *d = dest;
	if(n >= 0 || n == '\0')
	{
		while(--n >= 0 && (*dest++ = *source++) != '\0')
			continue;
		while(--n > 0)
			*dest++ = '\0';
	}

	return d;
}

int main()
{
	char source[] = { "Destination after..." };
	char dest[] = { "This is the destination before..." };

	print_array(dest);
	
	char *ans;

	ans = strncpy(dest, source, 20);

	printf("%p\n", ans);
	print_array(dest);

	printf("\n\n");

	char source2[] = { "Destination after..." };
	char dest2[] = { "This is the destination before..." };

	print_array(dest2);

	ss_strncpy(dest2, source2, 20);

	printf("%p\n", ans);
	print_array(dest2);
	return 1;
}
