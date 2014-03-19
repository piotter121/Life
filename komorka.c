#include <stdlib.h>

#include "komorka.h"

void zmien_stan(komorka_t *kom, stan_kom nowyst){
	kom->stan = nowyst;
}

komorka_t *inicjuj_kom(){
	komorka_t *new = malloc(sizeof *new);
	zmien_stan(new, MARTWA);
	return new;
}

stan_kom stan(komorka_t *kom) {
	return kom->stan;
}
