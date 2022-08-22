#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 1st way: ---------------------------------------------------
struct Person {
	char *name;
	int age;
	float height;
	int weight;
};

struct Person Person_create(char *name, int age, float height, int weight)
{
	struct Person who;
	who.name = name;
	who.age = age;
	who.height = height;
	who.weight = weight;
	return who;
}

void Person_destroy(struct Person who)
{}

void Person_print(struct Person who)
{
	printf("----\nName: %s\nAge: %d\nHeight: %f\nWeight: %d\n",
			who.name, who.age, who.height, who.weight);
}

// 2nd way: ---------------------------------------------------
struct animal {
	char *name;
	int age;
	char *type;
} lion, parrot;

typedef struct String {
	char *self;
	int len;
} string;

// 3th way: ---------------------------------------------------
string String_create(char *str)
{
	string my_string;
	my_string.self = str;
	my_string.len = strlen(str);
	return my_string;
}

void String_print(string input)
{
	printf("----\nself is '%s', len is %d %p\n", input.self, input.len, &input);
}

void String_print_2(string *input)
{
	printf("----\nself is '%s', len is %d %p\n", input->self, input->len, input);
}

//---------------------------------------------------
int main(int argc, char *argv[])
{
	struct Person mehrdad = Person_create("Mehrdad Arman", 23, 168.9, 60);
	printf("Mehrdad is at memory location %p:\n", &mehrdad);
	Person_print(mehrdad);
	// Person_destroy(mehrdad);

	lion.name = "Oscar";
	lion.age = 5;
	lion.type = "African";
	printf("----\n%s %d %s %p\n", lion.name, lion.age, lion.type, &lion);

	parrot.name = "Alvin";
	parrot.age = 10;
	parrot.type = "Malango";
	printf("----\n%s %d %s %p\n", parrot.name, parrot.age, parrot.type, &lion);

	string my_string = String_create("Hello world");
	String_print(my_string);

	string my_string_2 = String_create("I love C");
	String_print_2(&my_string_2);

	return 0;
}
