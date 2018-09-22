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

	//标记[第几个\n]出现在第几个字符
	int mark1[100];
	int mark2[100];
	int countm1;
	int countm2;
	//标记countm1.2中最小值
	int minmark;
	//标记哪几行字数不同
	int mark3[100];
	int countm3;
	//标记哪几行内容不同
	int mark4[100];
	//标记检查到那行那个字符
	int countm4;
	//标记某行字符数
	int len;

	int error;
	char store;

	int count;

	temp1 = (char*)malloc(sizeof(char)*LEN);
	temp2 = (char*)malloc(sizeof(char)*LEN);

	{
		printf("输入第一段文本（以 | 标志文本结束）:\n");
		while ((store = getchar()) != '|')
		{
			temp1[count1 - 1] = store;
			count1++;
		}
		count1 -= 1;//将count恢复为数组总长度备用

		getchar();//消耗掉前面传递下来的一个换行符

		printf("输入第二段文本（以 | 标志文本结束）:\n");
		while ((store = getchar()) != '|')
		{
			temp2[count2 - 1] = store;
			count2++;
		}
		count2 -= 1;

		getchar();


		//输入确认，以后可以删去
		printf("获得的第一段文本为:\n");
		for (count = 0; count < count1; count++)
			putchar(temp1[count]);
		putchar('\n');
		printf("获得的第二段文本为:\n");
		for (count = 0; count < count2; count++)
			putchar(temp2[count]);
		putchar('\n');

	}


	printf("换行标志计数:\n");

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
		printf("两文本总行数不同，第%d行(含)之后部分将不会比较！\n", minmark);

	//寻找字数错误行
	printf("存在字数差异(含内容差异)的行:\n");
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

	//寻找内容错误行
	printf("字数相同但存在内容差异的行:\n");
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