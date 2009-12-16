#include <stdio.h>
#include <ctype.h>

/*

Converts string of char into a double.
Supports scientific notation, signed exponents.

Warning: very large or small numbers exibit rounding errors.

*/

double atof(char s[])
{
	long double val, power, expower;
	int i, sign, exsign;
	for(i=0; isspace(s[i]); i++) // skip spaces
		;

	sign = (s[i] == '-') ? -1 : 1; // mark sign for number
	while(!isdigit(s[i])) // skip over signs and non numbers, dollar signs
		i++;

	val = 0.0;
	while(isdigit(s[i])) // calc val of nums before decimal
	{
		val = 10.0 * val + (s[i] - '0');
		i++;
	}

	if(s[i] == '.') // skip over decimals
		i++;

	power = 1.0;
	while(isdigit(s[i])) // calc val of nums after decimal
	{
		val = 10.0 * val + (s[i] - '0');
		power *= 10.0;
		i++;
	}

	val = sign * val / power;

	// check for exponent
	if(s[i] == 'e' || s[i] == 'E')
	{
		++i; // move past e or E
		exsign = (s[i] == '-') ? -1 : 1; // mark sign for number
		while(!isdigit(s[i])) // skip over sign(s)
			i++;

		expower = 0.0;	
		while(isdigit(s[i]))
		{
			expower = 10.0 * expower + (s[i] - '0');
			++i;
		}
	}

	/* cannot get pow() to work in math.h ... improvising :) */
	if(exsign == 1)
	{
		while(expower > 0) { val = val * 10; --expower; }
	} else {
		while(expower > 0) { val = val / 10; --expower; }
	}
	return val;
}

int main()
{
	char s[] = "-123.456e-7";
	double ans = atof(s);
	printf("%f\n", ans);

	char r[] = "123.45e-6";
	ans = atof(r);
	printf("%f\n", ans);

	char t[] = "123.45E6";
	ans = atof(t);
	printf("%f\n", ans);

	char u[] = "-123.45e56";
	ans = atof(u);
	printf("%f\n", ans);
	return 0;
}
