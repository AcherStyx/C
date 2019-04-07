#include <stdio.h>
int main(void)
{
	float a = 54.265;
	printf("*%f*\n", a);
	printf("*%e*\n", a);
	printf("*%7e*\n", a);
	printf("*%010.1f*\n", a);
	printf("*%-10f*\n", a);
	printf("*%+10.2f*\n", a);
	printf("*% 10.2f*\n", a);
	return 0;
}