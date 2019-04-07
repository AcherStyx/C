#include <stdio.h>
#include "List.h"
#define _CRT_SECURE_NO_DEPRECATE

int main(void)
{
	List head = NULL;
	Item temp = {
		"debug",
		10
	};

	char name[50];
	int rank;

	List_initializing(&head);

	for (int i = 0; i < 90000; i++)
	{
		

		List_addnode(&head, temp);
	}

	List_free(&head);

	scanf("%d");

	return 0;
}