#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Life game.h"
#include <time.h>

int main(void)
{
	long t;
	srand(time(NULL));
	LifeGame_CreateNewWorld();

	/*初始状态*/
	World[11][10] = 1;
	World[12][11] = 1;
	World[10][12] = 1;
	World[11][12] = 1;
	World[12][12] = 1;
	
	LifeGame_ShowWorld();
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
