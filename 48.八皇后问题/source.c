#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int totalcount=0;

void place(int map[][8],int a,int b)
{
    map[a][b]=1;
}

void iremove(int map[][8],int a,int b)
{
    map[a][b]=0;
}

int abletoplace(int map[][8],int a,int b)
{
    for(int i=0;i<8;i++)
    {
        if((a-i>=0&&map[a-i][b]==1)||(a-i>=0&&b-i>=0&&map[a-i][b-i]==1)||(a-i>=0&&b+i<8&&map[a-i][b+i]==1))
            return 0;
    }
    return 1;
}

void showresult(int map[][8])
{
    for(int i=0;i<8;i++)
    {
        for(int ii=0;ii<8;ii++)
            printf("%d",map[i][ii]);
        putchar('\n');
    }
}

int solve(int map[][8],int a,int b)
{
    int nextcount=0;
    int i;

    if(a==-1)
    {
        for(i=0;i<8;i++)
            nextcount+=solve(map,0,i);
        return nextcount;
    }

    if(abletoplace(map,a,b)==1)
    {
        place(map,a,b);
        if(a==7)
        {
            totalcount++;
            printf("[%d]\n",totalcount);
            showresult(map);
            iremove(map,a,b);
            return 1;
        }
    }
    else
    {
        return 0;
    }
    
    for(i=0;i<8;i++)
        nextcount+=solve(map,a+1,i);

    iremove(map,a,b);
    return nextcount;
}

int main(void)
{
    int map[8][8]={0};
    printf("可能结果数量: %d\n",solve(map,-1,0));
    return 1;
}