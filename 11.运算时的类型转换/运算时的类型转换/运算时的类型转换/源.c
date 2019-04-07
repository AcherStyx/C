#include<stdio.h>
int main(void)
{
	int a;
	unsigned int b;
	unsigned int c;
	
	a = -1000;
	b = 100;
	c = a + b;
	
	printf("int a:%d", a);
	printf("\nunsigned int b:%u\n", b);
	printf("a+b=%d\n", a + b);
	printf("4/5*2=%f\n", 4 / 5 * 2);
	printf("4.0/5*2=%f", 4.0 / 5 * 2);

	return 0;
}