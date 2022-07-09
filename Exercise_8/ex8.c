#include <stdio.h>

int main(int argc, char *argv[])
{
	int i = 0;
	char name[] = "Patrik";
	if (argc == 1) {
		printf("You only have one argument. You suck.\n");
	} else if (argc > 1 && argc < 3) {
		printf("(i)Here's your arguments: \n");
		
		for (i = 1; i < argc; i++) {
			printf("%s ", argv[i]);
		}
		printf("\n");
	} else if (argc > 1 || argc < 5) {
		printf("(j)Here's your arguments: \n");
		
		for (int j = 1; j < argc; j++) {
			printf("%s ", argv[j]);
		}
		printf("\n");
	} else {
		printf("You have too many arguments. You are such an asshole %s.\n", name);
	}

	return 0;
}

