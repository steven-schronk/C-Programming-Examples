#include <stdio.h>

/* finds las occurence of char t in string s */
int strindex(char s[], char t)
{
	int i;
	for(i = strlen(s)-1; i > 0; i--)
	{
		if(s[i] == t) { return i; }
	}
	return -1;
}

int main()
{
	char s[] = "sdgtwerlsjkadsfs";
	char t = 's';
	int pos = 0;
	pos = strindex(s,t);
	printf("POS Found: %d\n", pos);
	return 0;
}
