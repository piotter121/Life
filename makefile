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
	
.PHONY: clean test1 test2 test3 test4 test5

clean: 
	rm *.o

test1:
	./Life -n 100 -l ./test/glider_gun -s glider_gun
	
test2:
	./Life -n 100 -l ./test/glider -s glider -w ostatni_glider.txt

test3:
	./Life -n 100 -l ./test/dakota -s dakota
	
test4:
	./Life -n 100 -l ./test/test -s test -o
	
test5:
	./Life -n 1000 -l ./test/immortal -f 300 -s immortal -w immortal_last
