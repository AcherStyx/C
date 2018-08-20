#include <stdio.h>
#include <stdlib.h>
#define LEN_OF_PRIME_NUMBER 23249425
int main(void)
{
	int count;

	int *a;
	a = (int*)malloc(sizeof(int)*LEN_OF_PRIME_NUMBER);
	prime_number_array(a, LEN_OF_PRIME_NUMBER);
	
	for (count = 0; count < LEN_OF_PRIME_NUMBER; count++)
		printf("%d ", a[count]);
	return 0;
}

int prime_number_array(int *a, int len)
{
	int count = 2;
	int pcount;
	int ocount;
	int ok = 1;
	int check;
	for (ocount = 0; ocount < len; ok = 1)
	{
		for (pcount = 2; pcount < count; pcount++)
		{
			check = count % pcount;
			if (check == 0)
				ok = 0;
		}
		if (ok == 1)
		{
			a[ocount] = count;
			ocount++;
		}
		count++;
		while (count == 32768)
			return 0;
	}
	return 0;
}