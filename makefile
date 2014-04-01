FLAGS=-Wall -ansi -pedantic

Life: generacja.o komorka.o sasiedztwo.o zasady.o zapis.o
	$(CC) $^ -o Life 

main.o: main.c 
	$(CC) -c $(FLAGS) main.c -o main.o
	
generacja.o: generacja.c komorka.c
	$(CC) -c $(FLAGS) generacja.c -o generacja.o
	
komorka.o: komorka.c
	$(CC) -c $(FLAGS) komorka.c -o komorka.o
	
sasiedztwo.o: sasiedztwo_M.c komorka.c
	$(CC) -c $(FLAGS) sasiedztwo_M.c -o sasiedztwo.o
	
zasady.o: zasady.c komorka.c
	$(CC) -c $(FLAGS) zasady.c -o zasady.o

zapis.o: zapis.c
	$(CC) -c $(FLAGS) zapis.c -o zapis.o
	
.PHONY: clean

clean: 
	rm *.o
