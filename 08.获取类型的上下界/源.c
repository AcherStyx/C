#include <stdio.h>
int main(void)
{
	short ashort = 0;
	short ashort_compare;
	int aint = 0;
	int aint_compare;
	long along = 0;
	long along_compare;
	char achar = 0;
	char achar_compare;
	int ok;
	

	ok = 0;
	while (ok == 0)
	{
		ashort += 1;
		if (ashort < 0)
			ok = 1;
	}
	ashort_compare = ashort - 1;
	printf("The upper bound of short is:%d\nThe lower bound of short is:%d\n", ashort_compare, ashort);

	ok = 0;
	while (ok == 0)
	{
		aint += 1;
		if (aint < 0)
			ok = 1;
	}
	aint_compare = aint - 1;
	printf("The upper bound of int is:%d\nThe lower bound of int is:%d\n", aint_compare, aint);

	ok = 0;
	while (ok == 0)
	{
		along += 1;
		if (along < 0)
			ok = 1;
	}
	along_compare = along - 1;
	printf("The upper bound of long is:%d\nThe lower bound of long is:%d\n", along_compare, along);

	ok = 0;
	while (ok == 0)
	{
		achar += 1;
		if (achar < 0)
			ok = 1;
	}
	achar_compare = aint - 1;
	printf("The upper bound of char is:%d\nThe lower bound of char is:%d\n", achar_compare, achar);

	return 0;
}