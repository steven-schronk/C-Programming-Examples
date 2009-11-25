/*

maxline


function: discard newline
	for loop through buffer looking for terminator
		if current postion is newline, set position to terminator


function: reverse
	for find end of buffer as integer
	move back one space
	for loop reverse through string printing out chars one at a time



function: getline
	for get chars until buffer is full
	if last char is newline add to end of buffer
	terminate buffer with '\0'


function: main
	while getline > 0
		disgard new line
		reverse line
		print line



*/

#include <stdio.h>

#define MAXLEN 1024


/*

loop throguh buffer
convert newlines into nulls marking end of array

*/
int discard(char buffer[])
{
	int i;
	for(i = 0; buffer[i] != '\0'; i++) /* loop until we find NULL */
	{
		if(buffer[i] == '\n') { buffer[i] = '\0'; } /* convert newlines into NULL */
	}
}

/*

reverse

loop through buffer reversing chars

*/
int reverse(char buffer[])
{
	char ch;
	int i,j;
	for(j = 0; buffer[j] != '\0'; ++j) { } /* find length of buffer */
	--j; /* move back one space */

	/* loop though length of array reversing front to back chars */
	for(i = 0; i < j; i++)
	{
		ch = buffer[i];
		buffer[i] = buffer[j];
		buffer[j] = ch;
		--j;
	}
}

/*

getine

get input passed to program and store in buffer
check along the way that the input has not run out
do this until we reach a newline and then terminate with NULL

*/
int getline(char buffer[], int limit)
{
	int i;
	char c;
	for(i = 0; i < limit - 1 && (c = getchar()) != EOF && c != '\n';  ++i)
	{
		buffer[i] = c;
	}

	if(c == '\n') { buffer[i++] = c; }
	
	buffer[i] = '\0'; /* terminate string at this position */

	return i; /* return number of chars found in this line */
}

int main()
{
	char buffer[MAXLEN];

	while(getline(buffer, sizeof buffer) > 0)
	{
		// printf("getline\n");	
		discard(buffer);
		reverse(buffer);
		printf("%s\n", buffer);
	}
	return 0;
}
