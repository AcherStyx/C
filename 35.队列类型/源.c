#include <stdio.h>
#include "queue.h"


int main(void)
{
	Queue head;
	Item input;
	int mode = 1;
	
	printf("=====队列=====\n");
	Queue_initializing(&head);

	do
	{
		printf("选择操作:\n");
		printf("1)添加项 2)删除项 3)清空队列 4)元素数目 5)打印整个队列 0)退出\n");
		printf("选择:");
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
			printf("数目:%d\n", Queue_items(&head));
			printf("Done.\n");
			break;
		case 5:
			Queue_showall(&head);
			printf("Done.\n");
			break;
		default:
			if (mode != 0)
			{
				printf("错误选项\n");
			}
			break;
		}

		printf("============\n");

	} while (mode != 0);

	
	

	return 0;
}

