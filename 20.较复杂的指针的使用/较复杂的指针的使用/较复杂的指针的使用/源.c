#include <stdio.h>
int main(void)
{
	int **po;
	int *(*pa[3]);
	int **paa[3];//int *(*pa[3]);��int **paa[3];Ч������ͬ��
	int pa1[2][3];
	int pa2[3][2];
	int *pa3[3];//ָ��ΪԪ�ص�����
	int *po2;
	int i=999;
	int (*poo1)[2];
	int (*poo2)[3];

	po2 = &i;
	po = &po2;

	poo1 = pa1;
	poo2 = pa1;

	printf("��ַ:\npa1:%p pa1+1:%p\n", pa1, pa1 + 1);
	printf("��ַ:\ni:%p *po2:%p *po:%p\n����:\n**po:%d", &i, po2, *po, **po);
	printf("��ַ:\npo:%p &po2:%p\n", po, &po2);
	printf("��ַ:\npoo1:%p poo1+1:%p\npoo2:%p poo2+1:%p\n", poo1, poo1 + 1, poo2, poo2 + 1);




	return 0;
}