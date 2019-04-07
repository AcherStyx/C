#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Life game.h"
#include <time.h>

int main(void)
{
	long t;
	int seed;

	printf("Enter seed:");

	if (scanf("%d", &seed))
	{
		getchar();
		LifeGame_SetRand(seed);
	}
	else
	{
		return -1;
	}


	LifeGame_CreateNewWorld();

	LifeGame_ShowWorld();
	printf("No. 0\n");
	getchar();

	for (int i = 0; i < 10000; i++)
	{
		LifeGame_Refresh();
		LifeGame_ShowWorld();
		/*此处是每隔一秒输出一次的代码		
		t=time(NULL);
		while(t==time(NULL))
			;*/
		getchar();
	}

	return 0;
}
