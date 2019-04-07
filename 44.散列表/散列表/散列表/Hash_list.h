#ifndef _HASH_LIST_
#define _HASH_LIST_
/*====================����====================*/
#define SEED 131
#define In_type char*	//�������������
#define Out_type int	//�������������
#define HASH Hash		//ָ��ʹ�õ�Hash����
/*====================����====================*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "queue.h"		//���ö���ͷ�ļ�������ʹ����֮ǰ�����Out_type���Է��ں���
/*====================�ṹ====================*/
typedef struct Hashlist
{
	Queue **data;
	int len;
} Hashlist;
/*====================����====================*/
/*>>>>>>>>>>Hash����
�����ַ��������������Ϊ�±�
*/
static unsigned int Hash(char *str)
{
	unsigned int seed = SEED;// 31 131 1313 13131 131313 etc..    
	unsigned int hash = 0;
	while (*str)
	{
		hash = hash * seed + (*str++);
	}
	return (hash & 0x7FFFFFFF);
}
/*>>>>>>>>>>��ʼ��
�����ʼʱ����ĳ���
*/
Hashlist *Hashlist_Init(int len)
{
	Hashlist* hashlist = (Hashlist*)malloc(sizeof(Hashlist));
	hashlist->data = (Queue**)malloc(sizeof(Queue*)*len);
	for (int i = 0; i < len; i++)
	{
		hashlist->data[i] = (Queue*)malloc(sizeof(Queue));
		Queue_initializing(hashlist->data[i]);
	}
	hashlist->len = len;
	return hashlist;
}
/*>>>>>>>>>>�������
ͨ��ָ����ɢ�к�����������ӵ�������
*/
int Hashlist_Add(Hashlist *list, In_type label, Out_type data)
{
	unsigned long index = HASH(label) % list->len;
	Queue_enqueue_A(list->data[index], (Item) { label, data });
	return 0;
}
/*>>>>>>>>>>��ӡ��������
*/
int Hashlist_PrintAll(Hashlist *list, void(*how_to_print)(Item))
{
	for (int i = 0; i < list->len; i++)
	{
		Queue_showall(list->data[i], how_to_print);
	}
	return 0;
}
/*>>>>>>>>>>����
*/
static int Hashlist_Search_cmp(Item a, Item b)
{
	if (strcmp(a.label, b.label) == 0)
		return 1;
	else
		return 0;
}
int Hashlist_Search(Hashlist *list, In_type which_to_find, Out_type *out)
{
	int index = HASH(which_to_find);
	Item se;
	se.label = which_to_find;
	Item feedback = Queue_Search(list->data[index%list->len], se, Hashlist_Search_cmp);
	*out = feedback.data;
	return 0;
}
/*====================Debug====================*/
/*>>>>>>>>>>�����������
*/
char * i_itoa(int n)
{
	char s[50];
	char *temp;
	int i;
	i = 0;
	do {
		s[i++] = n % 10 + '0';//ȡ��һ������
	} while ((n /= 10) > 0);//ɾ��������
	s[i] = '\0';
	temp = (char*)malloc(sizeof(char)*i);
	temp[i] = '\0';
	for (int ii = i - 1; ii >= 0; ii--)
		temp[i - ii - 1] = s[ii];

	return temp;
}
int Hashlist_Debug_Randomdata(Hashlist* list, int data_amount)
{
	srand(time(NULL));
	for (int i = 0; i < data_amount; i++)
	{
		int data = rand();
		Hashlist_Add(list, i_itoa(data), data + 1);
	}
}


#endif