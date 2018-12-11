#include <stdio.h>
#include "queue.h"


int main(void)
{
	Queue head;
	Item input;
	int mode = 1;
	
	printf("=====����=====\n");
	Queue_initializing(&head);

	do
	{
		printf("ѡ�����:\n");
		printf("1)����� 2)ɾ���� 3)��ն��� 4)Ԫ����Ŀ 5)��ӡ�������� 0)�˳�\n");
		printf("ѡ��:");
		scanf("%d", &mode);
		putchar('\n');
		switch (mode)
		{
		case 1:
			Queue_getitem(&input);
			Queue_enqueue(&head, input);
			printf("Done.\n");
			break;
		case 2:
			Queue_dequeue(&head, &input);
			Queue_showitem(input);
			printf("Done.\n");
			break;
		case 3:
			Queue_clean(&head);
			break;
		case 4:
			printf("��Ŀ:%d\n", Queue_items(&head));
			printf("Done.\n");
			break;
		case 5:
			Queue_showall(&head);
			printf("Done.\n");
			break;
		default:
			if (mode != 0)
			{
				printf("����ѡ��\n");
			}
			break;
		}

		printf("============\n");

	} while (mode != 0);

	
	

	return 0;
}

