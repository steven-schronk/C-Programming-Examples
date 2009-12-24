#include <stdio.h>

static char daytab[2][13] =
{
	{ 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 },
	{ 0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }
};

/* set day of year based on month and day */
int day_of_year(int year, int month, int day)
{
	int i, leap;

	if(year < 1752 || month > 12 || month < 1 || day < 1) { return -1; }

	leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
	if(day > daytab[leap][month]) { return -1; } // day month pair OK?

	for( i = 1; i < month; i++)
		day += daytab[leap][i];
	return day;
}

/* get month, day from day of year */
int month_day(int year, int yearday, int *pmonth, int *pday)
{
	int i, leap;

	if(year < 1752) { return -1; }

	leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
	if((leap && yearday > 366) || (!leap && yearday > 365)) { return -1; }

	for(i = 1; yearday > daytab[leap][i]; i++)
		yearday -= daytab[leap][i];
	*pmonth = i;
	*pday = yearday;
	return 1;
}

int main()
{
	int ans, month, day;
	ans = day_of_year(2009, 2, 1);
	printf("%d\n", ans);
	ans = month_day(2009, 34, &month, &day);

	if(ans)
		printf("Day: %d\tMonth:%d\n", day, month);

	int yearday, year = 2009;
	int leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;	

	for(month = 1; month <= 12; ++month)
	{
		printf("\n");
		day = 0;
		while(++day <= daytab[leap][month])
		{
			yearday = day_of_year(year, month, day);
			printf("Y: %d\tM: %d\tD: %d\t->\tYD:%d\n", year, month, day, yearday);
		}
		printf("\n");
	}	
	return 1;
}
