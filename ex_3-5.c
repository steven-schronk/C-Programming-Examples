#include <stdio.h>
#include <string.h>

int itob(int n, char s[], int b);
void reverse(char s[]);

void print_array(char s[])
{
	int i;
	for(i = 0; i < strlen(s); i++)
		printf("%c", s[i]);
	printf("\n");
}

//main displays same number from base of two to highest base
int main()
{

	int base, number = 16384;
	char ans[255] = { '\0' };
	for(base = 2; base < 62; ++base)
	{
		if(itob(number, ans, base))
		{
			printf("Number: %d\tBase: %d Ans: ", number, base);
			print_array(ans);
		}
	}
	return 0;
}

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

// reverse string created (it was created in reverse order)
void reverse(char s[])
{
	int temp, i, j;
	for(i = 0, j = strlen(s)-1; j > i; i++, j--)
	{
		temp = s[i];
		s[i] = s[j];
		s[j] = temp;
	}
}
