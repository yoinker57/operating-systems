CC = gcc -Wall -Werror
raport = test.txt

.PHONY: all

all:
	$(CC) zad1.c -o zad1
	$(CC) exec_i.c -o exec_i
	$(CC) exec_m.c -o exec_m
	$(CC) exec_p.c -o exec_p
	make test
	
test : test_child test_exec
	
test_child : 
	echo "ignore" >> $(raport)
	./zad1 ignore >> $(raport)
	echo "\n" 	>> $(raport)
	echo "handler" >> $(raport)
	./zad1 handler >> $(raport)
	echo "\n" 	>> $(raport)
	echo "mask" >> $(raport)
	./zad1 mask >> $(raport)
	echo "\n" 	>> $(raport)
	echo "pending" >> $(raport)
	./zad1 pending >> $(raport)
	echo "\n" 	>> $(raport)
test_exec: exec_i exec_m exec_p
	echo "execI" >> $(raport)
	./zad1 execI >> $(raport)
	echo "\n" 	>> $(raport)
	echo "execM" >> $(raport)
	./zad1 execM >> $(raport)
	echo "\n" 	>> $(raport)
	echo "execP" >> $(raport)
	./zad1 execP >> $(raport)
	echo "\n" 	>> $(raport)
	
clean:
	rm -f zad1 exec_i exec_m exec_p