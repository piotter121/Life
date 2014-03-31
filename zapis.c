#include "zapis.h"

void save_to_txt(generation_t *net, char *file_name) {
	int i, j;
	FILE *out = fopen(file_name, "w");
	if (out == NULL) {
		fprintf(stderr, "Nie powiodl sie zapis ostatniej generacji do pliku TXT\n");
		return;
	}
	fprintf(out, "%d %d\n", net->rows, net->cols);
	for (i = 0; i < net->rows; i++) {
		for (j = 0; net->cols; j++) {
			if (condition(cell(net,i,j)) == ALIVE) {
				fprintf(out, "%d %d\n", i, j);
			}
		}
	}
	fclose(out);
}
