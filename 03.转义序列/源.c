#include <stdio.h>
int main(void)
{
	int count;

	printf("����:\\a\n");
	printf("\a");

	printf("�˸�:test\b\n");/*��Ч��ֻ�Դ�ӡ���������豸��Ч*/

	printf("�ʺ�:? \?");/*ûɶ����*/



	int pause=0;
	while (pause != 1)
	{
		printf("\n1 to exit:\a");
		scanf("%d", &pause);
	}
	return 0;
}