Life: generacja.o komorka.o sasiedztwo.o zasady.o main.o zapis.o
	$(CC) $^ -o Life -lpng
	make clean

.PHONY: clean

clean: 
	rm *.o
