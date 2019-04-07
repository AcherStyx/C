#include <stdio.h>
int main(void)
{
	int two = 1;
	long input;
	long output = 0;
	int count;
	long temp;

	int single;
	int ten = 10;

	scanf("%ld", &input);
	temp = input;
	for (count = 0; count < 8; count++)
	{
		single = (temp%ten) * 10 / ten;
		if ((count + 1) % 2 == single % 2 && temp != 0)
			output += two;

		temp -= single * ten / 10 ;
		ten *= 10;
		two *= 2;
	}
	
	printf("%ld", output);
	return 0;
}