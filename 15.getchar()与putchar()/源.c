#include <stdio.h>
int main(void)
{
	char a[100];
	int count;
	for (count = 0; count < 100; count++)
	{
		a[count] = getchar();
		if (a[count] == '\n')
			count = 10000;
	}
	for (count = 0; count < 100; count++)
	{
		putchar(a[count]);
		if (a[count] == '\n')
			count = 10000;
	}
	return 0;
}