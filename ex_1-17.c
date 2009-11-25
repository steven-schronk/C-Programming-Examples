/*

function: readbuffer
	read chars from input until newline is found or buffer is full
	return if buffer overflowed while filling


function printline
	print buffer passed in
	keep printing input until newline is found


main

	buffer
	status
	while status not changed
		readbuffer
	
	if status changes
		print buffer
		print rest of line until newline
*/

#include <stdio.h>

#define MAX 81

int readbuffer(char *buffer)
{
	int i = 0;
	char c;

	while(i < MAX)
	{
		c = getchar();	
		if (c == EOF) { return -1; }
		if(c == '\n') { return 0; }
		buffer[i++] = c;
	}
	return 1;
}

int printline(char *buffer)
{
	int endfound = 1;
	char c, i;
	for(i = 0; i < MAX; ++i)
		putchar(buffer[i]);

	while(endfound == 1)
	{
		c = getchar();
		if (c == EOF) { endfound = -1; }
		else if (c == '\n' ) { endfound = 0; }
		else { putchar(c); }
	}
	putchar('\n');
	return endfound;
}

int main(void)
{
	char buffer[MAX];
	int status = 0;

	while (status != -1)
	{
		status = readbuffer(buffer);
		if(status == 1)
			status = printline(buffer);
	}
	return 0;
}
