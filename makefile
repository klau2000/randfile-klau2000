all: main.o randfile.o
	gcc -o output main.o randfile.o

main.o: main.c randfile.c
	gcc -c main.c

randfile.o: randfile.c rand.h
	gcc -c randfile.c

rand.o: rand.c rand.h
	gcc -c rand.c

run:
	./output

clean:
	rm *.o
	rm *~
