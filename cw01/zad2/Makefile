CC = gcc
CFLAGS = -Wall -Wextra

.PHONY: all clean

all: static shared dynamic

static:
	$(CC) $(CFLAGS) main.c ../zad1/libwc.a -O0 -o static.o
	$(CC) $(CFLAGS) main.c ../zad1/libwc.a -O -o staticO.o
	$(CC) $(CFLAGS) main.c ../zad1/libwc.a -O2 -o staticO2.o
	$(CC) $(CFLAGS) main.c ../zad1/libwc.a -Os -o staticOs.o

shared:
	$(CC) $(CFLAGS) main.c ../zad1/libwc.so -O0 -o shared.o
	$(CC) $(CFLAGS) main.c ../zad1/libwc.so -O -o sharedO.o
	$(CC) $(CFLAGS) main.c ../zad1/libwc.so -O2 -o sharedO2.o
	$(CC) $(CFLAGS) main.c ../zad1/libwc.so -Os -o sharedOs.o

dynamic:
	$(CC) $(CFLAGS) main.c -O0 -o dynamic.o -ldl -D DLL -I.
	$(CC) $(CFLAGS) main.c -O -o dynamicO.o -ldl -D DLL -I.
	$(CC) $(CFLAGS) main.c -O2 -o dynamicO2.o -ldl -D DLL -I.
	$(CC) $(CFLAGS) main.c -Os -o dynamicOs.o -ldl -D DLL -I.

clean:
	rm -f *.o *.so
