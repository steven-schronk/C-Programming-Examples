#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define  DEFLINES 10
#define MAXLENGTH 1000

void error(const char *err)
{
        fprintf(stderr, "ERROR: %s\n", err);
        exit(EXIT_FAILURE);
}

int getline(char s[], int limit)
{
	int i, c;
	for(i = 0; i < limit - 1 && (c = getchar()) != EOF && c != '\n'; i++)
	{
		s[i] = c;
	}
		if(c == '\n'){ s[i++] = c; }
	s[i] = '\0';
	return i;
}

char *dupstr(const char *in)
{
	char *str = malloc(strlen(in)+1);
	if(str)
	{
		strcpy(str, in); 	
	}
	return str;
}

int main(int argc, char *argv[])
{
	int i, j, lines = DEFLINES;
	char **buff;
	char buffer[MAXLENGTH];
	if(argc > 1)
	{
		lines = atoi(argv[1]);
		lines = -lines; // input as negative - fixed that here
		if(lines < 1) { error("Incorrect Input"); }
	}
	buff = malloc(sizeof *buff * lines);
	if(!buff) { error("Could not allocate enough memory"); }
	for(i = 0; i < lines; i++)
	{
		buff[i] = NULL;
	}

	int current_line = 0;
	do {
		getline(buffer, sizeof buffer); // get line and store in buffer
		if(!feof(stdin))
		{
			if(buff[current_line])
				free(buff[current_line]);

			buff[current_line] = dupstr(buffer);
			if(!buff[current_line])
			{
				error("Out of Memory.");
			}
			current_line = (current_line + 1) % lines;
		}
	} while (!feof(stdin));
	for( i = 0; i < lines; i++)
	{
		j = (current_line + i) % lines;
		if(buff[j])
		{
			printf("%s", buff[j]);
			free(buff[j]);
		}
	}
	return EXIT_SUCCESS;
}
