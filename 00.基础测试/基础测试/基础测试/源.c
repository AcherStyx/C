#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
int floatcmp(const float * a, const float *b);
int main(void)
{
	srand(time(NULL));
	float a[100];

	for (int i = 0; i < 100; i++)
		a[i] = ((float)rand()) / rand();

	for (int i = 0; i < 100; i++)
	{
		printf("%10.3f ", a[i]);
		if ((i + 1) % 10 == 0)
			putchar('\n');
	}

	putchar('\n');
	qsort(a, 100, sizeof(float), floatcmp);

	for (int i = 0; i < 100; i++)
	{
		printf("%10.3f ", a[i]);
		if ((i + 1) % 10 == 0)
			putchar('\n');
	}

	return 0;
}


int floatcmp(const float * a, const float *b)
{
	if (*a == *b)
		return 0;
	return *a > *b ? 1 : -1;
}