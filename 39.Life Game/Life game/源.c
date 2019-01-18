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

	/*³õÊ¼×´Ì¬*/
	World[11][10] = 1;
	World[12][11] = 1;
	World[10][12] = 1;
	World[11][12] = 1;
	World[12][12] = 1;
	
	LifeGame_ShowWorld();
	printf("%d", LifeGame_Environment(1, 1));
	getchar();

	for (int i = 0; i < 100; i++)
	{
		LifeGame_Refresh();
		LifeGame_ShowWorld();
		t=time(NULL);
		while(t==time(NULL))
			;
	}

	return 0;
}
