#ifndef _SeqList_ADT_
#define _SeqList_ADT_

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h> //C99

/*=====一些说明=====
"返回值一般用了int类返回异常（-1），除了一些可以同时表示正常与异常的返回值"
"要返回其他信息，都采用添加到函数参数中这种做法"
"所有涉及到的索引都是从0起"
"为保持对不同Element_Type的通用性，有时需要传入比较函数"*/

#ifndef Element_Type	//在main函数中定义它可以覆盖此处的默认定义
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

//返回-1表示未找到,传入的函数需要在两元素相同时返回0,直接返回下标（而不是这是第几个元素）
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

//此函数不负责检查移位之后会不会下标越界，由调用它的函数处理这一问题
//位移时含首不含尾
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
	//offset==0直接跳过
	return 0;
}

//index从0起,-1插入末尾
int List_Insert(List const head, Element_Type const elem, int index)
{
	//检查下标
	if (index >= head->num + 1 || index < -1)
		return -1;
	//检查越界
	if (head->num >= head->max)
		return -1;
	//-1时，将插入的位置自动改为结尾
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

//传入一个规定对每个元素执行的操作的函数，在这个函数返回0时，会退出遍历
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
