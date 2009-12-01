#include <stdio.h>

main()
{
	int c, i, j, nwhite, nother, maxnum;
	int ndigit[10];

	maxnum = 0;
	nwhite = nother = 0;
	for(i = 0; i < 10; i++)
		ndigit[i] = 0;

	while ((c = getchar()) != EOF)
		if(c >= '0' && c <= '9')
			++ndigit[c-'0'];
		else if (c == ' ' || c == '\n' || c == '\t')
			++nwhite;
		else
			++nother;

	/* print out histogram */
	
	for(i = 0; i <= 10; ++i)
	{
		if(ndigit[i] > maxnum) { maxnum = ndigit[i]; }
	}

	for(i = 0; i < maxnum; ++i) // one row for each instance of number
	{
		printf("%d\t|", maxnum-i); // print sidebar
		for(j = 0; j <= 10; ++j) // one column for each number
		{
			if(ndigit[j] >= maxnum-i) { putchar('*'); } else { putchar(' '); }
		}
		printf("\n");
	}

	printf("\t 0123456789\n");

}
