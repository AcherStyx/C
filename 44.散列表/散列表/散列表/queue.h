#ifndef _QUEUE_H_
#	define _QUEUE_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <iso646.h>
#include <assert.h>

#define NDEBUG
#define ID_LEN 50
#define NAME_LEN 50

//节点数上限，去掉定义可以任意添加
//#define ITEMMAX 1000

#define None (Item){NULL,-1}
/*=======================================类型定义=======================================*/
typedef struct item
{
	In_type label;
	Out_type data;
} Item;//Item储存数据
typedef struct node
{
	Item item;
	struct node * next;
} Node;
typedef struct queue
{
	Node *first;
	Node *last;
	int items;
} Queue;
/*=========================================接口=========================================*/
//初始化
void Queue_initializing(Queue * queue);
//队列空
bool Queue_isempty(const Queue * queue);
//队列满
bool Queue_isfull(const Queue * queue);
//队列项数
int Queue_items(const Queue *queue);
//添加项_A 到末尾
bool Queue_enqueue_A(Queue * queue, const Item item);
//添加项_B 到指定位置 0结尾 1开头/合理的n表示加为第n项，之后的后移
bool Queue_enqueue_B(Queue * queue, const Item item, int place);
//提出项
bool Queue_dequeue(Queue * queue, Item * item);
//清空队列
bool Queue_clean(Queue * queue);
//打印整个队列
bool Queue_showall(const Queue *queue, void(*showitem)(Item));
//打印Item到文件
bool Queue_savetofile(const Queue * queue, FILE *file);
//从文件读入Item，加到队列末尾
bool Queue_readfromfile(Queue * queue, FILE *file);
//队列全排序
void Queue_sort(Queue * queue, int(*compare)(Item a, Item b));
//修改第n项的Item为输入的Item
bool Queue_modify(Queue * queue, int index, Item item);
//搜索项目,找到时返回index,没找到返回-1,第二个参数为函数指针，该函数需要在Item符合相同的条件时返回1
int Queue_find(const Queue * queue, Item item, int(*isequal)(Item a, Item b));
//打印第n项
bool Queue_showitem(Queue *queue, int index, void(*showitem)(Item item));
//删除节点
bool Queue_delete(Queue *queue, int index);
//跳转到某一节点处
static Node *Queue_movetoindex(Queue *queue, int index);
/*=========================================实现=========================================*/
//初始化
void Queue_initializing(Queue * queue)
{
	queue->first = NULL;
	queue->last = NULL;
	queue->items = 0;
}
//队列空
bool Queue_isempty(const Queue * queue)
{
	if (queue->items == 0)
		return 1;
	else
		return 0;
}
//队列满
bool Queue_isfull(const Queue * queue)
{
#ifndef ITEMMAX
	return 0;
#else
	if (queue->items == ITEMMAX)
		return 1;
	else
		return 0;
#endif
}
//队列项数
int Queue_items(const Queue *queue)
{
	return queue->items;
}
//添加项_A 到末尾
bool Queue_enqueue_A(Queue * queue, const Item item)
{
	Node *temp;

	temp = (Node *)malloc(sizeof(Node));
	if (temp == NULL)
	{
		fprintf(stderr, "NULL\n");
		assert(0);
		return false;
	}

	temp->item = item;
	temp->next = NULL;

	if (Queue_isfull(queue))
	{
		fprintf(stderr, "FULL\n");
		assert(0);
		return false;
	}

	if (Queue_isempty(queue))
	{
		queue->first = temp;
	}
	else
	{
		queue->last->next = temp;
	}

	queue->last = temp;
	queue->items++;

	return true;
}
//添加项_B 到指定位置 0结尾 1开头/合理的n表示加为第n项，之后的后移
bool Queue_enqueue_B(Queue * queue, const Item item, int place)
{
	Node *temp;
	Node *current;//在寻找第n项时作为标志
	int i;

	//队列已满
	if (Queue_isfull(queue))
	{
		fprintf(stderr, "FULL\n");
		assert(0);
		return false;
	}
	//滤除错误位置输入
	if (place < 0 || place >(Queue_items(queue) + 1))
	{
		fprintf(stderr, "Overpass\n");
		assert(0);
		return false;
	}

	//当队列中有n项，而要求插入到n+1项时，把它插入到最后一项
	if (place == (Queue_items(queue) + 1))
		place = 0;

	//分配内存
	temp = (Node *)malloc(sizeof(Node));
	if (temp == NULL)
	{
		fprintf(stderr, "NULL\n");
		assert(0);
		return false;
	}
	//给结构赋值
	temp->item = item;
	//分支选择
	switch (place)
	{
		//添加到末尾
	case 0:
		//结尾项初始化
		temp->next = NULL;

		if (Queue_isempty(queue))
		{
			queue->first = temp;
		}
		else
		{
			queue->last->next = temp;
		}

		queue->last = temp;

		break;
		//添加到开头
	case 1:
		temp->next = queue->first;
		queue->first = temp;
		break;
		//添加到第n项
	default:
		current = queue->first;
		/*current指向首项，刚开始时，通过current只能设置第2项节点*/
		for (i = 2; i < place; i++)
			current = current->next;

		temp->next = current->next;
		current->next = temp;

		break;
	}

	queue->items++;

	return true;
}
//提出项
bool Queue_dequeue(Queue * queue, Item * item)
{
	Node * temp;//临时储存第一个节点的地址

	if (Queue_isempty(queue))
	{
		fprintf(stderr, "Empty\n");
		assert(0);
		return false;
	}

	*item = queue->first->item;

	temp = queue->first;
	queue->first = queue->first->next;

	free(temp);

	queue->items--;

	return true;
}
//清空队列
bool Queue_clean(Queue * queue)
{
	Node * next;

	while (queue->items > 0)
	{
		next = queue->first;
		queue->first = queue->first->next;

		free(next);

		queue->items--;
	}
	queue->last = NULL;

	if (queue->items != 0)
	{
		fprintf(stderr, "Not match.\n");
		assert(0);
		return false;
	}

	return true;
}
//打印整个队列
bool Queue_showall(const Queue *queue, void(*showitem)(Item))
{
	Node *current = queue->first;
	int i = 0;

	while (current != NULL)
	{
		i++;
		//printf("NUM. %d\n", i);
		showitem(current->item);
		putchar('\n');

		current = current->next;
	}

	if (i != queue->items)
	{
		fprintf(stderr, "Not match\n");
		assert(0);
		return false;
	}
	else
		return true;

	return false;//正常情况下不会运行这句
}
//打印Item到文件
bool Queue_savetofile(const Queue * queue, FILE *file)
{
	Node *current = queue->first;
	int i = 0;

	if (file == NULL)
	{
		fprintf(stderr, "NULL\n");
		assert(0);
		return false;
	}

	while (current != NULL)
	{
		if (1 != fwrite(&current->item, sizeof(Item), 1, file))
		{
			fprintf(stderr, "I/O ERROR\n");
			assert(0);
			return false;
		}
		current = current->next;
		i++;
	}

	if (i != queue->items)
	{
		fprintf(stderr, "NULL\n");
		assert(0);
		return false;
	}

	return true;
}
//从文件读入Item，加到队列末尾
bool Queue_readfromfile(Queue * queue, FILE *file)
{
	Node *current = queue->first;
	Item temp;

	if (file == NULL)
	{
		fprintf(stderr, "NULL\n");
		assert(0);
		return false;
	}

	while ((int)fread(&temp, sizeof(Item), 1, file))//这里未考虑I/O错误，只当做读取失败时是到了文件结尾
	{
		if (false == Queue_enqueue_A(queue, temp))//是否添加节点成功
		{
			fprintf(stderr, "Enqueue failed\n");
			assert(0);
			return false;
		}
	}

	return true;
}
//队列全排序
void Queue_sort(Queue * queue, int(*compare)(Item a, Item b))//待修改为指针间排序
{
	Node *current = queue->first;
	int i, ii;
	Item temp;

	for (i = 0; i < (queue->items); i++)
	{
		for (ii = 0; ii < ((queue->items) - 1); ii++)
		{
			if (compare(current->item, current->next->item))//修改为排序函数,由使用传入，队列实现内不做定义
			{
				temp = current->item;
				current->item = current->next->item;
				current->next->item = temp;
			}
			current = current->next;
		}
		current = queue->first;
	}
}
//修改第n项的Item为输入的Item
bool Queue_modify(Queue * queue, int index, Item item)
{
	Node *current;//在寻找第n项时作为标志
	if ((current = Queue_movetoindex(queue, index)) == NULL)
	{
		fprintf(stderr, "Overpass\n");
		assert(0);
		return false;
	}
	current->item = item;
	return true;
}
//搜索项目,找到时返回index,没找到返回-1,第三个参数为函数指针，该函数需要在Item符合相同的条件时返回1
int Queue_find(const Queue * queue, Item item, int(*isequal)(Item a, Item b))
{
	Node * current = queue->first;
	int index = 1;

	while (current != NULL)
	{
		if (isequal(item, current->item))
			return index;
		else
		{
			index++;
			current = current->next;
		}
	}

	return -1;

}
//搜索项目,找到时返回Item,没找到返回None,第三个参数为函数指针，该函数需要在Item符合相同的条件时返回1
Item Queue_Search(const Queue * queue, Item item, int(*isequal)(Item a, Item b))
{
	Node * current = queue->first;
	int index = 1;

	while (current != NULL)
	{
		if (isequal(item, current->item))
			return current->item;
		else
		{
			index++;
			current = current->next;
		}
	}

	return None;
}
//打印第n项
bool Queue_showitem(Queue *queue, int index, void(*showitem)(Item item))
{
	Node * current = queue->first;
	if ((current = Queue_movetoindex(queue, index)) == NULL)
	{
		fprintf(stderr, "Overpass\n");
		assert(0);
		return false;
	}
	showitem(current->item);
	return true;
}
//删除节点
bool Queue_delete(Queue *queue, int index)
{
	Node *current = NULL;
	Node *temp;

	if (index == 1)
	{
		if (Queue_isempty(queue))
		{

			fprintf(stderr, "Overpass\n");
			assert(0);
			return false;
		}
		temp = queue->first;
		queue->first = queue->first->next;
	}
	else
	{
		current = Queue_movetoindex(queue, index - 1);
		if (current == NULL)
		{
			fprintf(stderr, "Overpass\n");
			assert(0);
			return false;
		}
		temp = current->next;
		current->next = NULL;
	}

	
	free(temp);
	queue->last = current;
	(queue->items)--;

	return true;
}
//跳转到某一节点处
static Node *Queue_movetoindex(Queue *queue, int index)
{
	int i;
	Node * current = queue->first;

	if (index <= 0 || index > Queue_items(queue))
	{
		fprintf(stderr, "Overpass\n");
		assert(0);
		return NULL;
	}

	for (i = 1; i < index; i++)
		current = current->next;

	return current;
}
#endif