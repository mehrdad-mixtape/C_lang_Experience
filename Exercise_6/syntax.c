//keywords:

/****** data types keywords ******/
int
long
float
double
char
short
void

/****** data type modifiers keywords ******/
signed
unsigned

/****** statement keywords ******/
// if-statement:
if
else
else if

// syntax:
if (BOOL-EXPRESION) {
	CODE;
}
else if (BOOL-EXPRESION) {
	CODE;
}
else {
	CODE;
}

// switch-statement:
switch
case
break
default

// syntax:
switch (OPERAND) {
	case CONSTANT:
		CODE;
		break;
	default:
		CODE;
}

// loop-statement: do somthings for many times!
for
while
do while
continue
break

// for-loop syntax:
for (INIT; TEST; POST) {
	CODE;
}

// while-loop syntax:
while (BOOL-EXPRESION) {
	CODE;
}

while (BOOL-EXPRESION) {
	if(OTHER-BOOL-EXPRESION) {
		CODE; // maybe, maybe not
		continue; // just go to the beginning of the loop and do not run the code after this line. 
	}
	CODE;
}

while (BOOL-EXPRESION) {
	if (OTHER-BOOL-EXPRESION) {
		CODE; // maybe, maybe not
		break; // just break the loop and go to the outside of loop-statement.
	}
	CODE;
}

do {
	CODE;
} while (BOOL-EXPRESION);

// goto-statement: jump to a label, and is only used in a few useful situations like error detection and exiting.
goto

// goto syntax:
if (BOOL-EXPRESION-TEST) {
	goto fail;
}
fail:
	CODE;

// return-statement: functions want to give back somthings.
return

// return syntax:
TYPE FUNC-NAME(ARG1, ARG2, ...) {
	CODE;
	return VALUE;
}
int name(arg1, arg2) {
	CODE;
	return 0;
}

/****** data type modifiers ******/
/****** bad ass keywords ******/
// create a set of integer costants:
enum

// enum syntax:
enum { CONST1, CONST2, CONST3 } NAME;

auto
const
extern
register
static

// typedef: define new type.
typedef

// typedef syntax:
typedef DEFINITION IDENTIFIER;
typedef unsigned char byte; // define 'unsigned char' type as 'byte'.

// struct: packaging of many base data types into a single concept.
struct

// struct syntax:
struct NAME {
	ELEMENTS;
} VARIABLE_NAME

typedef struct NAME {
	ELEMENTS;
} IDENTIFIER;

// union: create somthings like a struct, but the elements will over-lap in memory.
union

// union syntax:
union NAME {
	ELEMENTS;
} VARIABLE_NAME;

volatile

sizeof
