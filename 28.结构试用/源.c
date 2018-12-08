#include <stdio.h>
#include <stdlib.h>
struct book
{
	char name[10];
	int price;
};
int main(void)
{
	struct book ex = {
		"Deep",
		23
	};

	printf("Name:%s\n", ex.name);
	printf("Price:%d\n", ex.price);

	return 0;
}