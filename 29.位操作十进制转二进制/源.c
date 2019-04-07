#include <stdio.h>
#include <stdlib.h>
typedef unsigned int typetob;
void itob(typetob input, char out[]);
int  main(void)
{
	unsigned int a = 256;
	char *output;


	while (scanf("%ud", &a))
	{
		output = (char*)malloc(sizeof(typetob) * 8 + 1);

		itob(a, output);

		for (int i = 0; i < (sizeof(typetob) * 8); i++)
		{
			if (i % 4 == 4)
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