#ifndef GENERACJA_H
#define GENERACJA_H

#include "komorka.h"

typedef struct {
	komorka_t *gen;
	int rows;
	int cols;
} generacja_t;

generacja_t *inicjuj_gen(int rows, int cols);

generacja_t *wczytaj_z_pliku(FILE *in);

generacja_t *nastepna_generacja(generacja_t *gen);

#endif