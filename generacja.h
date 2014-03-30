#ifndef GENERACJA_H
#define GENERACJA_H

#include <stdio.h>

#include "komorka.h"

typedef struct {
	cell_t *gen;
	int rows;
	int cols;
} generation_t;

generation_t *init_gen(int rows, int cols);

generation_t *load_from_file(FILE *in);

generation_t *next_generation(generation_t *current);

void write_stdout(generation_t *gen);

generation_t *copy(generation_t *gen);

cell_t *cell(generation_t *net, int i, int j);

#endif
