#include <stdio.h>
int max_index(double*, int);
int min_index(double a[], int len);
double diff(double *a, int len);
int main(void)
{
	double a[10] = { 10.2,1.2,4578.4,10.5,455335.1,1.1 };

	printf("diff:%lf", diff(a, 10));

	return 0;
}

int max_index(double a[], int len)
{
	int count;
	double max = a[0];
	int max_index = 0;

	for (count = 1; count < len; count++)
	{
		if (max < a[count])
		{
			max = a[count];
			max_index = count;
		}
	}

	return max_index;
}

int min_index(double a[], int len)
{
	int count;
	double max = a[0];
	int max_index = 0;

	for (count = 1; count < len; count++)
	{
		if (max > a[count])
		{
			max = a[count];
			max_index = count;
		}
	}

	return max_index;
}

double diff(double *a, int len)
{
	return a[max_index(a, len)] - a[min_index(a, len)];
}
