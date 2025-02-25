#include <stdio.h>

/*

Sales tax is collected from buyers and remitted to the government.
A retailer must file a monthly sales tax report that lists the sales for the month and the
amount of sales tax collected, at both the county and state levels. Develop a program
that will input the total collections for a month, calculate the sales tax on the collec
tions,
and display the county and state taxes. Assume that states have a 4% sales tax,
and counties have a 5% sales tax. Here is a sample input/output dialog:


*/

int main()
{
	float tax_county = 0.05;
	float tax_state = 0.04;
	float tax_total = 0.0;
	float total_collections = 0.0;
	float total_county = 0.0;
	float total_state = 0.0;

	printf("Enter total amount collected (-1 to quit):  ");
	scanf("%f", &total_collections);

	if(total_collections == -1) { return 0; }

	printf("Enter name of month: ");

	total_county = total_collections * tax_county;
	total_state = total_collections * tax_state;
	tax_total = total_county + total_state;

	printf("Total Collections: ");
	scanf("%f", &total_collections);

	// printf("Sales :");
	// scanf("%f", &sales);

	printf("County Sales Tax: %f\n", total_county);
	printf("State Sales Tax: %f\n", total_state);
	printf("Total Sales Tax Collected:  %f\n", tax_total);
}
