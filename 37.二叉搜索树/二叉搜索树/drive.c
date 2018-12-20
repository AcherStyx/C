#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "tree.h"
#include "tools.h"

int main(void)
{
	Tree head;
	int mod;
	Item input;

	Tree_Initializing(&head, cmp);

	while (1)
	{
		printf("选择操作: \n");
		scanf("%d", &mod);
		switch (mod)
		{
		case 1://添加
			getitem(&input);
			Tree_AddItem(&head, input);
			printf("Done.\n");
			break;
		case 2://打印全队列

			break;
	
		}
		
	}
	


	return 0;
}

