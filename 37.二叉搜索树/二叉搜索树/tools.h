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
	printf("�������: ");
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
		printf("�� %-5d", item.grade);
		break;
	case 1:
		printf("�� %-5d", item.grade);
		break;
	case 0:
		printf("%-5d", item.grade);
		break;
	}

	switch (branch)
	{
	case -1:
		printf("��\n");
		break;
	case 1:
		printf("��\n");
		break;
	case 0:
		printf("��\n");
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
	printf("1.�����Ŀ\n2.��ӡȫ����Ŀ\n3.������Ŀ�Ƿ����\n4.������Ӧ����ȫ����Ŀ\n5.������5����������\n6.ɾ��ȫ���ڵ�\n7.\n");
}

/*
bool Tree_AddItem(Tree * tree, Item item)
{
	Node * current;
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
	current = Tree_Find_PreNode(tree, item, &cmp);
	if (current == NULL)
	{
		//������
		if (Tree_IsEmpty(tree) == 0)
		{
#ifdef TREE_DEBUG_ON
			fprintf(stderr, "�����������ص�ַ����\n");
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
			fprintf(stderr, "Ԫ���ظ�\n");
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
			fprintf(stderr, "�ȽϺ������ڴ���\n");
			assert(0);
#endif
			return NULL;
		}
	}

	return pre;
}
*/