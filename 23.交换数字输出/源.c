#include <stdio.h>
#include <stdlib.h>
void exchange(int *a, int *b);
int main(void)
{
	int count;
	
	int tcount;
	int time;

	int info[3];
	int len;
	int *in;

	scanf("%d", &time);

	for (tcount = 0; tcount < time; tcount++)
	{
		scanf("%d %d %d", info, info + 1, info + 2);

		in = (int*)malloc(sizeof(int)*info[0]);

		for (count = 0; count < info[0]; count++)
			scanf("%d", in + count);

		exchange(in + info[1] - 1, in + info[2] - 1);

		for (count = 0; count < info[0]; count++)
			printf("%d ", in[count]);

		putchar('\n');
	}

	return 0;
}

void exchange(int *a, int *b)
{
	int temp;
	temp = *b;
	*b = *a;
	*a = temp;
}