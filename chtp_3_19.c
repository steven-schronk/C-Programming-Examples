#include <stdio.h>

int main()
{
	float principle;
	float rate;
	float days;
	float interest_paid;
	while(1)
	{
		printf("Enter loan principal (-1 to end):");
		scanf("%f", &principle);
		if(principle == -1) { break; }
		printf("Enter interest rate:");
		scanf("%f", &rate);
		printf("Enter term of loan in days:");
		scanf("%f", &days);
		interest_paid = principle * rate * days / 365;
		printf("The interest charge is $%f\n", interest_paid);
	}
	return 0;
}
