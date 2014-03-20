FLAGS=-Wall -ansi -pedantic

Life: generacja.o komorka.o sasiedztwo.o zasady.o zapis.o
	$(CC) $(FLAGS) $^ 

main.o: main.c 
	$(CC) -c $(FLAGS) main.c -o $@
	
generacja.o: generacja.c komorka.c
	$(CC) -c $(FLAGS) generacja.c -o $@
	
komorka.o: komorka.c
	$(CC) -c $(FLAGS) komorka.c -o $@
	
sasiedztwo.o: sasiedztwo.c komorka.c
	$(CC) -c $(FLAGS) sasiedztwo.c -o $@
	
zasady.o: zasady.c komorka.c
	$(CC) -c $(FLAGS) zasady.c -o $@

zapis.o: zapis.c
	$(CC) -c $(FLAGS) zapis.c -o $@
	
.PHONY: clean

clean: 
	rm *.o