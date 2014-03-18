#ifndef KOMORKA_H
#define KOMORKA_H

typedef enum{MARTWA, ZYWA} stan_kom;

typedef struct{
	int i;
	int j;
	stan_kom stan;
} komorka_t;

void zmien_stan(komorka_t *kom, stan_kom nowy_stan);

komorka_t *inicjuj_kom();

#endif