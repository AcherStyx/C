#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "queue.h"


#define NDEBUG

int showmenue(void);
int idequal(Item a, Item b);
int nameequal(Item a, Item b);
bool getitem(Item * item);
void printitem(Item item);
void clear(void);
int pricecmp(Item a, Item b);

int main(void)
{
	Queue head;
	Item input;
	FILE *data;

	int mode = 1;
	int mode2;
	int index;

	int place;

	printf("超市商品管理系统\n");

	//初始化
	Queue_initializing(&head);
	data = fopen("queuedata", "rb");
	Queue_readfromfile(&head, data);
	fclose(data);

	do
	{
		mode = showmenue();

		putchar('\n');
		switch (mode)
		{
		case 1:
			Queue_showall(&head, printitem);
			//			printf("Done.\n");
			break;
		case 2:
			printf("通过哪一项寻找商品:\n1)商品ID  2)商品名称\n输入您的选择: ");
			scanf("%d", &mode2);

			switch (mode2)
			{
			case 1:
				printf("输入需要修改的商品ID(-1退出查找): \n");
				scanf("%s", input.id);

				if (strcmp(input.id, "-1") == 0)
					break;
				index = Queue_find(&head, input, idequal);
				if (index == -1)
				{
					printf("未找到该商品\n");
					break;
				}

				printf("输入新的商品信息: \n");
				getitem(&input);
				Queue_modify(&head, index, input);
				printf("修改商品信息成功!修改后的商品为: \n");
				Queue_showitem(&head, index, printitem);
				break;
			case 2:
				printf("输入需要修改的商品名称(-1退出查找): \n");
				scanf("%s", input.name);

				if (strcmp(input.id, "-1") == 0)
					break;

				index = Queue_find(&head, input, nameequal);

				if (index == -1)
				{
					printf("未找到该商品\n");
					break;
				}

				printf("输入新的商品信息: \n");
				getitem(&input);
				Queue_modify(&head, index, input);
				printf("修改商品信息成功!修改后的商品为: \n");
				Queue_showitem(&head, index, printitem);
				break;
			default:
				printf("错误的选项\n");
				break;
			}
			break;
		case 3:
			getitem(&input);
			printf("插入到的位置:");
			scanf("%d", &place);
			Queue_enqueue_B(&head, input, place);
			break;
		case 4:
			printf("输入要删除的商品名称(-1退出):");
			clear();
			if (NULL != fgets(input.name, NAME_LEN, stdin) || strlen(input.name) > 0)
				input.name[strlen(input.name) - 1] = '\0';

			if (strcmp(input.id, "-1") == 0)
				break;

			index = Queue_find(&head, input, nameequal);

			if (index == -1)
			{
				printf("未找到该商品\n");
				break;
			}

			Queue_delete(&head, index);
			printf("商品删除成功\n");

			break;
		case 5:
			printf("输入要查找的商品名称(-1退出):");
			clear();
			if (NULL != fgets(input.name, NAME_LEN, stdin) || strlen(input.name) > 0)
				input.name[strlen(input.name) - 1] = '\0';

			if (strcmp(input.id, "-1") == 0)
				break;

			index = Queue_find(&head, input, nameequal);

			if (index == -1)
			{
				printf("未找到该商品\n");
				break;
			}

			Queue_showitem(&head, index, printitem);

			break;
		case 6:
			data = fopen("queuedata", "wb");
			Queue_savetofile(&head, data);
			fclose(data);
			exit(0);
			break;
		case 7:
			Queue_sort(&head, pricecmp);
			break;
		case 8:
			Queue_clean(&head);
			printf("已清除所有商品信息\n");
		default:
			if (mode != 0)
			{
				//				printf("错误选项\n");

			}
			break;
		}
	} while (mode != 0);




	return 0;
}

//打印菜单
int showmenue(void)
{
	int mode;
show_again:
	printf("***********************************************************************\n");
	printf("1.显示所有商品的信息:\n");
	printf("2.修改某个商品的信息:\n");
	printf("3.插入某个商品的信息:\n");
	printf("4.删除某个商品的信息:\n");
	printf("5.查找某个商品的信息:\n");
	printf("6.商品存盘并退出系统:\n");
	printf("7.对商品价格进行排序:\n");
	printf("8.(慎用)删除所有内容:\n");
	printf("其他.不存盘并退出系统:\n");
	printf("***********************************************************************\n");
	printf("输入您的选择: ");
	if (0 == scanf("%d", &mode))
	{
		clear();
		goto show_again;
	}
	return mode;
}
//id相同
int idequal(Item a, Item b)
{
	return strcmp(a.id, b.id) == 0;
}
//name相同
int nameequal(Item a, Item b)
{
	return strcmp(a.name, b.name) == 0;
}
//录入项目
bool getitem(Item * item)
{
	int check = 0;
	printf("商品ID: ");
	check += scanf("%s", item->id);

	clear();
	printf("商品名称: ");
	check += (NULL!= fgets(item->name, NAME_LEN, stdin));
	if (strlen(item->name) > 0)
		item->name[strlen(item->name) - 1] = '\0';

	printf("商品价格: ");
	check += scanf("%d", &item->price);

	printf("商品折扣: ");
	check += scanf("%f", &item->discount);

	printf("商品数量: ");
	check += scanf("%d", &item->total);

	printf("商品剩余: ");
	check += scanf("%d", &item->rest);

	if (check == 6)
		return true;
	else
		return false;

	return false;//正常不会执行这句
}
//打印项目
void printitem(Item item)
{
	printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	printf("ID:%s   名称:%s  价格:%d  折扣:%.1f  数量:%d  剩余:%d\n", item.id, item.name, item.price, item.discount, item.total, item.rest);
	printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
}
//清空行
void clear(void)
{
	char in = '\0';
	while ((in = getchar()) != '\n')
		;
}
//排序
int pricecmp(Item a, Item b)
{
	if (a.price > b.price)
		return 1;
	else
		return 0;
}