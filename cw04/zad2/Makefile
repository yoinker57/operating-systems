CC = gcc -Wall

all: clean main test

main:
	$(CC) zad2.c -o zad2.o

test:
	./zad2.o > "report.txt"

clean:
	rm -f zad2.o