#include <stdio.h>

/* get next group of tokens from stdin */
int get_tokens(int *dir, char *start, char *stop){

	int status = 0;
	char c = '\0';
	if((c = getchar()) != EOF) { ++status; } 

	if(c == '-') {
		*dir = 1;
		if((*start = getchar()) != EOF) { ++status; }
		if(getchar() != EOF) { ++status; } // should be a '-'
		if((*stop = getchar()) != EOF) { ++status; }
	} else {
		*dir = 0;
		*start = c;
		if(getchar() != EOF) { ++status; } // should be a '-'
		if((*stop = getchar()) != EOF) { ++status; }
	}

	if(status == 4 && *dir == 1) { return 1; }
	if(status == 3 && *dir == 0) { return 1; }
	return -1;
}

/*

print out series of chars based on spec.
dir = direction to print
start and stop are chars in ASCII to begin and end with.

*/
void print_tokens(int *dir, char *start, char *stop)
{
	if(*dir == 0){ // foreward
		while(*start != *stop + 1)
		{
			putchar(*start);
			*start = *start + 1;
		}
 	 } else { // reverse

		while(*start != *stop - 1)
		{
			putchar(*start);
			*start = *start - 1;
		}
	}
}

int main()
{
	char start, stop;
	int dir;

	while(get_tokens(&dir, &start, &stop) == 1)
	{
		print_tokens(&dir, &start, &stop);
		putchar('\n');
	}
	return 0;
}
