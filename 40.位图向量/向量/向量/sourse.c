#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define AMOUNT 100
unsigned int a[AMOUNT / 4];
#define MASK (00000000000000000000000000000001)

unsigned int irand(void);

int main(void)
{
	srand(time(NULL));
	testdata();
	printf("=====================================================\n");

	unsigned int pic[AMOUNT / 32 + 1];
	int i;


	for (i = 0; i < AMOUNT / 32 + 1; i++)
		pic[i] = 0;

	//Â¼Èë
	for (i = 0; i < AMOUNT /4 ; i++)
	{
		pic[a[i] / 32] = pic[a[i] / 32] + (MASK << (a[i] % 32));
	}

	for (i = 0; i < AMOUNT; i++)
	{
		printf("%d:%d\n", i, (pic[i / 32] >> (i % 32)&MASK) == MASK);
	}

	return 0;
}

int testdata(void)
{
	unsigned int i;
	unsigned int ii;
	unsigned int randb;
	unsigned int temp;
	

	for (i = 0, ii = 0; ii < (AMOUNT / 4) && i < AMOUNT; i++)
	{
		if (irand() % 2 == 1)
		{
			a[ii] = i;
			ii++;
		}
	}

	for (i = 0; i < AMOUNT/4; i++)
	{
		randb = (irand() % (AMOUNT/4));
		temp = a[i];
		a[i] = a[randb];
		a[randb] = temp;
	}

	for (i = 0; i < AMOUNT/4; i++)
	{
		printf("%d:%u\n", i,a[i]);
	}

	return 0;
}

unsigned int irand(void)
{
	static int seed = 1;
	seed = (seed + 1) * 41354678451;
	return (unsigned int)seed;
}