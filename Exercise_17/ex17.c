#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

// define macro in program.
// Macros are constant!
#define MAX_DATA 5
#define MAX_ROWS 100

// What is heap?
// It’s just all the remaining memory in your computer that manage with data-structure, we called heap.
// You can store huge data in heap-memory when your program is running.
// Global variables, structs, typedefs store in heap.

// What is stack?
// Is a special region of memory that stores temporary variables, which each function creates as locals to that function.
// How it works is that each argument to a function is pushed onto the stack and then used inside the function.
// It’s really a stack data structure, so the last thing in is the first thing out.
// There is not memory leaks in stack.
// Local variable, args have been passed to functions, functions store in stack.

// Stack Problems:
/* 1. If you get a block of memory from malloc, and have that pointer on the stack,
then when the function exits the pointer will get popped off and lost.*/

/* 2. If you put too much data on the stack (like large structs and arrays),
then you can cause a stack overflow and the program will abort. In this
case, use the heap with malloc.*/

/* 3. If you take a pointer to something on the stack, and then pass or
return it from your function, then the function receiving it will
segmentation fault (segfault), because the actual data will get popped
off and disappear. You’ll be pointing at dead space.
*/

struct Address {
    int id;
    int set;
    char name[MAX_DATA];
    char email[MAX_DATA];
};

struct Database {
    struct Address rows[MAX_ROWS];
};

struct Connection {
	FILE *file;
	struct Database *db;
};

void die(const char *message)
{
	if (errno) {
		perror(message);
	} else {
		printf("ERROR: %s\n", message);
	}

	exit(1);
}

void Address_print(struct Address *addr)
{
	printf("%d %s %s\n", addr->id, addr->name, addr->email);
}

void Database_load(struct Connection *conn)
{
	int rc = fread(conn->db, sizeof(struct Database), 1, conn->file);
	if (rc != 1)
		die("Failed to load database.");
}

struct Connection *Database_open(const char *filename, char mode)
{
	struct Connection *conn = malloc(sizeof(struct Connection));
	if (!conn)
		die("Memory error.");
	// When you are using malloc() in your program, os give you a piece of 'heap memory'
	conn->db = malloc(sizeof(struct Database));
	if (!conn->db)
		die("Memory error.");
	// When your program had been executed, free() the heap to prevent memory leaks

	if (mode == 'c') {
		conn->file = fopen(filename, "w");
	} else {
		conn->file = fopen(filename, "r+");

		if (conn->file) {
			Database_load(conn);
		}
	}

	if (!conn->file)
		die("Failed to open the file.");

	return conn;
}

void Database_close(struct Connection *conn)
{
	if (conn) {
		if (conn->file)
			fclose(conn->file);
		if (conn->db)
			free(conn->db);
		free(conn);
	}
}

void Database_write(struct Connection *conn)
{
	rewind(conn->file);

	int rc = fwrite(conn->db, sizeof(struct Database), 1, conn->file);
	if (rc != 1)
		die("Failed to write database.");

	rc = fflush(conn->file);
	if (rc == -1)
		die("Cannot flush database.");
}

void Database_create(struct Connection *conn)
{
	for (int i = 0; i < MAX_ROWS; i++) {
		// make a prototype to initialize it
		struct Address addr = { .id = i, .set = 0 };
		// then just assign it
		conn->db->rows[i] = addr;
	}
}

void Database_set(struct Connection *conn, int id, const char *name, const char *email)
{
	struct Address *addr = &conn->db->rows[id];
	if (addr->set)
		die("Already set, delete it first.");

	addr->set = 1;

	char *buf = malloc(strlen(name) + 1);
	strcpy(buf, name);
	strcat(buf, "\0");

	char *res = strncpy(addr->name, buf, MAX_DATA <= strlen(buf) ? strlen(buf) : MAX_DATA);
	if (!res)
		die("Name copy failed.");
	free(buf);

	buf = malloc(strlen(email) + 1);
	strcpy(buf, email);
	strcat(buf, "\0");

	res = strncpy(addr->email, buf, MAX_DATA <= strlen(buf) ? strlen(buf) : MAX_DATA);
	if (!res)
		die("Email copy failed.");
	free(buf);
}

void Database_get(struct Connection *conn, int id)
{
	struct Address *addr = &conn->db->rows[id];

	if (addr->set) {
		Address_print(addr);
	} else {
		die("ID is not set.");
	}
}

void Database_delete(struct Connection *conn, int id)
{
	struct Address addr = { .id = id, .set = 0 };
	conn->db->rows[id] = addr;
}

void Database_list(struct Connection *conn)
{
	struct Database *db = conn->db;

	for (int i = 0; i < MAX_ROWS; i++) {
		struct Address *cur = &db->rows[i];

		if (cur->set) {
			Address_print(cur);
		}
	}
}

int main(int argc, char *argv[])
{
	if (argc < 3)
		die("USAGE: ex17 <dbfile> <action> [action-params]");

	char *filename = argv[1];
	char action = argv[2][0];
	struct Connection *conn = Database_open(filename, action);
	int id = 0;

	if (argc > 3) id = atoi(argv[3]);
	if (id >= MAX_ROWS) die("There's not that many records.");

	switch (action) {
		case 'c':
			Database_create(conn);
			Database_write(conn);
			break;

		case 'g':
			if (argc != 4)
				die("Need an id to get.");

			Database_get(conn, id);
			break;

		case 's':
			if (argc != 6)
				die("Need id, name, email to set.");

			Database_set(conn, id, argv[4], argv[5]);
			Database_write(conn);
			break;

		case 'd':
			if (argc != 4)
				die("Need id to delete.");

			Database_delete(conn, id);
			Database_write(conn);
			break;

		case 'l':
			Database_list(conn);
			break;
		default:
			die("Invalid action: c=create\ng=get\ns=set\nd=delete\nl=list\n");
	}

	Database_close(conn);

	return 0;
}
