#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
typedef unsigned long long typetob;
void itob(typetob in, char out[])
{
	unsigned long long i = 0;
	while (in != 0)
	{
		out[i] = in % 2;
		in = (in - (in % 2)) / 2;
		i++;
	}
}


long long fpow(long long a, long long b)
{
	unsigned long long sum = 1;
	char bri[1000];
	for (unsigned long long i = 0; i < 1000; i++)
		bri[i] = 0;
	itob(b, bri);
	unsigned long long a_2 = a * a;
	unsigned long long temp = 1;
	for (unsigned long long i = 0; i < 10; i++)
	{
		if (bri[i]==1)
		{
			temp = 1;
			for (unsigned long long ii = 0; ii <= i; ii++)
			{
				temp = temp * a_2;
			}
			sum *= temp;
		}
	}
	return sum;
}

long long ipow(long long a, long long b)
{
	unsigned long long sum = 1;
	for (unsigned long long i = 0; i < b; i++)
		sum *= a;
	return sum;
}

int main(void)
{
	int a, b;
	clock_t start, finish;
	double totaltime;
	scanf("%d %d", &a, &b);

	printf("%lld\n",fpow(a, b));
	start = clock();
	for (int i = 0; i < 1000000; i++)
		fpow(a, b);
	finish = clock();
	totaltime = (double)(finish - start) * 1000.0 / CLOCKS_PER_SEC;
	printf("%lf\n",totaltime);

	printf("%lld\n", ipow(a, b));
	start = clock();
	for (int i = 0; i < 1000000; i++)
		ipow(a, b);
	finish = clock();
	totaltime = (double)(finish - start) * 1000.0 / CLOCKS_PER_SEC;
	printf("%lf\n", totaltime);

	return 0;
}
