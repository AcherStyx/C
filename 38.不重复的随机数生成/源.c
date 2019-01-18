#include <stdio.h>
#include <stdlib.h>

#define AMOUNT 100000

unsigned int irand(void);

int main(void)
{
	unsigned int i;
	unsigned int randb;
	unsigned int temp;
	unsigned int a[AMOUNT];

	for (i = 0; i < AMOUNT; i++)
		a[i] = i;


	for (i = 0; i < AMOUNT; i++)
	{
		randb = (irand() % AMOUNT);
		temp = a[i];
		a[i] = a[randb];
		a[randb] = temp;
	}
	
	for (i = 0; i < AMOUNT; i++)
	{
		printf("%u ", a[i]);
	}
	
	return 0;
}

unsigned int irand(void)
{
	static int seed = 1;
	seed = (seed + 1) * 41354678451 + 45;
	return (unsigned int)seed;
}