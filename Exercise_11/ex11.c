#include <stdio.h>

int main(int *argc, char *argv[])
{
	int numbers[4] = { 0 };
	char name[4] = { 'm' };

	// first, print them out raw
	printf("numbers: %d %d %d %d\n", numbers[0], numbers[1], numbers[2], numbers[3]);
	printf("name each: %c %c %c %c\n", name[0], name[1], name[2], name[3]);

	printf("name: %s\n", name);

	// set up the numbers
	numbers[0] = 1;
	numbers[1] = 2;
	numbers[2] = 3;
	numbers[3] = 4;

	// set up the name
	name[0] = 'z';
	name[1] = 'e';
	name[2] = 'd';
	name[3] = '\0'; // so so important to insert \0 in end if string

	// then print them out initialized
	printf("numbers: %d %d %d %d\n", numbers[0], numbers[1], numbers[2], numbers[3]);
	printf("name each: %c %c %c %c\n", name[0], name[1], name[2], name[3]);

	// print name like a string
	printf("name: %s\n", name);

	// another way to use name
	char *another = "Zed";

	printf("another: %s\n", another);

	printf("another each: %c %c %c %c\n", another[0], another[1], another[2], another[3]);

	numbers[0] = 'm'; // convert char to int, ASCII code m = 109
	numbers[4] = 'k';
	name[0] = 109; // convert int to char, ASCII code m = 109
	name[3] = 73;
	name[4] = '\0';
	
	printf("numbers: %d %c %d %s\n", numbers[0], name[0], numbers[4], name);

	return 0;
}
