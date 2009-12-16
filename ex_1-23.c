/*

store state

store previous char

only check when we are not in a quoted area
check current char for * or / if prev char is a / than we are in a comment

echo out prev char


*/

#include <stdio.h>

void advbuf(char buf[], char mrk[])
{
	buf[0] = buf[1];
	mrk[0] = mrk[1];

	//buf[1] = buf[2];
	//mrk[1] = mrk[2];

	/* if buffer has comment string, continue comment by default */
	/* similar to carrying in math :) */
}

int main()
{
	char buf[2], mrk[2] = { '\0' };

	/* mrk   c = comment  q = quote p = program */

	char strtyp = '\0'; /* store string type */
	int comment = 0;
	/* pre-load buffer */

	for(;;)
	{
		advbuf(buf, mrk);
		buf[1] = getchar(); // load new char at start of buffer
		if(buf[1] == EOF) { return 0; } /* exit when we get to end of input */

		mrk[1] = 'p';

		/* found new quote */
		if(buf[1] == '\'' || buf[1] == '"') /* found one of the quotes */
		{
			mrk[1] = 'q';
			strtyp = buf[1];
		}

		/* if quote is in effect, keep quoting until we find corresponding quote */
		if(strtyp == '\'' || strtyp == '"')
		{
			if(mrk[0] == 'q')
			{
				if(buf[1] == strtyp)
				{
					strtyp = '\0';
				}
				mrk[1] = 'q';
			}
		}

		if(mrk[1] == 'p' || mrk[1] == 'c')
		{

		/* look for start of comment */
		if(buf[1] == '*' || buf[1] == '/')
		{
			if(buf[0] == '/')
			{
				mrk[0] = 'c';
				mrk[1] = 'c';
				comment = 1;
			}
		}

		/* look for end of comment */
		if(comment == 1)
		{
			if(buf[1] == '/')
				if(buf[0] == '*' || buf[0] == '/')
				{
					mrk[0] = 'c';
					mrk[1] = 'c';
					comment = 0;
				}
			mrk[1] = 'c';
		}

		}
		//printf("%c%c", buf[0], buf[1]);
		//printf("->%c%c\n", mrk[0], mrk[1]);

		/* based on current state print output */
		if(mrk[0] == 'p' || mrk[0] == 'q') { putchar(buf[0]); }
	}

	printf("This is a comment in a quote /* comment here */ just ignore it.\n");

	return 0;
}
