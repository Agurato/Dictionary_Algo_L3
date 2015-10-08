all: dictionnary

dictionnary: main.o dictionnary.o
	gcc -o dictionnary main.o dictionnary.o

dictionnary.o: dictionnary.c libdictionnary.h
	gcc -c dictionnary.c

main.o : main.c 
	gcc -c main.c

clean:
	rm -fr *.o dictionnary
