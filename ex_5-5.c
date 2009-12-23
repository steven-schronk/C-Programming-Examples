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

/*

Appends n chars of src into the end of dest.

If null encountered before n, then copy null and no more.

If n is zero or negative, then function has not effect.

*/
char *ss_strncat(char *dest, const char *source, size_t n)
{
        while(*dest) { ++dest; } // find pointer val for end of string s
        while((--n >= 0) && (*dest++ = *source++) != '\0');
        return dest;
}

/*
       
Compares contents of string s1 with contents of s2.

If s1 < s2 returns < 0
If s1 == s2 returns 0
If s1 > s2 returns > 0

*/
int ss_strncmp(const char *s1, const char *s2, size_t n)
{

        while(--n >= 0 && *s1 != '\0' && *s2 != '\0')
        {

                if(*s1++ == *s2++) { continue; }
                if(*s1 > *s2)
                        return 1;
                else
                        return -1;
        }
        return 0;
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

        char info[] = { "Data To Append. " };
        char buffer[50] = { "Beginning of Buffer. " };
        int i;
        for(i = 0; i <= 2; ++i)
        {       
                strncat(buffer, info, strlen(info));
                print_array(buffer);
        }

        printf("\n");

        char smaller[] = { "12345" };
        char bigger[] = { "67890" };
        int size_ans;

        size_ans = ss_strncmp(smaller, bigger, 3);
        printf("%d\n", size_ans);

        size_ans = ss_strncmp(bigger, bigger, 3);
        printf("%d\n", size_ans);

        size_ans = ss_strncmp(bigger, smaller, 3);
        printf("%d\n", size_ans);

	return 1;
}
