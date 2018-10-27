#include <stdio.h>
#include <string.h>
#define STL 20
void srt(char * in, const int n);
int main(void)
{
	int mod;

	char *ran[STL];
	char str[STL][20];

	int i;

	printf("输入%d条字符串，每条字符串以换行符结尾：\n", STL);

	/*
	测试数据：
	fadfasdfasdf gdsfgd1
	eqwfregds fds dfgdf2
	gergertgber fgg3
	fsdgferhgs4
	fhndbra5
	egrtyb6
	grufdsa7
	hnhgjtyrrys8
	fgfnfhd9
	fhtretgrfv10
	ergdfger11
	etrer12
	rhtyr13
	rht14
	hrth15
	resfgsege16
	kyghjf17
	ghfjyrd18
	gfxhdf19
	jgdd20
	*/


	i = 0;
	while (i < 20 && gets(str[i]) != NULL)
		i++;

	for (i = 0; i < STL; i++)
		ran[i] = str[i];

	srt(ran, STL);

	printf("排序后结果：\n");
	for (i = 0; i < STL; i++)
	{
		printf("%s\n", ran[i]);
	}


	return 0;
}

void srt(char ** in, const int n)
{
	int i;
	int ii;
	char * temp;

	for(i=0;i<n-1;i++)
		for (ii = i + 1; ii < n; ii++)
		{
			if (strcmp(in[i], in[ii]) > 0)
			{
				temp = in[i];
				in[i] = in[ii];
				in[ii] = temp;
			}
		}

}