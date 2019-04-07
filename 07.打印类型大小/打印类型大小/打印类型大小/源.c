#include <stdio.h>
int main(void)
{
	printf("On this system:\nThe size of char is %u bytes\nThe size of int is %u bytes\nThe size of long is %u bytes\nThe size of long long is %u bytes", sizeof(char), sizeof(int), sizeof(long), sizeof(long long));
	printf("\nThe size of unsigned int is %u bytes", sizeof(unsigned int));
	printf("\nThe size of float is %u bytes", sizeof(float));
	printf("\nThe size of double is %u bytes", sizeof(double));
	return 0;
}