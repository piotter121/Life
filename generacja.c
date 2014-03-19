#include <stdio.h>
#include <stdlib.h>

#include "generacja.h"

generacja_t *inicjuj_gen(int rows, int cols) {
	int i, j;
	generacja_t *new = (generacja_t *)malloc(sizeof *new);
	if (new == NULL)
		return NULL;
	new->gen = (komorka_t *)malloc((rows*cols) * sizeof *(new->gen));
	if (new->gen == NULL) {
		free(new);
		return NULL;
	}
	new->rows = rows;
	new->cols = cols;
	for (i = 0; i < rows; i++) 
		for (j = 0; j < cols; j++)
			zmien_stan(new->gen + i * cols + j, MARTWA);
	return new;
}

generacja_t *wczytaj_z_pliku(FILE *in) {
	int m, n, i, j;
	generacja_t *new;
	if (fscanf(in, "%d %d", &m, &n) != 2) 
		return NULL;
	new = inicjuj_gen(m, n);
	while (fscanf(in, "%d %d", &i, &j) == 2) {
		if (i > 0 && i < m && j > 0 && j < n)
			zmien_stan(new->gen + i * n + j, ZYWA);
	}
	return new;
}

generacja_t *nastepna_generacja(generacja_t *gen) {
	int i, j;
	generacja_t *next = inicjuj_gen(gen->rows, gen->cols);
	for (i = 0; i < gen->rows; i++) {
		for (j = 0; j < gen->cols; j++) {
			zmien_stan(next->gen + i*next->cols + j, zasady(sasiedztwo(gen,i,j),stan(gen->gen + i*gen->cols + j)));
		}
	}
	return next;
}
