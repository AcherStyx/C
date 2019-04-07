#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main(void)
{
	float a[2],b[2],len;
	int err;

	printf("Please input:\n");

	//Input
	printf("point 1(x,y):");
	scanf("(%f,%f)",a,a+1);   
	getchar();
	printf("point 2(x,y):");
	err=scanf("(%f,%f)",b,b+1);

	//Cal
	len=sqrtf((a[0]-b[0])*(a[0]-b[0])+(a[1]-b[1])*(a[1]-b[1]));

	//Print
	printf("The distance between points (%g,%g) and (%g,%g) is:%.4f\n",a[0],a[1],b[0],b[1],len);

	printf("%d",err);

	return 0;
}