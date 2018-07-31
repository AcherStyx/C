#include <stdio.h>
#include <math.h>
int main(void)
{
double pow( double base, double exp );

int count;
int n=6;

long double x=1;
long double h;
long double s;

h=pow(1-(x/2)*(x/2),0.5);
s=n*x*h*0.5;

for(count=1;count<100;count++)
{
	n=n*2;
	h=pow(1-(x/2)*(x/2),0.5);
	x=pow((x/2)*(x/2)+(1-h)*(1-h),0.5);
	
}

h=pow(1-(x/2)*(x/2),0.5);//keep upate to the n


printf("%2.19Lf",s);

return 0;

}