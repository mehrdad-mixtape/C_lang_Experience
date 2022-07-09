#include <stdio.h>

int main(int argc, char *argv[])
{
	int distance = 100;
	float power = 2.345f;
	double super_power = 56789.4532;
	char initial = 'A';
	char first_name[] = "Mehrdad";
	char last_name[] = "Arman";

	printf("You are %d miles away.\n", distance);
	printf("You have %f levels of power.\n", power);
	printf("You have %f awesome super powers. \n", super_power);
	printf("I have an initial %c.\n", initial);
	printf("I have a first name  %s.\n", first_name);
	printf("I have a last name %s.\n", last_name);
	printf("My whole name is %s %c. %s. \n", first_name, initial, last_name);

	int bugs = 100;
	double bug_rate = 1.2;

	printf("You have %d bugs at the imaginary rate of %f.\n", bugs, bug_rate);

	long universe_of_defects = 1L * 1024L * 1024L * 1024L;

	printf("The entire universe has %ld bugs.\n", universe_of_defects); // %ld : long decimal
	
	double excepted_bugs = bugs * bug_rate;

	printf("You are excepted to have %f bugs,\n", excepted_bugs);

	double part_of_universe = excepted_bugs / universe_of_defects;

	printf("That is only a %e portion of the universe.\n", part_of_universe); // %e : scientific notation

	// this makes no sense, just a demo of somthing weird

	char null_byte = '\0'; // '\0' : this is efectively the number 0
	int care_percentage = bugs * null_byte;

	printf("Which means you should care %d%%.\n", care_percentage); // %% you ca print % character

	return 0;
}

