#include <stdio.h>

int main()
{
	float sales = 0.0;
	float salary = 200.0;
	float salary_total = 0.0;

	while(1)
	{
		printf("Enter sales in dollars (-1 to end): ");
		scanf("%f", &sales);
		if(sales == -1) { break; }
		salary_total = sales * 0.09 + salary;
		printf("Salary is: %f\n", salary_total);
	}
}
