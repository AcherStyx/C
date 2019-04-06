#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int migong[][10] = {
{1,1,1,1,1,1,1,1,1,1},
{1,0,0,1,0,0,0,1,0,1},
{1,0,0,1,0,0,0,1,0,1},
{1,0,0,0,0,1,1,0,0,1},
{1,0,1,1,1,0,0,0,0,1},
{1,0,0,0,1,0,0,0,0,1},
{1,0,1,0,0,0,1,0,0,1},
{1,0,1,1,1,0,1,1,0,1},
{1,1,0,0,0,0,0,0,0,1},
{1,1,1,1,1,1,1,1,1,1}
};

int way[10000][2];
int index = -1;

bool solve(int migong[][10], int a, int b);

int main(void)
{
	solve(migong, 1, 1);
	for (int i = 0; i <= index; i++)
	{
		printf("(%d,%d)", way[i][0], way[i][1]);
	}
	return 1;
}

bool solve(int migong[][10], int a, int b)
{
	if (a == 8 && b == 8)
		return 1;
	if (migong[a][b] == 1)
	{
		return 0;
	}

	index++;
	migong[a][b] = 1; //标记过去的路径
	way[index][0] = a;
	way[index][1] = b;

	int check = 0;

	check += solve(migong, a - 1, b);
	check += solve(migong, a, b - 1);
	check += solve(migong, a, b + 1);
	check += solve(migong, a + 1, b);
	if (check == 0)
	{
		index--;
		migong[a][b] = 1;
		return 0;
	}

	return 1;
}