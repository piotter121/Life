#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <string.h>
#define _POSIX_SOURCE
#include <sys/stat.h>
#include <unistd.h>
#undef _POSIX_SOURCE

#include "generacja.h"
#include "komorka.h"
#include "zapis.h"
#include "sasiedztwo.h"

int main(int argc, char **argv) {
	int a, opt, n, f, last_to_txt = 0;
	char *gen_zero;
	char *png_pattern = "generacja";
	char png_title[100];
	char number[10];
	const char *format = ".png";
	char *txt_pattern;
	const char *usage = "Niepoprawne wywolanie programu\n";
	const char *new_dir = "created_files";
	FILE *in = NULL;
	int (*neighbourhood)(generation_t *, int, int) = Moore_ngbh;
	generation_t *current, *new;
	if (argc == 1) {
		puts(usage);
		return EXIT_FAILURE;
	}
	while ((opt = getopt(argc, argv, "n:l:s:f:w:o")) != -1) {
		switch (opt) {
			case 'n': 
				n = atoi(optarg);
				f = n;
				break;
			case 'l':
				gen_zero = optarg;
				break;
			case 's':
				png_pattern = optarg;
				break;
			case 'f':
				f = atoi(optarg);
				break;
			case 'w':
				last_to_txt = 1;
				txt_pattern = optarg;
				break;
			case 'o': 
				neighbourhood = vN_ngbh;
				break;
			default:
				fprintf(stderr, "%s: Nie prawidłowy argument wywołania %c\n", argv[0], opt);
				puts(usage);
				exit(EXIT_FAILURE);
		}
	}
	if (gen_zero == NULL || ((in = fopen(gen_zero, "r")) == NULL)) {
		fprintf(stderr, "%s: program nie moze odczytac pliku pierwszej generacji\n", argv[0]);
		return EXIT_FAILURE;
	}
	current = load_from_file(in);
	if (mkdir(new_dir, S_IRWXU|S_IRGRP|S_IXGRP) != 0) {
		perror("blad: nie mozna utworzyc folderu\n");
		exit(1);
	} else if (chdir(new_dir) != 0) {
		perror("blad: Nie mozna otworzyc katalogu do zapisu\n");
		exit(2);
	}
	strcpy(png_title, png_pattern);
	strcat(png_title, "0.png");
	save_to_png(current, png_title); 
	for (a = 1; a <= n; a++) {
		strcpy(png_title, png_pattern);
		if ((new = next_generation(current,neighbourhood)) == NULL) {
			fprintf(stderr, "%s: Nie powiodlo sie przejscie do kolejnej generacji\n", argv[0]);
			exit(EXIT_FAILURE);
		}
		if (a <= f) {
			sprintf(number, "%d", a);
			strcat(png_title, number);
			strcat(png_title, format);
			save_to_png(new, png_title); 
		}
		if (a == n && last_to_txt == 1) 
			save_to_txt(new,txt_pattern);
		free_gen(current);
		current = new;
	}
	chdir("..");
	exit(EXIT_SUCCESS);	
}
