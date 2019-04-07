#include <stdio.h>
#define MIN 60
int main(void)
{
	int second = 0;
	int omin;
	int os;
	printf("Enter time in seconds(0 to quite):");
	scanf("%d", &second);
	while (second != 0)
	{
		omin = second / MIN;
		os = second % MIN;
		printf("The time is :%d min %d s\n", omin, os);
		printf("Enter time in seconds(0 to quite):");
		scanf("%d", &second);
	}
	return 0;
}