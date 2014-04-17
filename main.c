#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <string.h>
#include <errno.h>
#define _POSIX_SOURCE
#include <sys/stat.h>
#include <unistd.h>
#undef _POSIX_SOURCE

#include "generacja.h"
#include "komorka.h"
#include "zapis.h"
#include "sasiedztwo.h"

const char *usage = "Usage: \n"
		    "./Life -n N -l path [-s prefix] [-o] [-w file_name] [-f F]\n"
		    "\tN - the number of generations\n"
		    "\tpath - path to the file with data about generation zero\n"
		    "\tprefix - prefix of the png files\n"
		    "\t-o - switch on von Neumann neighbourhood\n"
		    "\tfile_name - the name of the file which will have data about last generation\n"
		    "\tF - the number of generations which will be written to png files\n";

int main(int argc, char **argv) {
	int a, opt, n, f, last_to_txt = 0;
	char *gen_zero;
	char *png_pattern = "generacja";
	char png_title[100];
	char number[10];
	const char *format = ".png";
	char *txt_pattern;
	const char *new_dir = "created_files";
	FILE *in = NULL;
	int (*neighbourhood)(generation_t *, int, int) = Moore_ngbh;
	generation_t *current, *new;
	if (argc < 5) {
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
		if (errno == EEXIST) {
			if (chdir(new_dir) != 0) {
				perror("error");
			}
		} else {
			perror("error");
		}
	} else if (chdir(new_dir) != 0) {
		perror("error");
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
	if (chdir("..") != 0) 
		perror("error");
	exit(EXIT_SUCCESS);	
}
