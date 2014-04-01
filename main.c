#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <string.h>

#include "generacja.h"
#include "komorka.h"
#include "zapis.h"
#include "sasiedztwo.h"

char *add(char *png_pattern, int i) {
	int pattern_len = (int) strlen(png_pattern);
	int png_len = pattern_len;
	png_len += 5;
	char *new_name = (char*)malloc((png_len + 1) * sizeof new_name);
	strcpy(new_name, png_pattern);
	new_name[pattern_len] = '0' + i;
	new_name[pattern_len + 1] = '.';
	new_name[pattern_len + 2] = 'p';
	new_name[pattern_len + 3] = 'n';
	new_name[pattern_len + 4] = 'g';
	new_name[png_len] = '\0';
	return new_name;
}

int main(int argc, char **argv) {
	int a, opt, n, f, last_to_txt = 0;
	char *gen_zero;
	char *png_pattern = "generacja";
	char *png_title;
	char *txt_pattern;
	char *usage = "Niepoprawne wywolanie programu\n";
	FILE *in = NULL;
	int (*neighbourhood)(generation_t *, int, int) = Moore_ngbh;
	generation_t *current, *new, *tmp;
	if (argc == 1) {
		puts(usage);
		return EXIT_FAILURE;
	}
	while ((opt = getopt(argc, argv, "n:l:s:f:w:o:")) != -1) {
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
			case 'o': 
				neighbourhood = vN_ngbh;
				break;
			/*case default:
				fprintf(stderr, "%s: Nie prawidłowy argument wywołania %c\n", argv[0], opt);
				puts(usage);
				exit(EXIT_FAILURE); */
		}
		/*printf("pętla wczytujaca\n");*/
	}
	if (gen_zero == NULL || ((in = fopen(gen_zero, "r")) == NULL)) {
		fprintf(stderr, "%s: program nie moze odczytac pliku pierwszej generacji\n", argv[0]);
		return EXIT_FAILURE;
	}
	current = load_from_file(in);
	/*printf("po wczytaniu z pliku 0\n");*/
	png_title = strdup(png_pattern);
	strcat(png_title, "0.png");
	save_to_png(current, png_title); 
	/*write_stdout(current);*/
	/*printf("doszlo do głownej petli\n");*/
	for (a = 1; a <= n; a++) {
		if ((new = next_generation(current,neighbourhood)) == NULL) {
			fprintf(stderr, "%s: Nie powiodlo sie przejscie do kolejnej generacji\n", argv[0]);
			exit(EXIT_FAILURE);
		}
		if (a <= f) {
			png_title = add(png_pattern, a);
			save_to_png(new, png_title); 
			/*write_stdout(new);*/
		}
		if (a == n && last_to_txt == 1) 
			save_to_txt(new,txt_pattern);
		tmp = current;
		current = new;
		new = tmp;
		/*printf("wewnatrz petli gl\n");*/
	}
	free_gen(current);
	free_gen(new);
	exit(EXIT_SUCCESS);	
}
