Life: generacja.o komorka.o sasiedztwo.o zasady.o zapis.o
	$(CC) $^ -o Life -lpng

main.o: main.c 
	$(CC) -c $(FLAGS) main.c -o main.o
	
generacja.o: generacja.c komorka.c
	$(CC) -c $(FLAGS) generacja.c -o generacja.o
	
komorka.o: komorka.c
	$(CC) -c $(FLAGS) komorka.c -o komorka.o
	
sasiedztwo.o: sasiedztwo.c komorka.c
	$(CC) -c $(FLAGS) sasiedztwo.c -o sasiedztwo.o
	
zasady.o: zasady.c komorka.c
	$(CC) -c $(FLAGS) zasady.c -o zasady.o

zapis.o: zapis.c
	$(CC) -c $(FLAGS) zapis.c -o zapis.o -lpng
	
.PHONY: clean

clean: 
	rm *.o
