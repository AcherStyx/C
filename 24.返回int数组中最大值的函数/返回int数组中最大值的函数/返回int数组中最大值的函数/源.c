#include <stdio.h>
int max(int *, int);
int main(void)
{
	int in[10] = { 10,11,15,12,4,16 };
	int back;
	
	printf("max:%d", max(in, 10));

	return 0;
}

int max(int *a, int len)
{
	int count;
	int max;
	max = a[0];
	for (count = 1; count < len; count++)
	{
		max = max < a[count] ? a[count] : max;
	}

	return max;
}