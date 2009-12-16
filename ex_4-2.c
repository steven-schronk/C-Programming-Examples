#include <stdio.h>
#include <ctype.h>
/*

Add support for scientific notation.

123.45e-6
123.45E6
-123.45e56

*/

double atof(char s[])
{
	double val, power;
	int i, sign;
	for(i=0; isspace(s[i]); i++) /* skip spaces */
		;

	sign = (s[i] == '-') ? -1 : 1; // mark sign for number
	if(s[i] == '+' || s[i] == '-') // skip over signs
		i++;
	for(val = 0.0; isdigit(s[i]); i++)
		val = 10.0 * val + (s[i] - '0');
	if(s[i] == '.') // skip over decimals
		i++;

	for(power = 1.0; isdigit(s[i]); i++)
	{
		val = 10.0 * val + (s[i] - '0');
		power *= 10.0;
	}
	return sign * val / power;
}

int main()
{
	char s[] = "-10928473.25";
	double ans = atof(s);
	printf("%f\n", ans);
	return 0;
}
