.PHONY: all

all: compile work result

compile:
	gcc -Wall -o zad1_lib zad1_lib.c
	gcc -Wall -o zad1_sys zad1_sys.c

work:
	./zad1_lib a c test.txt test2.txt >> pomiar_zad_1_lib.txt
	./zad1_sys a c test.txt test3.txt >> pomiar_zad_1_sys.txt

result:
	cat pomiar_zad_1_lib.txt pomiar_zad_1_sys.txt > pomiar_zad_1.txt
	rm -f pomiar_zad_1_lib.txt pomiar_zad_1_sys.txt