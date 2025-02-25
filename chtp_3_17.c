#include <stdio.h>

int main()
{
	float mortgage_amount;
	float mortgage_term;
	float interest_rate;
	float monthly_payment;

	while(1)
	{
		printf("Enter mortgage amount in dollars:");
		scanf("%f", &mortgage_amount);

		printf("Enter mortgage term (in years):");
		scanf("%f", &mortgage_term);

		printf("Enter Interest rate:");
		scanf("%f", &interest_rate);

		monthly_payment = mortgage_amount / mortgage_term;

		printf("The Monthly Payable Interest is: %f\n", monthly_payment);
	}

	return 0;
}
