#include "sasiedztwo.h"

int sasiedztwo(generacja_t *siatka, int i, int j) {
	int a, b, wynik = 0;
	for (a = i - 1; a <= i + 1; a++) {
		if (a < 0 || a >= siatka->rows)
			continue;
		for (b = j - 1; b <= j + 1; b++) {
			if ((a == i && b == j) || b < 0 || b >= siatka->cols)
				continue;
			if (stan(siatka->gen + a*siatka->cols + b) == ZYWA)
				wynik++;
		}
	}
	return wynik;
}
