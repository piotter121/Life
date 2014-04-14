CFLAGS= -Wall -ansi -pedantic -ggdb

Life: generacja.o komorka.o sasiedztwo.o zasady.o main.o zapis.o
	$(CC) $^ -o Life -lpng

main.o: main.c
	$(CC) $(CFLAGS) -c S^
	
generacja.o: generacja.c
	$(CC) $(CFLAGS) -c S^

komorka.o: komorka.c
	$(CC) $(CFLAGS) -c S^
	
sasiedztwo.o: sasiedztwo.c 
	$(CC) $(CFLAGS) -c S^

zasady.o: zasady.c 
	$(CC) $(CFLAGS) -c S^
	
zapis.o: zapis.c 
	$(CC) $(CFLAGS) -c S^
	
.PHONY: clean

clean: 
	rm *.o
