#include <stdio.h>
#include <stdlib.h>

#include "generacja.h"

generation_t *init_gen(int rows, int cols) {
	int i, j;
	generation_t *new = (generation_t *)malloc(sizeof *new);
	if (new == NULL)
		return NULL;
	new->gen = (cell_t *)malloc((rows*cols) * sizeof *(new->gen));
	if (new->gen == NULL) {
		free(new);
		return NULL;
	}
	new->rows = rows;
	new->cols = cols;
	for (i = 0; i < rows; i++) 
		for (j = 0; j < cols; j++)
			change_condition(cell(new,i,j), DEAD);
	return new;
}

cell_t *cell(generation_t *net, int i, int j) {
	if ((i >= 0 && i < net->rows) && (j >= 0 && j < net->cols))
		return net->gen + i*net->cols + j;
}

generation_t *load_from_file(FILE *in) {
	int m, n, i, j;
	generation_t *new;
	if (fscanf(in, "%d %d", &m, &n) != 2) 
		return NULL;
	new = init_gen(m, n);
	while (fscanf(in, "%d %d", &i, &j) == 2) {
		if (i > 0 && i < m && j > 0 && j < n)
			change_condition(cell(new,i,j), ALIVE);
	}
	return new;
}

generation_t *next_generation(generation_t *net) {
	int i, j;
	generation_t *next = init_gen(gen->rows, gen->cols);
	for (i = 0; i < gen->rows; i++) {
		for (j = 0; j < gen->cols; j++) {
			change_condition(cell(next,i,j),zasady(sasiedztwo(gen,i,j),condition(cell(net,i,j)));
		}
	}
	return next;
}

void write_stdout(generation_t *net) {
	int i, j;
	if (net == NULL)
		return;
	for (i = 0; i < net->rows; i++) {
		for (j = 0; j < net->cols; j++) {
			if (condition(cell(net,i,j)) == ALIVE)
				printf("%d",1);
			else
				printf("%d",0);
		}
		printf("\n");
	}
}		