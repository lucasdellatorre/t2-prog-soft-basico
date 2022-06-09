CC = gcc

all: app run

run:
	./main.o caso.txt exit.csv

app:
	$(CC) -Wall palavra.c main.c -o main.o

help:
	./main.o caso.txt exit.csv -h

version:
	./main.o caso.txt exit.csv -v

clean:
	rm -rf *.o exit.csv exit.html