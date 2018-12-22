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
//#define TREE_CHECK_REPEAT

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
static int(*compare)(Item a, Item b);//建立二叉树所用的顺序由该函数决定

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
给添加节点的函数使用的
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
			fprintf(stderr, "比较函数返回错误\n");
			assert(0);
#endif
			return NULL;
		}
	}

	return NULL;
}

/*
>>>>>>>>>>添加节点
在重复时不添加
在查到重复时可以选择终止程序，只要更改 TREE_CHECK_REPEAT 定义
*/
bool Tree_AddItem(Tree * tree, const Item item)
{
	Node ** current;
	Node * temp;
	int cmp;

	//找到位置，先寻找，以防止节点重复时继续分配内存
	current = Tree_Find_PreNode(tree, item);
	if ((*current) != NULL)
	{
#ifdef TREE_CHECK_REPEAT
		fprintf(stderr, "元素重复\n");
		assert(0);
#endif
		return false;
	}
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

	//插入
	(*current) = temp;
	tree->size++;

	return true;
}

/*
>>>>>>>>>>递归打印（内部函数）
工具性函数，内部链接
*/
static void Tree_ShowAll_Recursion(Node * node, void(*ShowItem)(Item item, int deep, int side, int branch), int deep, int side)
{
	if (node->left != NULL)
		Tree_ShowAll_Recursion(node->left, ShowItem, deep + 1, -1);

	if (node->left == NULL && node->right == NULL)
		ShowItem(node->item, deep, side, 2);
	else
		ShowItem(node->item, deep, side, -(node->left != NULL) + (node->right != NULL));

	if (node->right != NULL)
		Tree_ShowAll_Recursion(node->right, ShowItem, deep + 1, 1);
}

/*
>>>>>>>>>>打印树
需要传入打印函数
打印函数要包含针对不同的层如何打印项目
*/
void Tree_ShowAll(const Tree * tree, void(*ShowItem)(Item item, int deep, int side, int branch))
{
	if (tree->root != NULL)
	{
			Tree_ShowAll_Recursion(tree->root, ShowItem, 0, 0, 0);
	}
	
}

/*
>>>>>>>>>>二叉检索整个树
第二个参数为要搜索地项目，搜索到后会把整个item的内容复制到该地址指向的储存位置中
检索依据初始化用的比较函数，只能检查该比较函数比较的项
检查到项目时返回1，否则返回0
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
				fprintf(stderr, "比较函数返回错误\n");
				assert(0);
#endif
				return 0;
			}
		}
	}

	return 0;
}

/*
>>>>>>>>>>递归遍历（内部函数）
内部链接
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
>>>>>>>>>>遍历树
将函数作用于每一个树的节点
*/
bool Tree_Traverse(Tree * tree, void(*change)(Item *item))
{
	Tree_Traverse_Recursion(tree->root, change);
}

/*
>>>>>>>>>>递归删除节点（内部函数）
内部链接
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
>>>>>>>>>>删除全部节点
*/
void Tree_DeleteAll(Tree*tree)
{
	Tree_DeleteAll_Recursion(tree->root);
	tree->root = NULL;
	tree->size = 0;
}

/*
>>>>>>>>>>删除指定节点
*/
bool Tree_DeleteItem(Tree *tree, const Item item)
{
	Node ** current;
	Node ** successor;

	successor = current = Tree_Find_PreNode(tree, item);
	
	if (((*current) == NULL))
	{
		return false;
	}
	else
	{
		if (NULL != (*current)->right)//右树有节点
		{
			
		}
		else if (NULL != (*current)->left)//左树有节点
		{

		}
		else//都没节点
		{
			free(*current);
			tree->size--;
		}
	}

}

#	endif
#endif