#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <time.h>
#include "Hash_list.h"

void printitem(Item in)
{
	printf("[%s:%d]\n", in.label, in.data);
}

int main(void)
{
	clock_t start, finish;
	double totaltime;
	
	char go_on = 'y';
	char se[100];
	int out = 0;
	Hashlist* list;
	list = Hashlist_Init(29999999);
	/*手动输入测试数据
	while (go_on != 'n')
	{
		char *temp;
		temp = malloc(sizeof(char) * 100);
		int data;
		printf("Label:");
		scanf("%s", temp);
		printf("Data:");
		scanf("%d", &data);
		Hashlist_Add(list, temp, data);
		while (getchar() != '\n');
		scanf("%c", &go_on);
	}
	*/
	Hashlist_Debug_Randomdata(list, 29999999);
	//Hashlist_PrintAll(list, printitem);
	while (1)
	{
		printf("输入要搜索的条目: ");
		scanf("%s", se);
		start = clock();
		Hashlist_Search(list, se, &out);
		finish = clock();
		totaltime = (double)(finish - start) / CLOCKS_PER_SEC;
		printf("检索结果: %d\n时间: %lf\n", out, totaltime);
	}
	return 0;
}

