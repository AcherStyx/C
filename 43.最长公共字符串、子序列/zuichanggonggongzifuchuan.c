#include <stdio.h>
#include <string.h>
#define LEN 100
int MPS(char*,char*);
int max(int *,int);
int main(void)
{
	char str1[LEN],str2[LEN];
	int num;

	printf("STR1: ");
	scanf("%s",str1);
	printf("STR2: ");
	scanf("%s",str2);
	
	num=MPS(str1,str2);

	printf("%d",num);

	
	
	return 0;
}

int MPS(char str1[],char str2[])
{
	int graph[strlen(str1)][strlen(str2)];
	int len1=strlen(str1);
	int len2=strlen(str2);
	for(int i=0;i<len1;i++)
	{
		for(int ii=0;ii<len2;ii++)
		{
			if(str1[i]==str2[ii])
			{
				if(i==0||ii==0)
					graph[i][ii]=1;
				else
					graph[i][ii]=graph[i-1][ii-1]+1;
			}
			else
				graph[i][ii]=0;
		}
	}

	printf("graph:\n");
	printf(" %s\n",str2);
	for(int i=0;i<len1;i++)
	{
		printf("%c",str1[i]);
		for(int ii=0;ii<len2;ii++)
		{
			printf("%d",graph[i][ii]);
		}
		putchar('\n');
	}

	return max((int*)graph,len1*len2);
}

int max(int in[],int len)
{
	int temp=in[0];
	for(int i=1;i<len;i++)
		if(in[i]>temp)
			temp=in[i];
	return temp;
}

