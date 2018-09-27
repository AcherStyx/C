#include <stdio.h>
#include <math.h>
float triS(float a,float b,float c);
int main(void)
{
	float a;
	float b;
	float c;

	scanf("%f %f %f",&a,&b,&c);

	printf("%f",triS(a,b,c));

	return 0;
}

float triS(float a,float b,float c)
{
	float s;
	float area;

	s=(a+b+c)/2;

	area=sqrtf(s*(s-a)*(s-b)*(s-c));

	return area;
}