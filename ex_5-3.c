#include <stdio.h>
#include <string.h>

/* print contents of array */
void print_array(char s[])
{
        int i;
        for(i = 0; i < strlen(s); i++)
                printf("%c", s[i]);
        printf("\n");
}

/* previous version of strcat */
void strcat_old(char s[], char t[])
{
	int i, j;
	i = j = 0;
	while(s[i] != '\0')
		i++;
	while((s[i++] = t[j++]) != '\0')
		;
}

/* copy string of chars from t into s */
void strcopy(char *s, char *t)
{
	while(*s++ = *t++);
}

/* pointer version of strcat - add string t to end of string s */
void strcatptr(char *s, char *t)
{
	while(*s) { ++s; } // find pointer val for end of string s
	strcopy(s,t);
}

int main()
{
	char buffer[128];
	char s[] = { "this is a string of chars " };

	strcatptr(buffer,s);
	strcatptr(buffer,s);

	print_array(buffer);

	printf("\n");

	return 1;
}
