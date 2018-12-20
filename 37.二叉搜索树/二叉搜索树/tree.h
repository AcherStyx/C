#pragma once
#ifndef _TREE_H_
#define _TREE_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

/*=====Tree����=====*/
//#define ITEMMAX 10000
#define TREE_DEBUG_ON
#define TREE_CHECK_REPEAT

/*=====���Ͷ���=====*/
typedef struct item
{
	int grade;
}Item;

typedef struct node
{
	Item item;
	struct node *left;
	struct node *right;
}Node;

typedef struct tree
{
	Node * root;
	int size;
}Tree;

/*=====ITEM����=====*/
#define NLENGTH 40
static int(*compare)(Item a, Item b);

/*=====�ӿں���=====*/
/*
>>>>>>>>>>��ʼ����
��Ҫ���������ζ�����Ԫ�ؽ�������ĺ���
�Ѿ���ʼ���õ������������ٴγ�ʼ��
*/
bool Tree_Initializing(Tree * tree, int(*HowToSort)(Item a, Item b))
{
#ifndef _TREE_INITIALIZED_ 
#define _TREE_INITIALIZED_
	tree->size = 0;
	tree->root = NULL;
	compare = HowToSort;
#endif
}

#	ifdef _TREE_INITIALIZED_//δ��ʼ��ʱ������������ຯ��

/*
>>>>>>>>>>����
*/
bool Tree_IsEmpty(const Tree * tree)
{
	return tree->size == 0;
}

/*
>>>>>>>>>>����
��û���趨ITEMMAXʱʼ�շ�����
*/
bool Tree_IsFull(const Tree * tree)
{
#ifdef ITEMMAX  //�������������
	return tree->size >= ITEMMAX;
#else
	return 1;
#endif
}

/*
>>>>>>>>>>������
����ָ������������Ŀ���ڵĽڵ�ĵ�ַ������û��ʱ������NULL��
*/
Node *Tree_Search(const Tree * tree, Item item)
{
	Node *current = tree->root;

	while (current != NULL)
	{
		switch (compare(item, current->item))
		{
		case 0:
			return current;
		case -1:
			current = current->left;
			break;
		case 1:
			current = current->right;
			break;
		default:
#ifdef TREE_DEBUG_ON
			fprintf(stderr, "�ȽϺ������ڴ���\n");
			assert(0);
#endif
			return NULL;
		}
	}

	return NULL;
}

/*
>>>>>>>>>>������������ָ�򴢴�һ���ڵ��ָ��ĵ�ַ��
*/
Node **Tree_Search_PreNode(Tree * tree, Item item)
{
	Node *current = tree->root;
	Node **pre = &((*tree).root);

	while (current != NULL)
	{
		switch (compare(item, current->item))
		{
		case 0:
			return pre;
			break;
		case -1:
			pre = &((*current).left);
			current = current->left;
			break;
		case 1:
			pre = &((*current).right);
			current = current->right;
			break;
		default:
#ifdef TREE_DEBUG_ON
			fprintf(stderr, "�ȽϺ������ڴ���\n");
			assert(0);
#endif
			return NULL;
		}
	}

	return pre;
}

/*
>>>>>>>>>>��ӽڵ�
���ظ�ʱ�����
*/
bool Tree_AddItem(Tree * tree, Item item)
{
	Node ** current;
	Node * temp;
	int cmp;

	//�����ڴ沢��ʼ���ڵ�
	temp = (Node *)malloc(sizeof(Node));
	if (temp == NULL)
	{
#ifdef TREE_DEBUG_ON
		fprintf(stderr, "�ڴ����ʧ��\n");
		assert(0);
#endif
		return false;
	}
	temp->left = NULL;
	temp->right = NULL;
	temp->item = item;

	//�ҵ�λ�ò�����
	current = Tree_Search_PreNode(tree, item);
	if ((*current) == NULL)
	{
		(*current) = temp;
		tree->size++;
	}
	else
	{
#ifdef TREE_CHECK_REPEAT
		fprintf(stderr, "Ԫ���ظ�\n");
		assert(0);
#endif
		return false;
	}

	return true;
}

/*
>>>>>>>>>>�ݹ��ӡ���ڲ�������
�����Ժ������ڲ�����
*/
static void Tree_ShowAll_Recursion(Node * node, void(*ShowItem)(Item item, int deep), int deep)
{
	ShowItem(node->item, deep);

	if (node->left != NULL)
		Tree_ShowAll_Recursion(node->left, ShowItem, deep++);
	if (node->right != NULL)
		Tree_ShowAll_Recursion(node->right, ShowItem, deep++);
}

/*
>>>>>>>>>>��ӡ��
��Ҫ�����ӡ����
��ӡ����Ҫ������Բ�ͬ�Ĳ���δ�ӡ��Ŀ
*/
void Tree_ShowAll(const Tree * tree, void(*ShowItem)(Item item, int deep))
{
	Tree_ShowAll_Recursion(tree->root, ShowItem, 0);
}



#	endif
#endif