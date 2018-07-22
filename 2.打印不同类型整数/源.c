#include <stdio.h>
int main(void)
{
	int tint=1234;
	long tl = 1234;
	long long tll = 1234;
	unsigned int tuint = 1234;
	short ts = 1234;
	unsigned short tus = 1234;
	unsigned long tul = 1234;
	unsigned long long tull = 1234;

	printf("用d打印：\nint:%d\nlong:%d\nlong long:%d\nshort:%d\n", tint, tl, tll, ts);
	
	printf("\n用ul打印unsigned long：\n%ul\n", tul);/*It's wrong*/
	printf("用lu打印unsigned long：\n%lu\n", tul);

	printf("\nshort:%hd\nunsigned short:%hu\n", ts, tus);/*short is %hu,not %h*/
	printf("\nint:%d\nunsigned int:%d\n", tint, tuint);
	printf("\nlong:%ld\nunsigned long:%lu\n", tl, tul);/*long is %ld,not %l*/
	printf("\nlong long:%lld\nunsigned long long:%llu\n", tll, tull);
	
	int pause = 0;
	while(pause!=1)
	{ 
		printf("\n1 to quit:");
		scanf("%d", &pause);
	}

	return 0;
}