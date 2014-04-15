CFLAGS= -Wall -ansi -pedantic -ggdb

Life: generacja.o komorka.o sasiedztwo.o zasady.o main.o zapis.o
	$(CC) $^ -o $@ -lpng

main.o: main.c
	$(CC) $(CFLAGS) -c $^
	
generacja.o: generacja.c
	$(CC) $(CFLAGS) -c $^

komorka.o: komorka.c
	$(CC) $(CFLAGS) -c $^
	
sasiedztwo.o: sasiedztwo.c 
	$(CC) $(CFLAGS) -c $^

zasady.o: zasady.c 
	$(CC) $(CFLAGS) -c $^
	
zapis.o: zapis.c 
	$(CC) $(CFLAGS) -c $^
	
.PHONY: clean

clean: 
	rm *.o
