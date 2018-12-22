#pragma once

int cmp(Item a, Item b)
{
	if (a.grade == b.grade)
		return 0;
	else if (a.grade < b.grade)
		return -1;
	else
		return 1;
}

void getitem(Item * item)
{
	printf("输入分数: ");
	scanf("%d", &item->grade);
}

void showitem(Item item, int deep, int side, int branch)
{
	int i;
	if (deep > 0)
		printf("     ");
	for (i = 1; i < deep; i++)
		printf("       ");
	
	switch (side)
	{
	case -1:
		printf("┌ %-5d", item.grade);
		break;
	case 1:
		printf("└ %-5d", item.grade);
		break;
	case 0:
		printf("%-5d", item.grade);
		break;
	}

	switch (branch)
	{
	case -1:
		printf("┘\n");
		break;
	case 1:
		printf("┐\n");
		break;
	case 0:
		printf("┤\n");
		break;
	default:
		printf("  \n");
	}

}

int randdata(int down, int up)
{
	return rand() % (up - down) + down;
}

void minus(Item *item)
{
	item->grade -= 1;
}

void showmenue(void)
{
	printf("1.添加项目\n2.打印全部项目\n3.查找项目是否存在\n4.将函数应用于全部项目\n5.随机添加5个测试数据\n6.删除全部节点\n7.\n");
}

/*
bool Tree_AddItem(Tree * tree, Item item)
{
	Node * current;
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
	current = Tree_Find_PreNode(tree, item, &cmp);
	if (current == NULL)
	{
		//错误检查
		if (Tree_IsEmpty(tree) == 0)
		{
#ifdef TREE_DEBUG_ON
			fprintf(stderr, "搜索函数返回地址错误\n");
			assert(0);
#endif
			return false;
		}

		tree->root = temp;
	}
	else
	{
		switch (cmp)
		{
		case -1:
			current->left = temp;
			break;
		case 1:
			current->right = temp;
			break;
		case 0:
#ifdef TREE_CHECK_REPEAT
			fprintf(stderr, "元素重复\n");
			assert(0);
#endif
			return false;
			break;
		default:
			break;
		}
	}
	tree->size++;

	return true;
}
*/

/*
Node *Tree_Find_PreNode(Tree * tree, Item item, int *cmp)
{
	Node *current = tree->root;
	Node *pre = NULL;

	while (current != NULL)
	{
		switch (*cmp = compare(item, current->item))
		{
		case 0:
			return pre;
			break;
		case -1:
			pre = current;
			current = current->left;
			break;
		case 1:
			pre = current;
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
*/