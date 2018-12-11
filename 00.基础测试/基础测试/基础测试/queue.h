#pragma once
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <iso646.h>
#include <assert.h>

#define NDEBUG

#define NLENGTH 50
#define WLENGTH 50

#define ITEMMAX 2

typedef struct item
{
	char bookname[NLENGTH];
	char writer[WLENGTH];
} Item;

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
	if (queue->items == ITEMMAX)
		return 1;
	else
		return 0;
}

//队列项数
int Queue_items(const Queue *queue)
{
	return queue->items;
}

//添加项
bool Queue_enqueue(Queue * queue, const Item item)
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
		queue->last = temp;
	}
	else
	{
		queue->last->next = temp;
		queue->last = temp;
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
void Queue_clean(Queue * queue)
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
		assert(0);


}

void Queue_getitem(Item * item)
{
	printf("[Name]:\n");
	scanf("%s", &item->bookname);
	printf("[Writer]:\n");
	scanf("%s", &item->writer);
}

void Queue_showitem(Item item)
{
	printf("[Name]:%s\n", item.bookname);
	printf("[Writer]:%s\n", item.writer);
}

bool Queue_showall(const Queue *queue)
{
	Node *current = queue->first;
	int i = 0;

	while (current != NULL)
	{
		i++;
		printf("NUM. %d\n", i);
		Queue_showitem(current->item);
		putchar('\n');

		current = current->next;
	}
	
	if (i != queue->items)
	{
		fprintf(stderr,"Not match\n");
		assert(0);
		return false;
	}
	else
		return true;

	return false;//正常情况下不会运行这句
}