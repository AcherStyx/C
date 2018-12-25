#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include "tree.h"
#include "tools.h"

int main(void)
{
	Tree head;
	int mod;
	Item input;

	srand((unsigned int)time(NULL));

	Tree_Initializing(&head, cmp);

	while (1)
	{
		showmenue();
		printf("选择操作: ");
		scanf("%d", &mod);
		switch (mod)
		{
		case 1://添加
			getitem(&input);
			Tree_AddItem(&head, input);
			printf("Done.\n");
			break;
		case 2://打印全队列
			Tree_ShowAll(&head, showitem);
			break;
		case 3:
			getitem(&input);
			switch (Tree_BSearch(&head, &input))
			{
			case 1:
				printf("项目存在.\n");
				break;
			case 0:
				printf("项目不存在.\n");
				break;
			}
			break;
		case 4:
			Tree_Traverse(&head, minus);
			printf("Done.\n");
			break;
		case 5:
			for (int i = 0; i <5; i++)
			{
				for (int i = 0; i < 5; i++)
				{
					input.name[i] = randdata('a', 'z');
				}
				input.name[5] = '\0';
				input.grade = randdata(0, 100);
				Tree_AddItem(&head, input);
			}
			

			printf("Done.\n");
			break;
		case 6:
			Tree_DeleteAll(&head);
			break;
		case 7:
			printf("输入要删除项的分数: ");
			getitem(&input);
			Tree_DeleteItem(&head, input);
			printf("Done.\n");
			break;
		case 8:
			printf("输入要查找的分数: ");
			scanf("%d", &input.grade);
			if (Tree_Search(&head, &input, gradeequal))
				showinfo(input);
			else
				printf("未找到该分数\n");

		}
		
	}
	


	return 0;
}

