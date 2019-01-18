#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define ROW 25
#define COL 25

int num_count;
bool (*World)[COL];

void LifeGame_ShowWorld(void)
{
	int i, ii;
	putchar('+');

	for (i = 0; i < COL; i++)
		putchar('-');
	putchar('+');
	putchar('\n');

	for (ii = 0; ii < ROW; ii++)
	{
		putchar('|');

		for (i = 0; i < COL; i++)
		{
			if(World[ii][i]==0)
				putchar(' ');
			else
				putchar('+');
		}
		
		putchar('|');
		putchar('\n');
	}

	putchar('+');
	for (i = 0; i < COL; i++)
		putchar('-');
	putchar('+');
	putchar('\n');

	if(num_count!=0)
		printf("No. %d\n",num_count);
	num_count++;
}

void LifeGame_CreateNewWorld(void)
{
	World = malloc(sizeof(bool)*COL*ROW);
	for (int ii = 0; ii < ROW; ii++)
		for (int i = 0; i < COL; i++)
			World[ii][i] = 0;
}

static int LifeGame_Environment(int row,int col)
{
	bool temp[3][3];

	if(row==0)
	{
		temp[0][0]=temp[0][1]=temp[0][2]=0;
		if(col==0)
		{
			temp[0][0] = temp[1][0] = temp[2][0] = 0;
			temp[2][1]=World[row+1][col];
			temp[2][2]=World[row+1][col+1];
			temp[1][2]=World[row][col+1];
		}
		else if(col==COL-1)
		{
			temp[0][2] = temp[1][2] = temp[2][2] = 0;
			temp[1][0] = World[row][col - 1];
			temp[2][0] = World[row + 1][col - 1];
			temp[2][1] = World[row + 1][col];
		}
		else
		{
			temp[1][0]=World[ROW][COL-1];
			temp[2][0]=World[ROW+1][COL-1];
			temp[2][1]=World[ROW+1][COL];
			temp[2][2]=World[ROW+1][COL+1];
			temp[1][2]=World[ROW][COL+1];
		}
	}
	else if(row==ROW-1)
	{
		temp[2][0] = temp[2][1] = temp[2][2] = 0;
		if (col == 0)
		{
			temp[2][0]=temp[1][0]=temp[0][0]=0;
			temp[0][1]=World[row-1][col];
			temp[0][2]=World[row-1][col+1];
			temp[1][2]=World[row][col+1];
		}
		else if (col == COL - 1)
		{
			temp[2][2]=temp[1][2]=temp[0][2]=0;
			temp[0][0]=World[row-1][col-1];
			temp[1][0]=World[row][col-1];
			temp[0][1]=World[row-1][col];
		}
		else{
			temp[1][0]=World[row][col-1];
			temp[0][0]=World[row-1][col-1];
			temp[0][1]=World[row-1][col];
			temp[0][2]=World[row-1][col+1];
			temp[1][2]=World[row][col+1];
		}
	}
	else if (col == 0)
	{
		temp[2][0] = temp[1][0] = temp[0][0] = 0;
		temp[0][1] = World[row - 1][col];
		temp[0][2] = World[row - 1][col + 1];
		temp[1][2] = World[row][col + 1];
		temp[2][1] = World[row + 1][col];
		temp[2][2] = World[row + 1][col + 1];
	}
	else if (col == COL - 1)
	{
		temp[2][2] = temp[1][2] = temp[0][2] = 0;
		temp[0][0] = World[row - 1][col - 1];
		temp[1][0] = World[row][col - 1];
		temp[2][0] = World[row + 1][col - 1];
		temp[0][1] = World[row - 1][col];
		temp[2][1] = World[row + 1][col];
	}
	else
	{
		temp[0][0] = World[row - 1][col - 1];
		temp[1][0] = World[row][col - 1];
		temp[2][0] = World[row + 1][col - 1];
		temp[0][1] = World[row - 1][col];
		temp[2][1] = World[row + 1][col];
		temp[0][2] = World[row - 1][col + 1];
		temp[1][2] = World[row][col + 1];
		temp[2][2] = World[row + 1][col + 1];
	}

	return temp[0][0] + temp[0][1] + temp[0][2] + temp[1][0] + temp[1][2] + temp[2][0] + temp[2][1] + temp[2][2];
}

void LifeGame_Refresh(void)
{
	int i,ii;
	int mode;
	bool (* World2)[COL];

	World2 = malloc(sizeof(bool)*COL*ROW);

	for(ii=0;ii<ROW;ii++)
	{
		for (i = 0; i < COL; i++)
		{
			mode = LifeGame_Environment(ii, i);
			switch (mode)
			{
			case 1:
				World2[ii][i] = 0;
				break;
			case 2:
				World2[ii][i] = World[ii][i];
				break;
			case 3:
				World2[ii][i] = 1;
				break;
			default:
				World2[ii][i] = 0;
			}
		}
	}

	free(World);
	World = World2;

}