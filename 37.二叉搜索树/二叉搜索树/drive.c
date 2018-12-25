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
		printf("ѡ�����: ");
		scanf("%d", &mod);
		switch (mod)
		{
		case 1://���
			getitem(&input);
			Tree_AddItem(&head, input);
			printf("Done.\n");
			break;
		case 2://��ӡȫ����
			Tree_ShowAll(&head, showitem);
			break;
		case 3:
			getitem(&input);
			switch (Tree_BSearch(&head, &input))
			{
			case 1:
				printf("��Ŀ����.\n");
				break;
			case 0:
				printf("��Ŀ������.\n");
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
			printf("����Ҫɾ����ķ���: ");
			getitem(&input);
			Tree_DeleteItem(&head, input);
			printf("Done.\n");
			break;
		case 8:
			printf("����Ҫ���ҵķ���: ");
			scanf("%d", &input.grade);
			if (Tree_Search(&head, &input, gradeequal))
				showinfo(input);
			else
				printf("δ�ҵ��÷���\n");

		}
		
	}
	


	return 0;
}

