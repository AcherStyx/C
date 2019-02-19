#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 1000

int rotate(char * in, int len, int n);

int main(void)
{
	char temp[SIZE];
	int n;

	printf("I: ");
	scanf("%s", temp);
	printf("n: ");
	scanf("%d", &n);

	rotate(temp, strlen(temp), n);

	printf("O: %s",temp);

	return 0;
}

int rotate(char * in, int len, int n)
{
	char temp, temp2;
	if ((n > 0 && n > len) || (n < 0 && n < -len))
		n = n % len;
	if (n > (int)(len / 2))
		n = n - len;
	if (n > 0)
	{
		if (len%n != 0)
			rotate(in + len - n, n, n - len % n);
		for (int ii = 0; ii < n; ii++)
		{
			temp = in[len - 1 - ii];
			int count = 1;
			while (len - 1 - (count * n + ii) >= 0)
			{
				in[len - 1 - (n*(count - 1) + ii)] = in[len - 1 - (n*count + ii)];
				count++;
			}
			in[len - 1 - (n*(count - 1) + ii)] = temp;
		}
	}
	else if (n < 0)
	{
		n = -n;
		if (len%n != 0)
			rotate(in, n, len%n-n);
		for (int ii = 0; ii < n; ii++)
		{
			temp = in[ii];
			int count = 1;
			while (count*n + ii < len)
			{
				in[n*(count - 1) + ii] = in[n*count + ii];
				count++;
			}
			in[n*(count - 1) + ii] = temp;
		}
	}
}