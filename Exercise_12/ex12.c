#include <stdio.h>

int main(int *argc, char *argv[])
{
	int areas[] = { 10, 12, 13, 14, 20 };
	int years[] = { 1998, 2000, 1991 };
	char name[] = "Zed";
	char *myname = "Mehrdad";
	char full_name[] = {
		'Z', 'e', 'd',
		' ', 'A', '.', ' ',
		'S', 'h', 'a', 'w', '\0'
	};

	/* Warning: On some systems you may have to change the
	%ld in this code to a %u since it will use unsigned ints */

	printf("The size of an int: %ld\n", sizeof(int));
	printf("The size of areas (int[]): %ld\n", sizeof(areas));
	printf("The number of ints in areas: %ld\n", sizeof(areas) / sizeof(int));
	printf("The first area is %d, the 2nd %d.\n", areas[0], areas[1]);
	printf("The size of a char: %ld\n", sizeof(char));
	printf("The size of name (char[]): %ld\n", sizeof(name));
	printf("The number of chars: %ld\n", sizeof(name) / sizeof(full_name));
	printf("The size of full_name (char[]): %ld\n", sizeof(full_name));
	printf("The number of chars: %ld\n", sizeof(full_name) / sizeof(char));
	printf("name=\"%s\" and full_name=\"%s\"\n", name, full_name);
	printf("myname=\"%s\"\n", myname);
	printf("The 10th area is %d\n", areas[10]);
	printf("Years are: %d %d %d\n", years[0], years[1], years[2]);
	return 0;
}
