all: work14.o
	gcc -o work14m work14.o

nov1.o: work14.c
	gcc -c work14.c

run:
	./work14m

clean:
	rm *.o
	rm work14m
