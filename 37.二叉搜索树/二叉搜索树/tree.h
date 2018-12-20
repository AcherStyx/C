#pragma once
#ifndef _TREE_H_
#define _TREE_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

/*=====Tree常量=====*/
//#define ITEMMAX 10000
#define TREE_DEBUG_ON
#define TREE_CHECK_REPEAT

/*=====类型定义=====*/
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

/*=====ITEM常量=====*/
#define NLENGTH 40
static int(*compare)(Item a, Item b);

/*=====接口函数=====*/
/*
>>>>>>>>>>初始化树
需要传入关于如何对树中元素进行排序的函数
已经初始化好的树，不允许再次初始化
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

#	ifdef _TREE_INITIALIZED_//未初始化时不允许调用其余函数

/*
>>>>>>>>>>树空
*/
bool Tree_IsEmpty(const Tree * tree)
{
	return tree->size == 0;
}

/*
>>>>>>>>>>树满
在没有设定ITEMMAX时始终返回真
*/
bool Tree_IsFull(const Tree * tree)
{
#ifdef ITEMMAX  //允许无最大限制
	return tree->size >= ITEMMAX;
#else
	return 1;
#endif
}

/*
>>>>>>>>>>搜索树
返回指向搜索到的项目所在的节点的地址（包括没有时，返回NULL）
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
			fprintf(stderr, "比较函数存在错误\n");
			assert(0);
#endif
			return NULL;
		}
	}

	return NULL;
}

/*
>>>>>>>>>>搜索树（返回指向储存一个节点的指针的地址）
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
			fprintf(stderr, "比较函数存在错误\n");
			assert(0);
#endif
			return NULL;
		}
	}

	return pre;
}

/*
>>>>>>>>>>添加节点
在重复时不添加
*/
bool Tree_AddItem(Tree * tree, Item item)
{
	Node ** current;
	Node * temp;
	int cmp;

	//分配内存并初始化节点
	temp = (Node *)malloc(sizeof(Node));
	if (temp == NULL)
	{
#ifdef TREE_DEBUG_ON
		fprintf(stderr, "内存分配失败\n");
		assert(0);
#endif
		return false;
	}
	temp->left = NULL;
	temp->right = NULL;
	temp->item = item;

	//找到位置并插入
	current = Tree_Search_PreNode(tree, item);
	if ((*current) == NULL)
	{
		(*current) = temp;
		tree->size++;
	}
	else
	{
#ifdef TREE_CHECK_REPEAT
		fprintf(stderr, "元素重复\n");
		assert(0);
#endif
		return false;
	}

	return true;
}

/*
>>>>>>>>>>递归打印（内部函数）
工具性函数，内部链接
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
>>>>>>>>>>打印树
需要传入打印函数
打印函数要包含针对不同的层如何打印项目
*/
void Tree_ShowAll(const Tree * tree, void(*ShowItem)(Item item, int deep))
{
	Tree_ShowAll_Recursion(tree->root, ShowItem, 0);
}



#	endif
#endif