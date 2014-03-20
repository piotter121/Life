FLAGS=-Wall -ansi -pedantic

Life: generacja.o komorka.o sasiedztwo.o zasady.o zapis.o
	$(CC) $(FLAGS) $^ 

main.o: main.c 
	$(CC) -c $(FLAGS) main.c -o $@
	
generacja.o: generacja.c komorka.c
	$(CC) -c $(FLAGS) generacja.c -o $@
	
komorka.o: komorka.c
	$(CC) -c $(FLAGS) komorka.c -o $@
	
Moore: sasiedztwo_M.c komorka.c
	$(CC) -c $(FLAGS) sasiedztwo_M.c -o sasiedztwo.o
	
von_Neumman: sasiedztwo_vN.c komorka.c
	$(CC) -c $(FLAGS) sasiedztwo_vN.c -o sasiedztwo.o
	
zasady.o: zasady.c komorka.c
	$(CC) -c $(FLAGS) zasady.c -o $@

zapis.o: zapis.c
	$(CC) -c $(FLAGS) zapis.c -o $@
	
.PHONY: clean

clean: 
	rm *.o