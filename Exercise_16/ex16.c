#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

struct Person {
	char *name;
	int age;
	float height;
	int weight;
}; // declare a struct without VARIABLE_NAME
// you can use a struct like a data type!

struct Person *Person_create(char *name, int age, float height, int weight)
{
	struct Person *who = malloc(sizeof(struct Person));
	// malloc(): ask the OS to give me a piece of raw memory.
	// create a struct with pointer!
	assert(who != NULL);
	// assert(): make sure that I have a valid piece of memory.
	
	// get value to fields of struct with '->', why? because you make your struct with pointer.
	who->name = strdup(name);
	// strdup(): make copies the original string into name.
	who->age = age;
	who->height = height;
	who->weight = weight;

	return who;
} // this is a function that declare like a pointer!
// because this function return a pointer too.
/* are you remember it?
 * TYPE FUNK-NAME(ARG1, ARG2, ...)
 * {
 *		CODE;
 *		return VALUE;
 * }
 * TYPE: struct Person
 * FUNC-NAME: *Person_create
 * ARG1: char *name
 * ARG2: int age
 * ARG3: float height
 * ARG4: int weight
 * CODE: ...
 * VALUE: who => struct pointer
*/

void Person_destroy(struct Person *who)
{
	assert(who != NULL);
	free(who->name);
	// free(): release the memory got with malloc(),
	// why should I free the 'name field'? because of strdup() and prevent from memory leak.
	free(who);
	// free all fields of struct
}

void Person_print(struct Person *who)
{
	printf("----\nName: %s\nAge: %d\nHeight: %f\nWeight: %d\n",
				who->name, who->age, who->height, who->weight);
	// you have 2 way to access to fields of struct:
	// x->y : when you declare your struct with pointer
	// x.y : when you declare your struct without pointer
}

int main(int argc, char *argv[])
{
	// make two people structures
	struct Person *joe = Person_create("Joe Alex", 32, 180.2, 90);
	struct Person *frank = Person_create("Frank Blank", 20, 173.4, 68);
	// print them out and where they are in memory
	printf("----\nJoe is at memory location %p:\n", joe);
	Person_print(joe);

	printf("----\nFrank is at memory location %p:\n", frank);
	Person_print(frank);

	// make everyone age 20 years and print them again
	joe->age += 20;
	joe->height -= 2;
	joe->weight += 40;
	Person_print(joe);

	frank->age += 20;
	frank->weight += 20;
	Person_print(frank);

	// destroy them both so we clean up
	Person_destroy(joe);
	Person_destroy(frank);

	printf("----\nJoe is at memory location %p:\n", joe);
	printf("----\nFrank is ar memory location %p:\n", frank);

	return 0;
}
