#include <stdio.h>

int main(int argc, char *argv[])
{
	if (argc != 2) {
		printf("ERROR: You need one argument.\n");
		// this is how you abort a program
		return 1;
	}
	
	for (int i = 0; argv[1][i] != '\0'; i++) {
		char letter = argv[1][i];

		if (65 <= letter && letter <= 90) {
			printf("Uppercase %c removed!\n", letter);
			continue;
		}
		else if (97 <= letter && letter <= 122) {
			printf("Lowercase %c --convert-to-upper-->", letter);
			letter = letter - 32;
			printf(" %c ", letter);
		}

		switch (letter) {
			case 'a':
			case 'A':
				printf("%d: 'A'\n", i);
				break;

			case 'e':
			case 'E':
				printf("%d: 'E'\n", i);
				break;

			case 'i':
			case 'I':
				printf("%d: 'I'\n", i);
				break;

			case 'o':
			case 'O':
				printf("%d: O\n", i);
				break;

			case 'u':
			case 'U':
				printf("%d: 'U'\n", i);
				break;

			case '@': printf("email found!");

			default: printf("%d: %c is not a vowel\n", i, letter);
		}
	}
	
	return 0;
}
