#ifndef _SeqList_ADT_
#define _SeqList_ADT_

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h> //C99

/*=====һЩ˵��=====
"����ֵһ������int�෵���쳣��-1��������һЩ����ͬʱ��ʾ�������쳣�ķ���ֵ"
"Ҫ����������Ϣ����������ӵ�������������������"
"�����漰�����������Ǵ�0��"
"Ϊ���ֶԲ�ͬElement_Type��ͨ���ԣ���ʱ��Ҫ����ȽϺ���"*/

#ifndef Element_Type	//��main�����ж��������Ը��Ǵ˴���Ĭ�϶���
#	define Element_Type int 
#endif

typedef struct list
{
	Element_Type *data;
	int num;
	int max;
} *List;

int List_Init(List *head, int const len)
{
	Element_Type* temp = (Element_Type*)malloc(sizeof(Element_Type)*len);
	*head = (List)malloc(sizeof(struct list));
	if (temp == NULL || (*head) == NULL)
		return -1;

	(*head)->data = temp;
	(*head)->num = 0;
	(*head)->max = len;

	return 0;
}

int List_Length(List const head)
{
	return head->num;
}

int List_Get(List const head, int const index,Element_Type * distination)
{
	if (index<1 || index>=head->num)
		return -1;
	else
	{
		*distination = head->data[index];
		return 0;
	}
}

//����-1��ʾδ�ҵ�,����ĺ�����Ҫ����Ԫ����ͬʱ����0,ֱ�ӷ����±꣨���������ǵڼ���Ԫ�أ�
int List_Locate(List const head, Element_Type const elem,bool(how_to_compare)(Element_Type a,Element_Type b))
{
	for (int i = 0; i < head->num; i++)
	{
		if (!how_to_compare(head->data[i], elem))
			return i;
	}
	return -1;
}

int List_Prior(List const head, Element_Type const elem, Element_Type *distination, bool(how_to_compare)(Element_Type a, Element_Type b))
{
	int index = List_Locate(head, elem, how_to_compare);

	if (index < 1)
		return -1;
	else
	{
		*distination = head->data[index - 1];
		return 0;
	}
}

int List_Next(List const head, Element_Type const elem, Element_Type * distination, bool(how_to_compare)(Element_Type a, Element_Type b))
{
	int index = List_Locate(head, elem, how_to_compare);

	if (index < 0 || index >= head->num)
		return -1;
	else
	{
		*distination = head->data[index + 1];
		return 0;
	}
}

//�˺�������������λ֮��᲻���±�Խ�磬�ɵ������ĺ���������һ����
//λ��ʱ���ײ���β
static int List_Move(Element_Type * arr, int start, int end, int offset)
{
	if (offset < 0)
	{
		for (int i = start; i < end; i++)
		{
			arr[i + offset] = arr[i];
		}
	}
	else if (offset > 0)
	{
		for (int i = end - 1; i >= start; i--)
		{
			arr[i + offset] = arr[i];
		}
	}
	//offset==0ֱ������
	return 0;
}

//index��0��,-1����ĩβ
int List_Insert(List const head, Element_Type const elem, int index)
{
	//����±�
	if (index >= head->num + 1 || index < -1)
		return -1;
	//���Խ��
	if (head->num >= head->max)
		return -1;
	//-1ʱ���������λ���Զ���Ϊ��β
	if (index == -1)
		index = head->num;
	if (List_Move(head->data, index, head->num, 1))
		return -1;
	head->data[index] = elem;
	head->num++;
	return 0;
}

int List_Delete(List const head, Element_Type const elem,bool(how_to_compare)(Element_Type a,Element_Type b))
{
	int index = List_Locate(head, elem, how_to_compare);
	if (index == -1)
		return -1;
	if (-1==List_Move(head->data, index + 1, head->num, -1))
		return -1;
	head->num--;
	return 0;
}

bool List_IsEmpty(List const head)
{
	return 0 == head->num ? 1 : 0;
}

//����һ���涨��ÿ��Ԫ��ִ�еĲ����ĺ������������������0ʱ�����˳�����
int List_Traverse(List const head, bool(operation)(Element_Type data))
{
	for (int i = 0; i < head->num; i++)
	{
		if (0 == operation(head->data[i]))
			break;
	}
	return 0;
}





#endif
