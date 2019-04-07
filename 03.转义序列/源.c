#include <stdio.h>
int main(void)
{
	int count;

	printf("警报:\\a\n");
	printf("\a");

	printf("退格:test\b\n");/*无效？只对打印机这样的设备有效*/

	printf("问号:? \?");/*没啥区别？*/



	int pause=0;
	while (pause != 1)
	{
		printf("\n1 to exit:\a");
		scanf("%d", &pause);
	}
	return 0;
}