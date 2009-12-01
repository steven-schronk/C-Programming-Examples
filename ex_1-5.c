#include <stdio.h>

#define LOWER 0
#define UPPER 300
#define STEP 20

main()
{
	int fahr;

	for(fahr = UPPER; fahr > LOWER; fahr = fahr - STEP)
		printf("%3d %61f\n", fahr, (5.0/9.0)*(fahr-32));
}
