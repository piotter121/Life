#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <string.h>

#include "genracja.h"
#include "komorka.h"
#include "zapis.h"

int main(int argc, char **argv) {
	int a = 1, opt, n, f, last_to_txt = 0;
	char *gen_zero;
	char *png_wzor;
	char *nazwa_png;
	char *uzycie = "Niepoprawne wywolanie programu\n";
	FILE *in = NULL;
	generacja_t *bierzaca, *nowa, *tmp;
	if (argc == 1) {
		puts(usage);
		return EXIT_FAILURE;
	}
	while ((opt = getopt(argc, argv, "n:l:s:f:w")) != -1) {
		switch (opt) {
			case 'n': 
				n = atoi(optarg);
				f = n;
				break;
			case 'l':
				gen_zero = strdup(optarg);
				break;
			case 's':
				png_wzor = strdup(optarg);
				break;
			case 'f':
				f = atoi(optarg);
				break;
			case 'w':
				last_to_txt = 1;
				txt_wzor = strdup(optarg);
				break;
			case default:
				break;
		}
	}
	if ((in = fopen(gen_zero, "r")) == NULL) {
		fprintf(stderr, "Blad: program nie moze odczytac pliku pierwszej generacji\n");
		return EXIT_FAILURE;
	}
	bierzaca = wczytaj_z_pliku(in);
	fclose(in);
	nazwa_png = strdup(png_wzor);
	strcat(nazwa_png, "0.png");
	zapisz_png(bierzaca, nazwa_png);
	while (a <= n) {
		if ((nowa = nastepna_generacja(bierzaca)) == NULL) {
			fprintf(stderr, "Nie powiodlo sie przejscie do kolejnej generacji\n");
			exit(EXIT_FAILURE);
		}
		if (a <= f) {
			nazwa_png = strdup(png_wzor);
			strcat(nazwa_png,"%d.png", a);
			zapisz_png(nowa, nazwa_png);
		}
		if (a == n && last_to_txt == 1) 
			zapisz_txt(nowa, txt_wzor);
		tmp = bierzaca;
		bierzaca = nowa;
		nowa = tmp;
	}
	free_gen(bierzaca
	exit(EXIT_SUCCESS);	
