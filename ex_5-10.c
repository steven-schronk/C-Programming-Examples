#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#define STACKSIZE 100

double stack[STACKSIZE];
int stkh = 0;
 
void error(const char *err)
{
	fprintf(stderr, "ERROR: %s\n", err);
	exit(EXIT_FAILURE);
}

void push(double val)
{
	if(stkh == STACKSIZE)
		error("Stack Overflow.");
	stack[stkh] = val;
	++stkh;
}

double pop()
{
	if(stkh == 0)
		error("Stack Empty.");
	return stack[--stkh]; 
}

int main(int argc, char *argv[])
{
	int i = 0;
	for(i = 1; i < argc; ++i)
	{
		switch(argv[i][0])
		{
			case '\0':
				error("No Arguments Sent.");
				break;
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':
			case '0':
				push(atof(argv[i]));
				break;
			case '+':
				push(pop()+pop());
				break;
			case 'x':
				push(pop()*pop());
				break;
			default:
				error("Unknown Operand.");
				break;
		}
	}
	printf("%f\n", pop());
	return 1;
}
