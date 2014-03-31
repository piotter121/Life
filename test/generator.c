#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int losuj(int p, int q) {
	return rand() % (q - p + 1) + p;
}

int main(int argc, char **argv) {
	int m, n, z, i;

	if (argc < 4)
		exit(1);
	m = atoi(argv[1]);
	n = atoi(argv[2]);
	z = atoi(argv[3]);
	srand(time(NULL));
	printf("%d %d\n", m, n);
	for (i = 0; i < z; i++)
		printf("%d %d\n", losuj(1,m), losuj(1,n));
	return 0;
}
