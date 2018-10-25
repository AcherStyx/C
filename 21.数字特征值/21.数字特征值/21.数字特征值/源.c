#include <stdio.h>
int main(void)
{
	int count;
	char in[8];
	int get = 0;
	char cache;
	int ok;
	int endmark;

	int bri01[7];//计算对应位是0还是1
	long bri[7] = { 1 };
	for (count = 0; count < (7 - 1); count++)
		bri[count + 1] = 2 * bri[count];

	long out;

	while (get != 1)
	{
		//获得输入
		printf("输入一个0~1000000之间的数字：");
		get = scanf("%s", in);

		//检查字符串是否超出长度
		for (count = 0; count < 8; count++)
			if (in[count] == '\0')
			{
				ok = 1;
				endmark = count;
			}
		if (ok != 1)
			get = 0;
		cache = getchar();
		if (get == 0 || cache != '\n')
		{
			do {
				cache = getchar();
			} while (cache != '\n');

			get = 0;
			printf("【!】没有正确地输入一个0~1000000之间的数字\n");
			continue;
		}
		//检查有没有不是数字的输入
		count = 0;
		cache = in[count];
		do {
			if (cache<'0' || cache>'9')
			{
				get = 0;
			}
			if (get == 0)
			{
				printf("【!】输入中包含非数字成分\n");
				break;
			}
			count++;
			cache = in[count];

		} while (cache != '\0'&&count < 7);

	}

	for (count = 1; count <= endmark; count++)
	{
		if ((count % 2) == (in[endmark - count] % 2))
			bri01[count - 1] = 1;
		else
			bri01[count - 1] = 0;
	}

	for (count = 0, out = 0; count < endmark; count++)
	{
		out += bri[count] * bri01[count];
	}
	printf("特征值为 %ld\n", out);
		
	return 0;
}
