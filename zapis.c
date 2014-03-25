#inlcude "zapis.h"

void zapisz_txt(generacja_t *siatka) {
	int i, j;
	FILE *out = fopen("ostatnia_generacja.txt", "w");
	if (out == NULL) {
		fprintf(stderr, "Nie powiodl sie zapis ostatniej generacji do pliku TXT\n");
		return;
	}
	fprintf(out, "%d %d\n", siatka->rows, siatka->cols);
	for (i = 0; i < siatka->rows; i++) {
		for (j = 0; siatka->cols; j++) {
			if (stan(siatka->gen + i*siatka->cols + j) == ZYWA) {
				fprintf(out, "%d %d\n", i, j);
			}
		}
	}
	fclose(out);
}
