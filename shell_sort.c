/*

Invented in 1959 by D. L. Shell

Sorts an array of integers

From Page 60 & 61.

*/

#include <stdio.h>

void shellsort(int v[], int n)
{
	int gap, i, j, temp;

	for(gap = n/2; gap > 0; gap /=2)
	{
		for(i = gap; i < n; i++)
		{
			for(j = i - gap; j >=0 && v[j]>v[j+gap]; j-=gap)
			{
				temp = v[j];
				v[j] = v[j+gap];
				v[j+gap] = temp;
			}
		}
	}
}

int main()
{
	int data[10] = { 9, 12, 54, 90, 0, 100, 65, 32, 54, 81};
	int i;

	for(i = 0; i < 10; ++i) { printf("%d\n", data[i]); }

	shellsort(data, 10);

	for(i = 0; i < 10; ++i) { printf("%d\n", data[i]); }

	return 0;
}
