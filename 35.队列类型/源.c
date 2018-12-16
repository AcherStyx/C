#include <stdio.h>
#include "queue.h"

#define NDEBUG

int main(void)
{
	Queue head;
	Item input;
	int mode = 1;
	FILE *data;

	printf("=====����=====\n");
	Queue_initializing(&head);

	data = fopen("queuedata", "a+b");

	do
	{
		printf("ѡ�����:\n");
		printf("1)����� 2)ɾ���� 3)��ն��� 4)Ԫ����Ŀ 5)��ӡ�������� 6)������ļ� 7)���ļ����� 0)�˳�\n");
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
		case 6:
			Queue_savetofile(&head, data);
			printf("Done.\n");
			rewind(data);
			break;
		case 7:
			Queue_readfromfile(&head, data);
			printf("Done.\n");
			rewind(data);
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

