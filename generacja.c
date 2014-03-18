#include <stdio.h>
#include <stdlib.h>

#include "generacja.h"

generacja_t *inicjuj_gen(int rows, int cols) {
	int i, j;
	generacja_t *new = malloc(sizeof *new);
	if (new == NULL)
		return NULL;
	new->gen = malloc((rows*cols) * sizeof *(new->gen));
	if (new->gen == NULL) {
		free(new);
		return NULL;
	}
	new->rows = rows;
	new->cols = cols;
	for (i = 0; i < rows; i++) 
		for (j = 0; j < cols; j++)
			new->gen[i * cols + j] = MARTWA;
	return new;
}

generacja_t *wczytaj_z_pliku(FILE *in) {
	int m, n, i, j;
	generacja_t *new;
	if (fscanf(in, "%d %d", &m, &n) != 2) 
		return NULL;
	new = inicjuj_gen(m, n);
	while (fscanf(in, "%d %d", &i, &j) == 2) {
		new->gen[i*new->cols + j] = ZYWA;
	}
	return new;
}

/* generacja_t *nastepna_generacja(generacja_t *gen) {
	int i, j;
	generacja_t *next = inicjuj_gen(gen->rows, gen->cols);
	for (i = 0; i < gen->rows; i++) {
		for (j = 0; j < gen->cols; j++) {
			*/