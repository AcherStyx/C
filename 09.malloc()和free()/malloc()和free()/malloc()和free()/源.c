#include <stdio.h>
#define LEN 10
int main(void)
{
	char *a;
	int count;
	char *b;

	a = (char*)malloc(sizeof(char)*LEN);

	printf("%p\n", a);
	for (count = -10; count < (LEN+10); count++)
		printf("%2d ", a[count]);
	printf("\n");


	for (count = 0; count < (LEN); count++)
		a[count] = 1;

	printf("%p\n", a);
	for (count = -10; count < (LEN+10); count++)
		printf("%2d ", a[count]);
	printf("\n");

	b = a;

	free(a);
	
	printf("%p\n", b);
	for (count = -10; count < (LEN + 10); count++)
		printf("%2d ", b[count]);

	return 0;
}