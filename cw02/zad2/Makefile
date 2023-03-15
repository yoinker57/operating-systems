.PHONY: all

all: compile work result

compile:
	gcc -Wall -o zad2_1 zad2_1.c
	gcc -Wall -o zad2_2 zad2_2.c

work:
	./zad2_1 test.txt test2.txt >> pomiar_1.txt
	./zad2_2 test.txt test3.txt >> pomiar_2.txt

result:
	cat pomiar_1.txt pomiar_2.txt > pomiar_zad_2.txt
	rm -f pomiar_1.txt pomiar_2.txt