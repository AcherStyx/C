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
#define NAME_LEN 100
//#define TREE_CHECK_REPEAT

/*=====���Ͷ���=====*/
typedef struct item
{
	int grade;
	char name[NAME_LEN];
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
static int(*compare)(Item a, Item b);//�������������õ�˳���ɸú�������

/*=====�ӿں���=====*/
/*
>>>>>>>>>>��ʼ����
��Ҫ���������ζ�����Ԫ�ؽ�������ĺ���?
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

#	ifdef _TREE_INITIALIZED_//δ��ʼ��ʱ�������������ຯ��

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
#ifdef ITEMMAX  //�������������?
	return tree->size >= ITEMMAX;
#else
	return 1;
#endif
}

/*
>>>>>>>>>>������������ָ��һ���ڵ�ĵ�ַ��?
����ָ������������Ŀ���ڵĽڵ�ĵ�ַ������û��ʱ������NULL��
*/
static Node *Tree_Find(const Tree * tree, Item item)
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
�����ӽڵ�ĺ���ʹ�õ�?
*/
static Node **Tree_Find_PreNode(Tree * tree, Item item)
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
			fprintf(stderr, "�ȽϺ������ش���\n");
			assert(0);
#endif
			return NULL;
		}
	}

	return pre;
}

/*
>>>>>>>>>>���������ݹ飩
���ڻ�����������������
*/
static Node * Tree_Search_Recursion(Node * current, Item *item, bool(*is_equal_search)(Item a, Item b))
{
	Node * temp;
	
	if (current == NULL)
		return NULL;
	else if (is_equal_search(current->item, *item))
		return current;
	else
	{
		if (NULL != (temp = Tree_Search_Recursion(current->left, item, is_equal_search)))
			return temp;
		else if (NULL != (temp = Tree_Search_Recursion(current->right, item, is_equal_search)))
			return temp;
		else
			return NULL;
	}
}

/*
>>>>>>>>>>������������Ҫ�����Ľڵ��������Ϣ�������У�?
�����ն������ķ�ʽ���������ڰ����ǻ��ڽ���ʱ������������������
���Ҳ���ƥ��Ľڵ�ʱ������?0���ҵ�ʱ����1
*/
bool Tree_Search(Tree*tree, Item *item, bool(*is_equal_search)(Item a, Item b))
{
	Node *current;
	
	current = Tree_Search_Recursion(tree->root, item, is_equal_search);

	if (current == NULL)
	{
		return false;
	}
	
	*item = current->item;
	return true;
}

/*
>>>>>>>>>>���ӽڵ�
���ظ�ʱ������
�ڲ鵽�ظ�ʱ����ѡ����ֹ����ֻҪ���� TREE_CHECK_REPEAT ����
*/
bool Tree_AddItem(Tree * tree, const Item item)
{
	Node ** current;
	Node * temp;
	int cmp;

	//�ҵ�λ�ã���Ѱ�ң��Է�ֹ�ڵ��ظ�ʱ���������ڴ�
	current = Tree_Find_PreNode(tree, item);
	if ((*current) != NULL)
	{
#ifdef TREE_CHECK_REPEAT
		fprintf(stderr, "Ԫ���ظ�\n");
		assert(0);
#endif
		return false;
	}
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

	//����
	(*current) = temp;
	tree->size++;

	return true;
}

/*
>>>>>>>>>>�ݹ��ӡ���ڲ�������?
�����Ժ������ڲ�����
*/
static void Tree_ShowAll_Recursion(Node * node, void(*ShowItem)(Item item, int deep, int side, int branch), int deep, int side)
{
	if (node->right != NULL)
		Tree_ShowAll_Recursion(node->right, ShowItem, deep + 1, 1);

	if (node->left == NULL && node->right == NULL)
		ShowItem(node->item, deep, side, 2);
	else
		ShowItem(node->item, deep, side, -(node->left != NULL) + (node->right != NULL));

	if (node->left != NULL)
		Tree_ShowAll_Recursion(node->left, ShowItem, deep + 1, -1);
}

