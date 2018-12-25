#include <stdio.h>
#include <stdlib.h>
void quicksort(int a[], int low, int high);
void quicksort2(int a[], int len);
int slipt(int a[], int low, int high);
void swap(int *a, int *b);
int  main(void)
{
	int a[10] = { 10,11,15,48,654,213,12,1548,45,235 };
	int b[10] = { 10,11,15,48,654,213,12,1548,45,235 };
	for (int i = 0; i < 10; i++)
		printf("%d ", a[i]);
	putchar('\n');

	quicksort(a,0, 10);
	
	quicksort2(b, 10);

	for (int i = 0; i < 10; i++)
		printf("%d ", a[i]);
	putchar('\n');
	for (int i = 0; i < 10; i++)
		printf("%d ", b[i]);
	return 0;
}

void swap(int *a, int *b)
{
	int temp;
	if (*a < *b)
	{
		temp = *a;
		*a = *b;
		*b = temp;
	}
}

void quicksort(int a[], int low, int high)
{
	int mid;

	if (low == high)
		return;

	mid = slipt(a, low, high);

	quicksort(a, low, mid);
	quicksort(a, mid+1, high);
}

int slipt(int a[], int low, int high)
{
	int i;
	int pick;
	
	pick = a[high - 1];
	for (i = low; i < high; i++)
	{
		if (a[i] <= pick)
		{
			swap(&a[i], &a[low]);
			low++;
		}
	}

	return low - 1;
}

void quicksort2(int a[], int len)
{
	int i, ii;
	for (i = 1; i < len; i++)
	{
		for (ii = 1; ii < len - i; ii++)
		{
			swap(a + ii - 1, a + ii);
		}
	}
}