#include <stdio.h>
#include <ctype.h>
#include <string.h>

// Function declaration style in C
// -----------------------------------------
// K&R syntax
int foo_1(a, p)
    int a;
    char *p;
{
    return 0;
}

// ANSI syntax
int foo_2(int a, char *p)
{
    return 0;
}
// -----------------------------------------

// Forward declarations
int can_print_it(char ch);
// void print_letters(char arg[]);
void print_letters(char arg[], int length);

// Impliment functions
void print_arguments(int argc, char *argv[])
{
	int i = 0;

	for (int i = 1; i < argc; i++) {
		// print_letters(argv[i]);
		print_letters(argv[i], strlen(argv[i]));
	}
}

// void print_letters(char arg[])
void print_letters(char arg[], int length)
{
	// for (int i = 0; arg[i] != '\0'; i++)
	for (int i = 0; i < length; i++)
	{
		char ch = arg[i];
		if (can_print_it(ch)) {
			printf("'%c' == %d ", ch, ch);
		}
	}
	printf("\n");
}

int can_print_it(char ch)
{
	return isalpha(ch) || isblank(ch);
}

int main(int argc, char *argv[])
{
	print_arguments(argc, argv);
	return 0;
}
