#include <stdio.h>
int sumf(int p[], int len);
int  main(void)
{
	int p[10] = { 1,1,1,2,2,2,1,1,1,5 };
	int sum;

	sum = sumf(p, 10);

	return 0;

}

int sumf(int p[], int len)
{
	int sum = 0;
	int count;

	for (count = 0; count < len; count++)
		sum += p[count];

	return sum;
}