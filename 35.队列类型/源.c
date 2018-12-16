#include <stdio.h>
#include "queue.h"

#define NDEBUG

int main(void)
{
	Queue head;
	Item input;
	int mode = 1;
	FILE *data;

	printf("=====队列=====\n");
	Queue_initializing(&head);

	data = fopen("queuedata", "a+b");

	do
	{
		printf("选择操作:\n");
		printf("1)添加项 2)删除项 3)清空队列 4)元素数目 5)打印整个队列 6)输出到文件 7)从文件输入 0)退出\n");
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
				printf("错误选项\n");
			}
			break;
		}

		printf("============\n");
	} while (mode != 0);

	
	

	return 0;
}

