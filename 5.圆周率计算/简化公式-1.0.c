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

for(count=1;count<20;count++)
{
	h=pow(1-(x/2)*(x/2),0.5);
	x=pow((x/2)*(x/2)+(1-h)*(1-h),0.5);
	n=n*2;
}

h=pow(1-(x/2)*(x/2),0.5);//keep upate to the n
s=n*x*h*0.5;//S计算方法需要改进，重复次数多后会因为精度问题，S值出现误差

printf("%2.19Lf",s);

return 0;

}
