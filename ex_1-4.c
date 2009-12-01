#include <stdio.h>

main()
{
	float fahr, celsius;
	int lower, upper, step;

	lower = 0;
	upper = 300;
	step = 20;

	celsius = lower;

	while (celsius <= upper)
	{
		fahr = (celsius*1.8)+32;
		printf("%6.1f %6.1f\n", celsius, fahr);
		celsius = celsius + step;
	}
}
