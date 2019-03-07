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
		"0.测试数据		（10个顺序自然数）\n"
		"1.打印全部		（遍历）\n"
		"2.插入			（下标-1插入到末尾）\n"
		"3.删除\n"
		"4.前驱			（按元素）\n"
		"5.后继\n"
		"6.取元素		（按下标）\n"
		"7.定位			（搜索）\n"
		"8.长度			（返回长度）\n"
		"9.判空			（空返回1）\n"
		"==========\n"
		">>>>>选择(q退出): "
	);
}
Element_Type getelem(void)
{
	Element_Type temp;
	printf("输入元素数据:");
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
	printf("输入索引:");
	scanf("%d", &temp);
	return temp;
}
void printindex(int index)
{
	printf("%d\n", index);
}
void feedback(int back)
{
	printf(">>>返回值: %d\n", back);
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