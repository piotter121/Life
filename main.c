#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <string.h>

#include "generacja.h"
#include "komorka.h"
#include "zapis.h"

int main(int argc, char **argv) {
	int a = 1, opt, n, f, last_to_txt = 0;
	char *gen_zero;
	char *png_pattern;
	char *png_title;
	char *txt_pattern;
	char *usage = "Niepoprawne wywolanie programu\n";
	FILE *in = NULL;
	generation_t *current, *new, *tmp;
	if (argc == 1) {
		puts(usage);
		return EXIT_FAILURE;
	}
	while ((opt = getopt(argc, argv, "n:l:s:f:w:")) != -1) {
		switch (opt) {
			case 'n': 
				n = atoi(optarg);
				f = n;
				break;
			case 'l':
				gen_zero = strdup(optarg);
				break;
			case 's':
				png_pattern = strdup(optarg);
				break;
			case 'f':
				f = atoi(optarg);
				break;
			case 'w':
				last_to_txt = 1;
				txt_pattern = strdup(optarg);
				break;
		}
	}
	if ((in = fopen(gen_zero, "r")) == NULL) {
		fprintf(stderr, "Blad: program nie moze odczytac pliku pierwszej generacji\n");
		return EXIT_FAILURE;
	}
	current = load_from_file(in);
	fclose(in);
	png_title = strdup(png_pattern);
	strcat(png_title, "0.png");
	/* save_to_png(current, png_title); */
	write_stdout(current);
	while (a <= n) {
		if ((new = next_generation(current)) == NULL) {
			fprintf(stderr, "Nie powiodlo sie przejscie do kolejnej generacji\n");
			exit(EXIT_FAILURE);
		}
		if (a <= f) {
			png_title = strdup(png_pattern);
			/* strcat(png_title,"%d.png",a); */
			/* save_to_png(new, png_title); */
			write_stdout(new);
		}
		if (a == n && last_to_txt == 1) 
			save_to_txt(new,txt_pattern);
		tmp = current;
		current = new;
		new = tmp;
		a++;
	}
	free_gen(current);
	free_gen(new);
	exit(EXIT_SUCCESS);	
}
