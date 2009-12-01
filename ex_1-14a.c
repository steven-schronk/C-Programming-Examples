#include <stdio.h>
#include <limits.h>

main()
{
       int c, i, j, nwhite, nother, maxnum;
        int ndigit[CHAR_MAX] = {0};

        maxnum = 0;
        nwhite = nother = 0;

        for(i = 0; i < 10; i++)
                ndigit[i] = 0;

        while ((c = getchar()) != EOF)
                if(c > CHAR_MAX) { /* chars outside CHAR_MAX skipped */ } else { ++ndigit[c]; }

        /* print out histogram */
        for(i = 0; i <= CHAR_MAX; ++i) // find maximim count to determine graph height
                if(ndigit[i] > maxnum) { maxnum = ndigit[i]; }

        for(i = 0; i < maxnum; ++i) // one row for each instance of number
        {
                printf("\n");
                printf("%d\t|", maxnum-i); // print sidebar
                for(j = 0; j <= CHAR_MAX; ++j) // one column for each number
                {
                        if(ndigit[j] > 0) // skip chars not represented in file
                                if(ndigit[j] >= maxnum-i) { putchar('*'); } else { putchar(' '); }
                }
        }

        /* print vertically ascii value of char printed */
        printf("\n\t ");
        for (i = 0; i <= CHAR_MAX; ++i) { if(ndigit[i] > 0) { printf("%d", i/100); } }
        printf("\n\t ");
        for (i = 0; i <= CHAR_MAX; ++i) { if(ndigit[i] > 0) { printf("%d", (i-(100*(i/100)))/10); } }
        printf("\n\t ");
        for (i = 0; i <= CHAR_MAX; ++i) { if(ndigit[i] > 0) { printf("%d",  i-(10*(i/10))); } }
        printf("\n");
}
