#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "queue.h"


#define NDEBUG

int showmenue(void);
int idequal(Item a, Item b);
int nameequal(Item a, Item b);
bool getitem(Item * item);
void printitem(Item item);
void clear(void);
int pricecmp(Item a, Item b);

int main(void)
{
	Queue head;
	Item input;
	FILE *data;

	int mode = 1;
	int mode2;
	int index;

	int place;

	printf("������Ʒ����ϵͳ\n");

	//��ʼ��
	Queue_initializing(&head);
	data = fopen("queuedata", "rb");
	Queue_readfromfile(&head, data);
	fclose(data);

	do
	{
		mode = showmenue();

		putchar('\n');
		switch (mode)
		{
		case 1:
			Queue_showall(&head, printitem);
			//			printf("Done.\n");
			break;
		case 2:
			printf("ͨ����һ��Ѱ����Ʒ:\n1)��ƷID  2)��Ʒ����\n��������ѡ��: ");
			scanf("%d", &mode2);

			switch (mode2)
			{
			case 1:
				printf("������Ҫ�޸ĵ���ƷID(-1�˳�����): \n");
				scanf("%s", input.id);

				if (strcmp(input.id, "-1") == 0)
					break;
				index = Queue_find(&head, input, idequal);
				if (index == -1)
				{
					printf("δ�ҵ�����Ʒ\n");
					break;
				}

				printf("�����µ���Ʒ��Ϣ: \n");
				getitem(&input);
				Queue_modify(&head, index, input);
				printf("�޸���Ʒ��Ϣ�ɹ�!�޸ĺ����ƷΪ: \n");
				Queue_showitem(&head, index, printitem);
				break;
			case 2:
				printf("������Ҫ�޸ĵ���Ʒ����(-1�˳�����): \n");
				scanf("%s", input.name);

				if (strcmp(input.id, "-1") == 0)
					break;

				index = Queue_find(&head, input, nameequal);

				if (index == -1)
				{
					printf("δ�ҵ�����Ʒ\n");
					break;
				}

				printf("�����µ���Ʒ��Ϣ: \n");
				getitem(&input);
				Queue_modify(&head, index, input);
				printf("�޸���Ʒ��Ϣ�ɹ�!�޸ĺ����ƷΪ: \n");
				Queue_showitem(&head, index, printitem);
				break;
			default:
				printf("�����ѡ��\n");
				break;
			}
			break;
		case 3:
			getitem(&input);
			printf("���뵽��λ��:");
			scanf("%d", &place);
			Queue_enqueue_B(&head, input, place);
			break;
		case 4:
			printf("����Ҫɾ������Ʒ����(-1�˳�):");
			clear();
			if (NULL != fgets(input.name, NAME_LEN, stdin) || strlen(input.name) > 0)
				input.name[strlen(input.name) - 1] = '\0';

			if (strcmp(input.id, "-1") == 0)
				break;

			index = Queue_find(&head, input, nameequal);

			if (index == -1)
			{
				printf("δ�ҵ�����Ʒ\n");
				break;
			}

			Queue_delete(&head, index);
			printf("��Ʒɾ���ɹ�\n");

			break;
		case 5:
			printf("����Ҫ���ҵ���Ʒ����(-1�˳�):");
			clear();
			if (NULL != fgets(input.name, NAME_LEN, stdin) || strlen(input.name) > 0)
				input.name[strlen(input.name) - 1] = '\0';

			if (strcmp(input.id, "-1") == 0)
				break;

			index = Queue_find(&head, input, nameequal);

			if (index == -1)
			{
				printf("δ�ҵ�����Ʒ\n");
				break;
			}

			Queue_showitem(&head, index, printitem);

			break;
		case 6:
			data = fopen("queuedata", "wb");
			Queue_savetofile(&head, data);
			fclose(data);
			exit(0);
			break;
		case 7:
			Queue_sort(&head, pricecmp);
			break;
		case 8:
			Queue_clean(&head);
			printf("�����������Ʒ��Ϣ\n");
		default:
			if (mode != 0)
			{
				//				printf("����ѡ��\n");

			}
			break;
		}
	} while (mode != 0);




	return 0;
}

//��ӡ�˵�
int showmenue(void)
{
	int mode;
show_again:
	printf("***********************************************************************\n");
	printf("1.��ʾ������Ʒ����Ϣ:\n");
	printf("2.�޸�ĳ����Ʒ����Ϣ:\n");
	printf("3.����ĳ����Ʒ����Ϣ:\n");
	printf("4.ɾ��ĳ����Ʒ����Ϣ:\n");
	printf("5.����ĳ����Ʒ����Ϣ:\n");
	printf("6.��Ʒ���̲��˳�ϵͳ:\n");
	printf("7.����Ʒ�۸��������:\n");
	printf("8.(����)ɾ����������:\n");
	printf("����.�����̲��˳�ϵͳ:\n");
	printf("***********************************************************************\n");
	printf("��������ѡ��: ");
	if (0 == scanf("%d", &mode))
	{
		clear();
		goto show_again;
	}
	return mode;
}
//id��ͬ
int idequal(Item a, Item b)
{
	return strcmp(a.id, b.id) == 0;
}
//name��ͬ
int nameequal(Item a, Item b)
{
	return strcmp(a.name, b.name) == 0;
}
//¼����Ŀ
bool getitem(Item * item)
{
	int check = 0;
	printf("��ƷID: ");
	check += scanf("%s", item->id);

	clear();
	printf("��Ʒ����: ");
	check += (NULL!= fgets(item->name, NAME_LEN, stdin));
	if (strlen(item->name) > 0)
		item->name[strlen(item->name) - 1] = '\0';

	printf("��Ʒ�۸�: ");
	check += scanf("%d", &item->price);

	printf("��Ʒ�ۿ�: ");
	check += scanf("%f", &item->discount);

	printf("��Ʒ����: ");
	check += scanf("%d", &item->total);

	printf("��Ʒʣ��: ");
	check += scanf("%d", &item->rest);

	if (check == 6)
		return true;
	else
		return false;

	return false;//��������ִ�����
}
//��ӡ��Ŀ
void printitem(Item item)
{
	printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	printf("ID:%s   ����:%s  �۸�:%d  �ۿ�:%.1f  ����:%d  ʣ��:%d\n", item.id, item.name, item.price, item.discount, item.total, item.rest);
	printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
}
//�����
void clear(void)
{
	char in = '\0';
	while ((in = getchar()) != '\n')
		;
}
//����
int pricecmp(Item a, Item b)
{
	if (a.price > b.price)
		return 1;
	else
		return 0;
}