#include <stdio.h>
int main(void)
{
	int count;
	char in[8];
	int get = 0;
	char cache;
	int ok;
	int endmark;

	int bri01[7];//�����Ӧλ��0����1
	long bri[7] = { 1 };
	for (count = 0; count < (7 - 1); count++)
		bri[count + 1] = 2 * bri[count];

	long out;

	while (get != 1)
	{
		//�������
		printf("����һ��0~1000000֮������֣�");
		get = scanf("%s", in);

		//����ַ����Ƿ񳬳�����
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
			printf("��!��û����ȷ������һ��0~1000000֮�������\n");
			continue;
		}
		//�����û�в������ֵ�����
		count = 0;
		cache = in[count];
		do {
			if (cache<'0' || cache>'9')
			{
				get = 0;
			}
			if (get == 0)
			{
				printf("��!�������а��������ֳɷ�\n");
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
	printf("����ֵΪ %ld\n", out);
		
	return 0;
}
