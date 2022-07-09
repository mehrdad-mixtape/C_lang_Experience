#include <stdio.h>

int main()
{
	int age = 23;
	int height = 170 / 2.5;
	int *pointer = 10;

	printf("I am %d years old.\n", age);
	printf("I am %d inches tall.\n", height); // %d print an signed int
	printf("I am %x years old.\n", age); // %x print an int in hexadecimal
	printf("I am %u inches tall.\n", height); // %u print an unsigned int
	printf("This is pointer variable %p in hex and This is %p address memory of pointer.\n", pointer, &pointer); // %p print print a pointer

	return 0;
}