/*
>>>>>>>>>>��ӡ��
��Ҫ�����ӡ����?
��ӡ����Ҫ������Բ�ͬ�Ĳ���δ�ӡ��Ŀ
*/
void Tree_ShowAll(const Tree * tree, void(*ShowItem)(Item item, int deep, int side, int branch))
{
	if (tree->root != NULL)
	{
			Tree_ShowAll_Recursion(tree->root, ShowItem, 0, 0, 0);
	}
	
}

/*
>>>>>>>>>>�������������?
�ڶ�������ΪҪ��������Ŀ����������������item�����ݸ��Ƶ��õ�ַָ��Ĵ���λ����?
�������ݳ�ʼ���õıȽϺ�����ֻ�ܼ��ñȽϺ����Ƚϵ���
��鵽��Ŀʱ����?1�����򷵻�0
*/
bool Tree_BSearch(const Tree * tree, Item * item)
{
	Node * current = tree->root;
	if (tree->root == NULL)
		return 0;
	else
	{
		while (current != NULL)
		{
			switch (compare(*item, current->item))
			{
			case 0:
				*item = current->item;
				return 1;
				break;
			case -1:
				current = current->left;
				break;
			case 1:
				current = current->right;
				break;
			default:
#ifdef TREE_DEBUG_ON
				fprintf(stderr, "�ȽϺ������ش���\n");
				assert(0);
#endif
				return 0;
			}
		}
	}

	return 0;
}

/*
>>>>>>>>>>�ݹ�������ڲ�������?
�ڲ�����
*/
static void Tree_Traverse_Recursion(Node * node, void(*change)(Item *item))
{
	if (node != NULL)
	{
		change(&(node->item));
		Tree_Traverse_Recursion(node->left, change);
		Tree_Traverse_Recursion(node->right, change);
	}
}

/*
>>>>>>>>>>������
������������ÿһ�����Ľڵ�
*/
bool Tree_Traverse(Tree * tree, void(*change)(Item *item))
{
	Tree_Traverse_Recursion(tree->root, change);
}

/*
>>>>>>>>>>�ݹ�ɾ���ڵ㣨�ڲ�������
�ڲ�����
*/
static void Tree_DeleteAll_Recursion(Node *node)
{
	if (node != NULL)
	{
		Tree_DeleteAll_Recursion(node->left);
		Tree_DeleteAll_Recursion(node->right);
		free(node);
	}
}

/*
>>>>>>>>>>ɾ��ȫ���ڵ�
*/
void Tree_DeleteAll(Tree*tree)
{
	Tree_DeleteAll_Recursion(tree->root);
	tree->root = NULL;
	tree->size = 0;
}

/*
>>>>>>>>>>ɾ��ָ���ڵ�
*/
bool Tree_DeleteItem(Tree *tree, const Item item)
{
	Node ** current;
	Node ** successor;
	Node * ptrtemp;
	Node * rabbish;
	Node temp;

	successor = current = Tree_Find_PreNode(tree, item);
	
	if (((*current) == NULL))
	{
		return false;
	}
	else
	{
		if (NULL != (*current)->right)//�����нڵ�
		{
			successor = &((**current).right);//��ת������
			while ((*successor)->left != NULL && (*successor) != NULL)
				successor = &((**successor).left);
			
			ptrtemp = *successor;
			rabbish = *current;

			*successor = (*successor)->right;

			temp.left = (*current)->left;//�ݴ������������?
			temp.right = (*current)->right;

			*current = ptrtemp;

			(*current)->left = temp.left;
			(*current)->right = temp.right;
			
			free(rabbish);
			tree->size--;
		}
		else if (NULL != (*current)->left)//�����нڵ�
		{
			successor = &((**current).left);
			while ((*successor)->right != NULL && (*successor) != NULL)
				successor = &((*successor)->right);

			ptrtemp = *successor;
			rabbish = *current;

			*successor = (*successor)->left;

			temp.left = (*current)->left;//�ݴ������������?
			temp.right = (*current)->right;

			*current = ptrtemp;

			(*current)->left = temp.left;
			(*current)->right = temp.right;

			free(rabbish);
			tree->size--;
		}
		else//��û�ڵ�
		{
			free(*current);
			*current = NULL;
			tree->size--;
		}
	}

}

#ifdef NKKKK
	prin()
#endif


#	endif
#endif