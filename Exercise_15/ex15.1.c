#include <stdio.h>

int main(int argc, char *argv[])
{
	// create to arrays we care about
	int ages[] = { 23, 43, 12, 89, 2 };
	char *names[] = { "Alen", "Frank", "Mary", "John", "Lisa" };

	// safely get the size of ages
	int count = sizeof(ages) / sizeof(int);

	// first way using indexing
	for (int i = 0; i < count; i++) {
		printf("%s has %d years alive. \n", names[i], ages[i]);
	}

	printf("----\n");

	int *ptr = &ages[0];
	printf("address ptr0 = %p, ptr0 = %d\n", ptr, *ptr);
	for (int i = 1; i < count; i++) {
		printf("address ptr%d = %p, ptr%d = %d\n", i, &ages[i], i, ages[i]);
	}

	printf("----\n");

	for (int i = 0; i < count; i++) {
		printf("address ptr%d = %p, ptr%d = %d\n", i, &ptr, i, *ptr);
		++ptr;
	}

	printf("----\n");
	
	char **cptr = names;
	printf("address names = %p\naddress cptr = %p, cptr = %s, First_letter = %c\n", names, &cptr, *cptr, **cptr);
	printf("%c %c %c %c\n", *(*cptr + 0), *(*cptr + 1), *(*cptr + 2), *(*cptr + 3)); // *(*cptr + 0) = **cptr

	for (int i = 0; i < count; i++) {
		printf("address %s = %p\n", *(cptr + i), cptr + i);
		char *name = *(cptr + i);
		for (int j = 0; *(name + j) != '\0'; j++) {
			printf("address %c = %p\n", *(name + j), name + j);
		}
		printf("----\n");
	}

	return 0;
}
