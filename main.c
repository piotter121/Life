#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>

#include "genracja.h"
#include "komorka.h"
#include "zapis.h"

int main(int argc, char **argv) {
	int opt, n;
	char *gen_zero;
	char *png_wzor;
	char *usage = "Niepoprawne wywolanie programu\n";
	if (argc == 1) {
		puts(usage);
		return EXIT_FAILURE;
	}
	while ((opt = getopt(argc, argv, "n:l:s:f:w")) != -1) {
		switch (opt) {
			case 'n': 
				n = atoi(optarg);
				break;
			case 'l':
				gen_zero = optarg;
				break;
			case 's':
				png_wzor = optarg;
				break;
			case 'f':
				f = atoi(optarg);
				break;
