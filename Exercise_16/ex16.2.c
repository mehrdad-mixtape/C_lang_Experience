#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

typedef struct String {
	char *self;
	int len;
} string;

struct CPU {
	char *type;
	char *model;
	string serise;
	string gen;
	int cores;
	int threads;
	float freq;
};

struct PC {
	struct CPU *cpu;
	int RAM;
	int STORAGE;
	string GPU;
} pc_one, pc_two;

struct CPU *create_cpu(char *type, char *model, string serise, string gen, int cores, int threads, float freq)
{
	struct CPU *new_cpu = malloc(sizeof(struct CPU));
	assert(new_cpu != NULL);

	new_cpu->type = type;
	new_cpu->model = model;
	new_cpu->serise = serise;
	new_cpu->gen = gen;
	new_cpu->cores = cores;
	new_cpu->threads = threads;
	new_cpu->freq = freq;

	return new_cpu;
}

void print_cpu(struct CPU *cpu)
{
	printf("\tCPU:\n\t\tType: %s\n\t\tModel: %s\n\t\tSerise: %s\n\t\tGen: %s\n\t\tInfo: %d Cores, %d Threads, %lf GHz\n",
			cpu->type, cpu->model, cpu->serise.self, cpu->gen.self, cpu->cores, cpu->threads, cpu->freq);
}

void print_pc(struct PC pc)
{
	printf("Your PC:\n\tRAM: %dGB\n\tSTORAGE: %dTB\n\tGPU: %s\n",
			pc.RAM, pc.STORAGE, pc.GPU.self);
	print_cpu(pc.cpu);
}

void destroy_cpu(struct CPU *cpu)
{
	assert(cpu != NULL);
	free(cpu);
}

string create_string(char *str)
{
	string new_str;
	new_str.self = str;
	new_str.len = strlen(str);
	return new_str;
}

int main(int argc, char *argv[])
{
	struct CPU *AMD = create_cpu("amd64", "Ryzen 9", create_string("7950X"), create_string("ZEN 4"), 16, 32, 5.5);
	struct CPU *Intel = create_cpu("x86-64", "Core i9", create_string("13900K"), create_string("13 Raptor lake"), 24, 32, 5.5);

	pc_one.cpu = AMD;
	pc_one.RAM = 64;
	pc_one.STORAGE = 5;
	pc_one.GPU = create_string("Radeon RX 7900 XT");
	print_pc(pc_one);

	pc_two.cpu = Intel;
	pc_two.RAM = 64;
	pc_two.STORAGE = 5;
	pc_two.GPU = create_string("NVIDIA RTX 4090 TI");
	print_pc(pc_two);

	destroy_cpu(Intel);
	print_pc(pc_two);
	return 0;
}
