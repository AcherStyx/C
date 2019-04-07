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

//�ڵ������ޣ�ȥ����������������
//#define ITEMMAX 1000

#define None (Item){NULL,-1}
/*=======================================���Ͷ���=======================================*/
typedef struct item
{
	In_type label;
	Out_type data;
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
//�����_A ��ĩβ
bool Queue_enqueue_A(Queue * queue, const Item item);
//�����_B ��ָ��λ�� 0��β 1��ͷ/�����n��ʾ��Ϊ��n�֮��ĺ���
bool Queue_enqueue_B(Queue * queue, const Item item, int place);
//�����
bool Queue_dequeue(Queue * queue, Item * item);
//��ն���
bool Queue_clean(Queue * queue);
//��ӡ��������
bool Queue_showall(const Queue *queue, void(*showitem)(Item));
//��ӡItem���ļ�
bool Queue_savetofile(const Queue * queue, FILE *file);
//���ļ�����Item���ӵ�����ĩβ
bool Queue_readfromfile(Queue * queue, FILE *file);
//����ȫ����
void Queue_sort(Queue * queue, int(*compare)(Item a, Item b));
//�޸ĵ�n���ItemΪ�����Item
bool Queue_modify(Queue * queue, int index, Item item);
//������Ŀ,�ҵ�ʱ����index,û�ҵ�����-1,�ڶ�������Ϊ����ָ�룬�ú�����Ҫ��Item������ͬ������ʱ����1
int Queue_find(const Queue * queue, Item item, int(*isequal)(Item a, Item b));
//��ӡ��n��
bool Queue_showitem(Queue *queue, int index, void(*showitem)(Item item));
//ɾ���ڵ�
bool Queue_delete(Queue *queue, int index);
//��ת��ĳһ�ڵ㴦
static Node *Queue_movetoindex(Queue *queue, int index);
/*=========================================ʵ��=========================================*/
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
#ifndef ITEMMAX
	return 0;
#else
	if (queue->items == ITEMMAX)
		return 1;
	else
		return 0;
#endif
}
//��������
int Queue_items(const Queue *queue)
{
	return queue->items;
}
//�����_A ��ĩβ
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
//�����_B ��ָ��λ�� 0��β 1��ͷ/�����n��ʾ��Ϊ��n�֮��ĺ���
bool Queue_enqueue_B(Queue * queue, const Item item, int place)
{
	Node *temp;
	Node *current;//��Ѱ�ҵ�n��ʱ��Ϊ��־
	int i;

	//��������
	if (Queue_isfull(queue))
	{
		fprintf(stderr, "FULL\n");
		assert(0);
		return false;
	}
	//�˳�����λ������
	if (place < 0 || place >(Queue_items(queue) + 1))
	{
		fprintf(stderr, "Overpass\n");
		assert(0);
		return false;
	}

	//����������n���Ҫ����뵽n+1��ʱ���������뵽���һ��
	if (place == (Queue_items(queue) + 1))
		place = 0;

	//�����ڴ�
	temp = (Node *)malloc(sizeof(Node));
	if (temp == NULL)
	{
		fprintf(stderr, "NULL\n");
		assert(0);
		return false;
	}
	//���ṹ��ֵ
	temp->item = item;
	//��֧ѡ��
	switch (place)
	{
		//��ӵ�ĩβ
	case 0:
		//��β���ʼ��
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
		//��ӵ���ͷ
	case 1:
		temp->next = queue->first;
		queue->first = temp;
		break;
		//��ӵ���n��
	default:
		current = queue->first;
		/*currentָ������տ�ʼʱ��ͨ��currentֻ�����õ�2��ڵ�*/
		for (i = 2; i < place; i++)
			current = current->next;

		temp->next = current->next;
		current->next = temp;

		break;
	}

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
//��ӡ��������
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

	if (file == NULL)
	{
		fprintf(stderr, "NULL\n");
		assert(0);
		return false;
	}

	while ((int)fread(&temp, sizeof(Item), 1, file))//����δ����I/O����ֻ������ȡʧ��ʱ�ǵ����ļ���β
	{
		if (false == Queue_enqueue_A(queue, temp))//�Ƿ���ӽڵ�ɹ�
		{
			fprintf(stderr, "Enqueue failed\n");
			assert(0);
			return false;
		}
	}

	return true;
}
//����ȫ����
void Queue_sort(Queue * queue, int(*compare)(Item a, Item b))//���޸�Ϊָ�������
{
	Node *current = queue->first;
	int i, ii;
	Item temp;

	for (i = 0; i < (queue->items); i++)
	{
		for (ii = 0; ii < ((queue->items) - 1); ii++)
		{
			if (compare(current->item, current->next->item))//�޸�Ϊ������,��ʹ�ô��룬����ʵ���ڲ�������
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
//�޸ĵ�n���ItemΪ�����Item
bool Queue_modify(Queue * queue, int index, Item item)
{
	Node *current;//��Ѱ�ҵ�n��ʱ��Ϊ��־
	if ((current = Queue_movetoindex(queue, index)) == NULL)
	{
		fprintf(stderr, "Overpass\n");
		assert(0);
		return false;
	}
	current->item = item;
	return true;
}
//������Ŀ,�ҵ�ʱ����index,û�ҵ�����-1,����������Ϊ����ָ�룬�ú�����Ҫ��Item������ͬ������ʱ����1
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
//������Ŀ,�ҵ�ʱ����Item,û�ҵ�����None,����������Ϊ����ָ�룬�ú�����Ҫ��Item������ͬ������ʱ����1
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
//��ӡ��n��
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
//ɾ���ڵ�
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
//��ת��ĳһ�ڵ㴦
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