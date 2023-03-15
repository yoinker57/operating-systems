P_STATIC = ../zad2/static.o
P_SHARED = ../zad2/shared.o
P_DYNAMIC = ../zad2/dynamic.o

STATIC = results_static.txt
SHARED = results_shared.txt
DYNAMIC = results_dynamic.txt

REPORT = report.txt

INPUT = input.txt

CC = gcc
CFLAGS = -Wall -Wextra

.PHONY: all clean

all: static shared dynamic report

static:
	echo "static:" > $(STATIC)
	cat $(INPUT) | $(P_STATIC) >> $(STATIC)

shared:
	echo "shared:" > $(SHARED)
	cat $(INPUT) | $(P_SHARED) >> $(SHARED)

dynamic:
	echo "dynamic:" > $(DYNAMIC)
	cat $(INPUT) | $(P_DYNAMIC) >> $(DYNAMIC)


report:
	cat $(STATIC) $(SHARED) $(DYNAMIC) > $(REPORT)

clean:
	rm -f $(STATIC) $(SHARED) $(DYNAMIC)
