#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXLINES 5000   // max number of lines sorted
#define MAXLEN 1000     // maximum length of each line
#define ALLOCSIZE 10000 // size of available space

int readlines(char *lineprt[], int nlines);
void writelines(char *lineprt[], int nlines);
void new_qsort(void *lineptr[], int left, int right, int (*comp)(void *, void*));
int numcmp(char *, char *);
void swap(void *v[], int i, int j);
int getline(char s[], int lim);
char *alloc(int n);

char *lineptr[MAXLINES]; // pointers to next lines
static char allocbuf[ALLOCSIZE];
static char *allocp = allocbuf;

/*

Get chars ony by one from stdin.  Load them into array of chars within lim.

*/
int getline(char s[], int lim)
{
	int c, i;
	i = 0;
	while(--lim > 0 && (c = getchar()) != EOF && c != '\n')
		s[i++] = c;
	if(c == '\n')
		s[i++] = c;
	s[i] = '\0';
	return i;
}

void new_qsort(void *v[], int left, int right, int (*comp)(void *, void*))
{
	int i, last;
	void swap(void *v[], int, int);

	if(left >= right)
		return;
	swap(v, left, (left + right)/2);
	last = left;
	for(i = left+1; i <= right; i++)
		if((*comp)(v[i], v[left]) < 0)
			swap(v, ++last, i);
	swap(v, left, last);
	new_qsort(v, left, last-1, comp);
	new_qsort(v, last+1, right, comp);
}

void swap(void *v[], int i, int j)
{
	void *temp;
	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}

/*

Compare two strings numerically.

*/
int numcmp(char *s1, char *s2)
{
	double v1, v2;
	v1 = atof(s1);
	v2 = atof(s2);
	if(v1 < v2)
		return -1;
	else if (v1 > v2)
		return 1;
	else
		return 0;
}

/*

read input lines

Use getline to obtain data from stdin.

Put data into array of pointers to char, as long as number of lines less than maxlines.

*/
int readlines(char *lineprt[], int maxlines)
{
	int len, nlines;
	char *p, line[MAXLEN];
	
	nlines = 0;
	while((len = getline(line, MAXLEN)) > 0)
	{
		if(nlines >= maxlines || (p = alloc(len)) == NULL)
		{
			return -1;
		} else {
			line[len-1] = '\0'; // delete newline
			strcpy(p, line);
			lineptr[nlines++] = p;
		}
	}
	return nlines;
}

/*
write ouput lines to stdout

input is an array of pointers to char and the number of lines stored

ouput goes to stdout

*/
void writelines(char *lineptr[], int nlines)
{
	while(nlines-- > 0)
		printf("%s\n", *lineptr++);
}

char *alloc(int n)
{
	if(allocbuf + ALLOCSIZE - allocp >= n)
	{
		allocp += n;
		return allocp -n; // old pointer
	} else {
		return 0;
	}
}

/*

Sort lines in input numerically.

If -n switch entered, sort lines numerically.

Program is limited by buffers of both maximum number of lines and maximum length of lines.

*/
	
int main(int argc, char *argv[])
{
	int nlines;
	int numeric = 0;

	if(argc > 1 && strcmp(argv[1], "-n") == 0)
		numeric = 1;
	if((nlines = readlines(lineptr, MAXLINES)) >= 0)
	{
		new_qsort((void **) lineptr, 0, nlines-1, (int(*)(void *,void *))(numeric ? numcmp : strcmp));
		writelines(lineptr, nlines);
		return 0;
	} else {
		printf("Input: Too many lines to sort\n");
		return 1;
	}
	return 1;
}
