#include <stdio.h>
#include <stdlib.h>
#define EXIT_FAILURE 1
int main(int argc, char *argv[])
{
	int i;
	int ch;
	FILE *fp;

	if (argc != 2)
	{
		printf("Error.\n");
		exit(EXIT_FAILURE);
	}

	fp = fopen(argv[1], "r");

	if (fp == NULL)
	{
		printf("Not a file.\n");
		exit(EXIT_FAILURE);
	}


	printf("File name:\n%s\n", argv[0]);
	printf("Content:\n");

	while ((ch = getc(fp)) != EOF)
	{
		putc(ch, stdout);
	}

	putchar('\n');

	return 0;
}