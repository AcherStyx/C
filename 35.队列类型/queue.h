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

#define ITEMMAX 1000

typedef struct item
{
	char bookname[NLENGTH];
	char writer[WLENGTH];
} Item;//Item��������

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


/*=========================================�ӿ�=========================================*/
//��ʼ��
void Queue_initializing(Queue * queue);
//���п�
bool Queue_isempty(const Queue * queue);
//������
bool Queue_isfull(const Queue * queue);
//��������
int Queue_items(const Queue *queue);
//�����
bool Queue_enqueue(Queue * queue, const Item item);
//�����
bool Queue_dequeue(Queue * queue, Item * item);
//��ն���
void Queue_clean(Queue * queue);
//��ӡ��������
bool Queue_showall(const Queue *queue);
//��ӡItem���ļ�
bool Queue_savetofile(const Queue * queue, FILE *file);
//���ļ�����Item���ӵ�����ĩβ
bool Queue_readfromfile(Queue * queue, FILE *file);

//��ӡ��Ŀ
void Queue_showitem(Item item);





//��ʼ��
void Queue_initializing(Queue * queue)
{
	queue->first = NULL;
	queue->last = NULL;
	queue->items = 0;
}

//���п�
bool Queue_isempty(const Queue * queue)
{
	if (queue->items == 0)
		return 1;
	else
		return 0;
}

//������
bool Queue_isfull(const Queue * queue)
{
	if (queue->items == ITEMMAX)
		return 1;
	else
		return 0;
}

//��������
int Queue_items(const Queue *queue)
{
	return queue->items;
}

//�����
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
	}
	else
	{
		queue->last->next = temp;
	}

	queue->last = temp;
	queue->items++;

	return true;
}

//�����
bool Queue_dequeue(Queue * queue, Item * item)
{
	Node * temp;//��ʱ�����һ���ڵ�ĵ�ַ

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

//��ն���
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

//��ӡ��������
bool Queue_showall(const Queue *queue)
{
	Node *current = queue->first;
	int i = 0;

	while (current != NULL)
	{
		i++;
		//printf("NUM. %d\n", i);
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

	return false;//��������²����������
}

//��ӡItem���ļ�
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

//���ļ�����Item���ӵ�����ĩβ
bool Queue_readfromfile(Queue * queue, FILE *file)
{
	Node *current = queue->first;
	Item temp;

	if(file==NULL)
	{
		fprintf(stderr, "NULL\n");
		assert(0);
		return false;
	}

	while((int)fread(&temp, sizeof(Item), 1, file))//����δ����I/O����ֻ������ȡʧ��ʱ�ǵ����ļ���β
	{
		if (false == Queue_enqueue(queue, temp))//�Ƿ���ӽڵ�ɹ�
		{
			fprintf(stderr, "Enqueue failed\n");
			assert(0);
			return false;
		}
	}

	return true;
}

/*===================================��Ҫ����Item�ṹ���ĵĺ���===================================*/

//¼����Ŀ
void Queue_getitem(Item * item)
{
	printf("[Name]:\n");
	scanf("%s", &item->bookname);
	printf("[Writer]:\n");
	scanf("%s", &item->writer);
}

//��ӡ��Ŀ
void Queue_showitem(Item item)
{
	printf("[Name]:%s\n", item.bookname);
	printf("[Writer]:%s\n", item.writer);
}