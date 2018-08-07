#include <stdio.h>
int main(void)
{
	float up;
	float down;
	up = 99.9999e99;
	up = up;
	printf("上溢的输出结果:");
	printf("%f\n", up);

	down = 9e-6;
	printf("下溢的输出结果:%f %f %f", down, down / 10, down / 100);

	return 0;
}