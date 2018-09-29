#include <stdio.h>
int which(int);
int main(void)
{
	int getdate = -1;
	int date[3];
	int days;

	while (getdate < 0)
	{
		printf("输入年份(Year/Month/date):");
		getdate = scanf("%d/%d/%d", date, date + 1, date + 2);
		getchar();
	}

	const int day[2][12] = {
	{31,28,31,30,31,30,31,31,30,31,30,31},
	{31,29,31,30,31,30,31,31,30,31,30,31},
	};

	int ifbig;
	int count;

	ifbig = which(date[0]);

	days = 0;
	for (count = 1; count < date[1]; count++)
		days += day[ifbig][count - 1];

	days += date[2];

	printf("这天是这一年的第 %d 天", days);


	return 0;
}

int which(int year)
{
	return (year % 4) == 0 ? 1 : 0;
}