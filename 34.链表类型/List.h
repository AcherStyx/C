#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>
struct item
{
	char name[50];
	int rank;
};

typedef struct item Item;

struct node
{
	struct node * pre;
	Item item;
	struct node * next;
};

typedef struct node Node;

typedef Node * List;

bool List_initializing(List *list)
{
	*list = NULL;
}

bool List_addnode(List *list, Item item)
{
	Node *current = *list;
	Node *temp = NULL;
	Node *pre = NULL;

	temp = (Node *)malloc(sizeof(Node));
	if (temp == NULL)
	{
		fprintf(stderr, "NULL\n");
		return false;
	}

	if (current == NULL)
	{
			*list = temp;
			temp->next = NULL;
			temp->pre = NULL;
			temp->item = item;//�ṹ��ֵ
	}
	else
	{
		while (current != NULL)
		{
			pre = current;
			current = current->next;//ֱ�Ӹ���current�ĵ�ַ��û���õģ���������ʵ���б��еĽڵ㣬ֻ�и�����ָ��Ľڵ��еĵ�ַ������
		}

		pre->next = temp;
		pre->next->next = NULL;
		pre->next->pre = pre;
		pre->next->item = item;//�ṹ��ֵ
	}

	return true;
}


bool List_show(List list)
{
	Node *current = list;
	int error = 0;
	int i = 0;

	while (current != NULL)
	{
		error+=printf("num:%d\n", i++);
		error+=printf("name:%s\n", current->item.name);
		error+=printf("rank:%d\n", current->item.rank);
		putchar('\n');
		current = current->next;
	}

	if (error == 3)
		return true;
	else
		return false;
}

void List_free(List *list)
{
	Node *current = *list;
	Node *next;

	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
	
	List_initializing(list);
}