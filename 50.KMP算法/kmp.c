#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct string
{
	char* root;
	int len;
}String;

bool isequal(char* a, char* b, int len)
{
	for (int i = 0; i < len; i++)
	{
		if (a[i] != b[i])
			return false;
	}
	return true;
}

void next_pos(char* T, int* next,int length)
{
	next[0] = -1;
	int p, q;
	for (int i = 1; i < length ; i++)
	{
		for (int ii = 0; ii < i; ii++)
		{
			if (isequal(T, T + i - ii, ii))
				next[i] = ii;
		}
	}
}

void next_pos_2(char* T,int* next, int len)
{
	int j = 0;	//当前匹配到了那个字符
	int k = -1;	//前面一段字符可以和开头匹配的字符数量
	next[0] = -1;
	while (j < len)
	{
		if (k == -1 || T[j] == T[k])
		{
			k++;
			j++;
			next[j] = k;
		}
		else
			k = next[k];
	}
}

void next_pos_3(char* T, int* next, int len)
{
	int j = 0;	//当前匹配到了那个字符
	int k = -1;	//前面一段字符可以和开头匹配的字符数量
	next[0] = -1;
	while (j < len)
	{
		if (k == -1 || T[j] == T[k])
		{
			k++;
			j++;
//			next[j] = k;
			if (T[k] != T[j])	//代表回溯回去的那项和当前的项不相等的时候
				next[j] = k;
			else
				next[j] = next[k];	//往上回溯直到不同
		}
		else
			k = next[k];
	}
}

#define SHOW_NEXT

int KMP(String S, String T, int pos)
{
	int i = 0, j = 0;
	int* next = (int*)malloc(sizeof(int) * T.len);
	if (next == NULL)
		return -1;

	next_pos_3(T.root, next, T.len);

#ifdef SHOW_NEXT
	for (i = 0; i < T.len; i++)
	{
		printf("  %c ", T.root[i]);
	}
	putchar('\n');
	for (i = 0; i < T.len; i++)
	{
		printf("%3d ",next[i]);
	}
	putchar('\n');
#endif
	
	
	i = j = 0;
	while (i < S.len && j < T.len)
	{
		if (j == -1 || S.root[i] == T.root[j])
		{
			i++;
			j++;
		}
		else
		{
			j = next[j];
		}
	}

	if (j >= T.len)
		return i - T.len;
	else
		return -1;
}

int main(void)
{
	char temp[1000];
	int result;

	if (!freopen("./data.txt", "r", stdin))
		return -1;

	String T;
	String S;

	scanf("%s", temp);
	S.len = strlen(temp);
	S.root = (char*)malloc(sizeof(char) * (S.len));
	strcpy(S.root, temp);
	printf("目标串: %s\n", temp);
	scanf("%s", temp);
	T.len = strlen(temp);
	T.root = (char*)malloc(sizeof(char) * (T.len));
	strcpy(T.root, temp);
	printf("模式串: %s\n", temp);


	result=KMP(S, T, 0);
	
	printf("%d", result);

	return 0;
}