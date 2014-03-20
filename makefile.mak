CFLAGS=-Wall -ansi -pedantic

generacja.o: generacja.c generacja.h komorka.c komorka.h
	$(CC) -c $(CFLAGS) generacja.c -o $@
	
komorka.o: komorka.c komorka.h
	$(CC) -c $(CFLAGS) komorka.c -o $@
	
sasiedztwo.o: sasiedztwo.c sasiedztwo.h komorka.c komorka.h
	$(CC) -c $(CFLAGS) sasiedztwo.c -o $@
	
zasady.o: zasady.c zasady.h komorka.c komorka.h
	$(CC) -c $(CFLAGS) zasady.c -o $@
	
.PHONY: clean

clean: 
	rm *.o