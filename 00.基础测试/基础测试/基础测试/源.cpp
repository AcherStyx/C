#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct data
{
	char word;
	data *next;
	data *pre;

}data;

data *L;

void init(data *&L, char b[], int n)
{
	data **LL;
	LL = &L;
	*LL = (data*)malloc(sizeof(data));
	L->next = L->pre = NULL;
	
	for (int i = 0; i < n; i++)
	{
		(*LL)->word = b[i];
		if (i == 0)
			(*LL)->pre = NULL;

		(*LL)->next= (data*)malloc(sizeof(data));
		LL = &((*LL)->next);
	}
	free(*LL);
	(*LL) = NULL;
}

int readline(char b[])
{
	int i = 0;
	char m;
	scanf("%s", b);
	i = strlen(b);
	return i;

}

void print(data *&L)
{
	data *LLL;

	LLL = L;
	for (; LLL != NULL; LLL = LLL->next)
	{
		printf("%c", LLL->word);
	}
}
int main(void)
{
	char b[10];
	int length;

	length = readline(b);
	init(L, b, length);
	print(L);


	return 0;
}
