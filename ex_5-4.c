#include <stdio.h>

/* strcmp - compare strings */
/* return <0 is s < t; 0 if s==t; >0 if s>t */
int strcmp(char *s, char *t)
{
	int i;
	for(i = 0; s[i] == t[i]; i++)
		;

	return i; // might need to change
}


/* strlen - return length of string */
int strlen_new(char *s)
{
	int n;
	for(n =0; s[n] != '\0'; n++);
	return n;
}

/* strend - compares end of string s with string t */
/* return 1 if string t occurs and 0 otherwise */
int strend(char *s, char *t)
{
	int ls, lt;
	ls = strlen_new(s); // find length of s
	lt = strlen_new(t); // find length of t

	// start with end of s and move back comparing with end of t
	while(lt >= 0)
	{
		if(s[ls] != t[lt]) { return 0; }
		--ls;
		--lt;
	}
	return 1;
}


int main()
{
	char s[] = { "1234567890" };
	char t[] = { "67890" };

	int ans = strend(s,t);
	printf("%d\n", ans);

	return 1;
}
