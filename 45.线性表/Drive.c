#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define Element_Type int

#include "SeqList.h"

bool compare(Element_Type a, Element_Type b)
{
	if (a == b)
		return 0;
	else
		return 1;
}
void showmenue(void)
{
	printf(
		"==========\n"
		"0.��������		��10��˳����Ȼ����\n"
		"1.��ӡȫ��		��������\n"
		"2.����			���±�-1���뵽ĩβ��\n"
		"3.ɾ��\n"
		"4.ǰ��			����Ԫ�أ�\n"
		"5.���\n"
		"6.ȡԪ��		�����±꣩\n"
		"7.��λ			��������\n"
		"8.����			�����س��ȣ�\n"
		"9.�п�			���շ���1��\n"
		"==========\n"
		">>>>>ѡ��(q�˳�): "
	);
}
Element_Type getelem(void)
{
	Element_Type temp;
	printf("����Ԫ������:");
	scanf("%d", &temp);
	return temp;
}
bool printelem(Element_Type in)
{
	printf("%d\n", in);
	return 1;
}
int getindex(void)
{
	int temp;
	printf("��������:");
	scanf("%d", &temp);
	return temp;
}
void printindex(int index)
{
	printf("%d\n", index);
}
void feedback(int back)
{
	printf(">>>����ֵ: %d\n", back);
}
void initdata(List head)
{
	static int i = 0;
	int mark = i + 10;
	for (; i < mark; i++)
		List_Insert(head, i, -1);
}
#define LEN 1000

int main(void)
{
	int mode;
	List head;
	Element_Type temp, temp2;
	int index;

	List_Init(&head, LEN);
	do
	{
		printf("==========""==========""==========""==========""==========\n");
		showmenue();
		if (!scanf("%d", &mode))
			break;

		switch (mode)
		{
		case 0:
			initdata(head);
			break;
		case 1:
			feedback(List_Traverse(head, printelem));
			break;
		case 2:
			temp = getelem();
			index = getindex();
			feedback(List_Insert(head, temp, index));
			break;
		case 3:
			temp = getelem();
			feedback(List_Delete(head, temp, compare));
			break;
		case 4:
			temp = getelem();
			feedback(List_Prior(head, temp, &temp2, compare));
			printelem(temp2);
			break;
		case 5:
			temp = getelem();
			feedback(List_Next(head, temp, &temp2, compare));
			printelem(temp2);
			break;
		case 6:
			index = getindex();
			feedback(List_Get(head, index, &temp));
			printelem(temp);
			break;
		case 7:
			temp = getelem();
			index=List_Locate(head, temp, compare);
			printindex(index);
			break;
		case 8:
			feedback(List_Length(head));
			break;
		case 9:
			feedback(List_IsEmpty(head));
			break;

		}
	} while (mode !='q');

}