#include <stdio.h>
#include <string.h>

#define MAXLINES 1000  // max number of lines in buffer
#define MAXLEN 1000    // max length of individual lines

// declare lines as an array of array of char
// iow: create the maximum size empty buffer in global scope
char lines[MAXLINES][MAXLEN];

/* print contents of array */
void print_sparse_array(char s[][MAXLEN])
{
        int i, j;
        for(i = 0; i < MAXLINES; i++)
	{
		int found = 0;
		for(j = 0; j < MAXLEN; j++)
		{
			if(s[i][j] != '\0') { found++; }
		}
		if(found > 0)
		{
			printf("%d:\t", i);
			for(j = 0; j < MAXLEN; j++)
                		printf("%c", s[i][j]);
			printf("\n");
		}
	}
        printf("\n");
}

/* From K&R Page 29 */
int getline(char s[], int lim)
{
	int c, i;
	for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; i++)
		s[i] = c;                                                         
	if (c == '\n')
		s[i++] = c;   
	s[i] = '\0';
	return i;
}


/*

reads input lines from stdin and stores each line in buffer named lines

*/
int readlines(char lines[][MAXLEN], int maxlines)
{
	int len, nlines = 0;

	while((len = getline(lines[nlines], MAXLEN)) > 0)
		if(nlines >= maxlines) // when buffer full, return
			return -1;
		else
			lines[nlines++][len - 1] = '\0'; // delete newline
	return nlines;
}

int main()
{
	int length = readlines(lines, MAXLINES);
	printf("Number of Lines Stored: %d\n", length);
	print_sparse_array(lines);
	return 1;
}
