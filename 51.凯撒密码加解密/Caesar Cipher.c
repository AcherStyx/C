#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

void Encryption(char* plaintext,int shift)
{
	int i;

	for (i = 0; i < 10000; i++)
	{
		if (plaintext[i] != '\0')
		{
			if (plaintext[i] >= 'A' && plaintext[i] <= 'Z')
			{
				plaintext[i] += shift;
				while (true)
				{
					if (plaintext[i] > 'Z')
						plaintext[i] -= 26;
					else if (plaintext[i] < 'A')
						plaintext[i] += 26;
					else
						break;
				}
			}
			else if (plaintext[i] >= 'a' && plaintext[i] <= 'z')
			{
				plaintext[i] += shift;
				while (true)
				{
					if (plaintext[i] > 'z')
						plaintext[i] -= 26;
					else if (plaintext[i] < 'a')
						plaintext[i] += 26;
					else
						break;
				}
			}
			else
				continue;
		}
		else
			break;
	}
}

int main(void)
{
	char mode;
	char plaintext[10000];
	int shift;

	while (true)
	{
		printf("Chose: 1.Encryption\n       2.Decryption\n       other.Exit\n>>> ");
		
		if (scanf("%d", &mode) == 1)
			while (getchar() != '\n')
				;
		else
			return -1;

		switch (mode)
		{
		case 1:
			printf("Enter message to be encrypted: ");
			fgets(plaintext, 10000, stdin);
			printf("Enter shift amount (1-25): ");
			if (scanf("%d", &shift) == 1)
				while (getchar() != '\n')
					;
			else
				return -1;

			Encryption(plaintext, shift);

			printf("Encrypted message: %s\n", plaintext);
			break;
		case 2:
			printf("Enter encrypted message: ");
			fgets(plaintext, 10000, stdin);
			printf("Enter shift amount (1-25): ");
			if (scanf("%d", &shift) == 1)
				while (getchar() != '\n')
					;
			else
				return -1;

			Encryption(plaintext, -shift);

			printf("Original message: %s\n", plaintext);
			break;
		default:
			return 0;
		}
	}

	return 0;
}