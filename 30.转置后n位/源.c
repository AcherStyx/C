#include <stdio.h>
#include <stdlib.h>
typedef unsigned int typetob;
void itob(typetob input, char out[]);
void invert_end(typetob * input, int n);
int  main(void)
{
	typetob a = 256;
	char *output;
	

	while (scanf("%ud", &a))
	{
		output = (char*)malloc(sizeof(typetob) * 8 + 1);

		itob(a, output);

		for (int i = 0; i < (sizeof(typetob) * 8); i++)
		{
			if (i % 4 == 0 && i != 0)
				putchar(' ');
			printf("%c", output[i]);
		}
		putchar('\n');

		invert_end(&a, 10);
		itob(a, output);

		for (int i = 0; i < (sizeof(typetob) * 8); i++)
		{
			if (i % 4 == 0 && i != 0)
				putchar(' ');
			printf("%c", output[i]);
		}
		putchar('\n');

	}

	return 0;

}

void itob(typetob in, char out[])
{
	int i;
	for (i = 0; i < (sizeof(typetob) * 8); i++, in >>= 1)
	{
		out[sizeof(typetob) * 8 - 1 - i] = (01 & in) + '0';
	}
	out[sizeof(typetob) * 8] = '\0';
}

void invert_end(typetob * input, int n)
{
	typetob mask = 0;
	int i;
	for (i = 0; i < n; i++)
	{
		mask <<= 1;
		mask = mask | 01;
	}

	*input ^= mask;

}