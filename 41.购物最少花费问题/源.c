#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
int main(void)
{
	int *price;
	int i, ii, iii;
	int min;

	int data[3][2] = { {2,2} , {50,30} , {30,27} };
	int n = 57;
	int dim[3];
	int dim_t;

	for (dim_t = 1, i = 0; i < 3; i++)
	{
		dim[i] = n / data[i][0] + 1;
		if (!n%data[i][0] == 0)
			dim[i]++;
		dim_t *= dim[i];
	}

	price = (int*)malloc(sizeof(int)*dim_t);

	for (iii = 0; iii < dim[2]; iii++)
	{
		for (ii = 0; ii < dim[1]; ii++)
		{
			for (i = 0; i < dim[0]; i++)
			{
				if (i*data[0][0] + ii * data[1][0] + iii * data[2][0] < n)
					price[iii*dim[1] * dim[0] + ii * dim[0] + i] = -1;
				else
					price[iii*dim[1] * dim[0] + ii * dim[0] + i] = i * data[0][1] + ii * data[1][1] + iii * data[2][1];
				printf("%d ", price[iii*dim[1] * dim[0] + ii * dim[0] + i]);
			}
		}
	}
	putchar('\n');

	min = 99999;
	for (i = 0; i < dim_t; i++)
	{
		printf("%d ", price[i]);
		if (price[i] == -1)
			continue;
		if (price[i] < min)
			min = price[i];
	}

	printf("\n×îÓÅ½â: %d", min);

	return 0;
}

