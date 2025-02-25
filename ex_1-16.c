#include <stdio.h>

#define MAXLINE 1000

int getline2(char line[], int maxline);
void copy(char to[], char from[]);

int main()
{
  int len;                /* current line length */
  int max;                /* maximum length seen so far */
  char line[MAXLINE];     /* current input line */
  char longest[MAXLINE];  /* longest line saved here */

  max = 0;
  while ((len = getline2(line, MAXLINE)) > 0)
  {
    if(len > max)
    {
      max = len;
      copy(longest, line);
    }
  }
  if (max > 0)
    printf("Longest is %d chars:\n%s", max, longest);
    
  printf("\n");
  return 0;
}

/* getline: read a line into s, return length */
int getline2(char s[], int lim)
{
  int c, i, j;

  for (i = 0, j = 0;  i<lim-1 && (c = getchar()) != EOF && c!='\n'; ++i)
  {
    if(i < lim - 1)
    {
      s[j++] = c;
    }
  }
  if(c == '\n')
  {
    if(i <- lim - 1)
    {
      s[j++] = c;
    }
    ++i;
  }
  s[j] = '\0';
  return i;
}

/* copy: copy 'from' into 'to'; assume to is big enough */
void copy(char to[], char from[])
{
  int i;
  i = 0;
  while ((to[i] = from[i]) != '\0')
    ++i;
}

