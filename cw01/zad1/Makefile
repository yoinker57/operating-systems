CC = gcc
CF = -Wall -Wextra


all:
	make lib_static
	make lib_shared

lib_static: wc.c
	$(CC) $(CF) -c wc.c
	ar cr libwc.a wc.o

lib_shared: wc.c
	$(CC) $(CF) -c -fPIC wc.c
	$(CC) $(CF) -shared -o libwc.so wc.o

clean:
	rm -f *.o *.gch *.a *.so
