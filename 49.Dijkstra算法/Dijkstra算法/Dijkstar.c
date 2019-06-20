#include <stdio.h>
#include <stdlib.h>

#define M 5

int MAP[M][M] = { {1,4,2,0,0},\
{0,1,5,4,6},\
{1,0,2,0,1},\
{1,9,4,6,5},\
{1,2,5,6,3}
};

int Dijkstra(int map[][M], int a1, int b1, int a2, int b2);

int main(void)
{
	printf("%d",Dijkstra(MAP, 0, 0, 4, 4));
}


int Dijkstra(int map[][M], int a1, int b1, int a2, int b2)
{
	int history[M][M];
	int infty = 100000000;
	int temp[M][M];
	int current[2] = { a1,b1 };

	for (int i = 0; i < M; i++) for (int ii = 0; ii < M; ii++) temp[i][ii] = infty;

}