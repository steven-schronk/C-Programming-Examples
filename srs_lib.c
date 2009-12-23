#include <stdio.h>
#include <string.h>

#include "srs_lib.h"

/* print contents of array */
void print_array(char s[])
{
        int i;
        for(i = 0; i < strlen(s); i++)
                printf("%c", s[i]);
        printf("\n");
}

/* print contents of array */
void print_sparse_array(char s[][MAXLEN])
{
        int i, j;
        for(i = 0; i < MAXLINES; i++)
        {
                int found = 0;
                for(j = 0; j < MAXLEN; j++)
                {
                        if(s[i][j] != '\0') { found++; }
                }
                if(found > 0)
                {
                        printf("%d:\t", i);
                        for(j = 0; j < MAXLEN; j++)
                                printf("%c", s[i][j]);
                        printf("\n");
                }
        }
        printf("\n");
}

/* reverse contents of array in place */
void reverse(char s[])
{
        int c, i, j;
        for(i = 0, j = strlen(s)-1; i < j; i++, j--)
        {
                c = s[i];
                s[i] = s[j];
                s[j] = c;
        }
}

/* convert integer to another base and store result in array of char */
int itob(int n, char s[], int b)
{
        int sign, i = 0;

        //create string of digits used to represent chars
        char base_chars[] = { "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ" };

        //check that base is neither too high nor too small
        if(b < 2)
        {
                printf("Base must be between 2 and %d.\n", (int)strlen(base_chars)-1);
                return -1;
        }

        if(b > strlen(base_chars)-1)
        {
                printf("Base must be %d or less.\n", (int)strlen(base_chars)-1);
                return -1;
        }

        // remove sign from number
        if(n < 0) { n = -n; sign = 1; }


        // increment s array and store in that location the modulus of the number -vs- the base
        // while number divided by base is larger than 0
        i = 0;
        do {
                s[i++] = base_chars[n % b];
        } while ((n /= b) > 0);

        // add sign from above
        if(sign == '1') { s[++i] = '-'; }
        s[i] = '\0';

        reverse(s);
        return 1;
}

