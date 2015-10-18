all: dictionary

dictionary: main.o dictionary.o
	gcc -o dictionary main.o dictionary.o

dictionary.o: dictionary.c libDico.h
	gcc -c dictionary.c

main.o : main.c 
	gcc -c main.c

clean:
	rm -fr *.o dictionary
