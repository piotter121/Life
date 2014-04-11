#include "sasiedztwo.h"

int Moore_ngbh(generation_t *net, int i, int j) {
	int a, b, result = 0;
	for (a = i - 1; a <= i + 1; a++) {
		if (a < 0 || a >= net->rows)
			continue;
		for (b = j - 1; b <= j + 1; b++) {
			if ((a == i && b == j) || b < 0 || b >= net->cols)
				continue;
			if (condition(cell(net,a,b)) == ALIVE)
				result++;
		}
	}
	return result;
}

int vN_ngbh(generation_t *net, int i, int j) {
	int a, b, result = 0;
	for (a = i - 1; a <= i + 1; a++) {
		if (a < 0 || a >= net->rows)
			continue;
		for (b = j - 1; b <= j + 1; b++) {
			if ((a == i && b == j) || b < 0 || b >= net->cols)
				continue;
			if ((a == i || b == j) && (condition(cell(net,a,b)) == ALIVE))
				result++;
		}
	}
	return result;
}
