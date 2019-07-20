#include <stdio.h>
int max_index(float*, int);
int main(void)
{
	float a[10] = { 10.2f,1.2f,4578.4f,10.5f,4553435.1f,1.1f };
	
	printf("index:%d", max_index(a, 10));

	return 0;
}

int max_index(float a[], int len)
{
	int count;
	float max = a[0];
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