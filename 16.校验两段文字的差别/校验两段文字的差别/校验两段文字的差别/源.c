#include <stdio.h>
#include <stdlib.h>
#define LEN 10000
#define LEN 10000
int Min(int a, int b);
int main(void)
{
	float sim_word;
	float sim_word_num;

	char *temp1;
	int count1 = 1;
	char *temp2;
	int count2 = 1;

	//���[�ڼ���\n]�����ڵڼ����ַ�
	int mark1[100];
	int mark2[100];
	int countm1;
	int countm2;
	//���countm1.2����Сֵ
	int minmark;
	//����ļ���������ͬ
	int mark3[100];
	int countm3;
	//����ļ������ݲ�ͬ
	int mark4[100];
	//��Ǽ�鵽�����Ǹ��ַ�
	int countm4;
	//���ĳ���ַ���
	int len;

	int error;
	char store;

	int count;

	temp1 = (char*)malloc(sizeof(char)*LEN);
	temp2 = (char*)malloc(sizeof(char)*LEN);

	{
		printf("�����һ���ı����� | ��־�ı�������:\n");
		while ((store = getchar()) != '|')
		{
			temp1[count1 - 1] = store;
			count1++;
		}
		count1 -= 1;//��count�ָ�Ϊ�����ܳ��ȱ���

		getchar();//���ĵ�ǰ�洫��������һ�����з�

		printf("����ڶ����ı����� | ��־�ı�������:\n");
		while ((store = getchar()) != '|')
		{
			temp2[count2 - 1] = store;
			count2++;
		}
		count2 -= 1;

		getchar();


		//����ȷ�ϣ��Ժ����ɾȥ
		printf("��õĵ�һ���ı�Ϊ:\n");
		for (count = 0; count < count1; count++)
			putchar(temp1[count]);
		putchar('\n');
		printf("��õĵڶ����ı�Ϊ:\n");
		for (count = 0; count < count2; count++)
			putchar(temp2[count]);
		putchar('\n');

	}


	printf("���б�־����:\n");

	mark1[0] = 0;
	countm1 = 1;
	for (count = 0 ; count < count1; count++)
	{
		if (temp1[count] == '\n')
		{
			mark1[countm1] = count;
			countm1++;
		}
	}

	//test
	for (count = 0; count < countm1; count++)
		printf("%5d", mark1[count]);
	putchar('\n');

	mark2[0] = 0;
	countm2 = 1;
	for (count = 0; count < count2; count++)
	{
		if (temp2[count] == '\n')
		{
			mark2[countm2] = count;
			countm2++;
		}
	}

	//test
	for (count = 0; count < countm2; count++)
		printf("%5d", mark2[count]);
	putchar('\n');

	if (countm1 != countm2)
		printf("���ı���������ͬ����%d��(��)֮�󲿷ֽ�����Ƚϣ�\n", minmark);

	//Ѱ������������
	printf("������������(�����ݲ���)����:\n");
	minmark = Min(countm1, countm2);
	countm3 = 0;
	for (count = 0; count < (minmark - 1); count++)
	{
		if ((mark1[count + 1] - mark1[count]) != (mark2[count + 1] - mark2[count]))
		{
			mark3[countm3] = count;
			countm3++;
		}
	}
	for (count = 0; count < countm3; count++)
		printf("%d\n", mark3[count] + 1);

	//Ѱ�����ݴ�����
	printf("������ͬ���������ݲ������:\n");
	minmark = Min(countm1, countm2);
	countm3 = 0;
	for (count = 0; count < (minmark - 1); count++)
	{
		if ((mark1[count + 1] - mark1[count]) == (mark2[count + 1] - mark2[count]))
		{
			len = mark1[count + 1] - mark1[count] - 1;
			error = 0;
			for (countm4 = 0; countm4 < len; countm4++)
			{
				if (temp1[mark1[count] + countm4] != temp2[mark2[count] + countm4])
					error = 1;
			}
			if (error != 0)
			{
				mark4[countm3] = count;
				countm3++;
			}
		}
	}
	for (count = 0; count < countm3; count++)
		printf("%d\n", mark4[count] + 1);



	return 0;
}

int Min(int a, int b)
{
	return (a > b) ? b : a;
}