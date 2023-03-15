P_STATIC = ../zad2/staticO.o
P_STATIC1 = ../zad2/staticO2.o
P_STATIC2 = ../zad2/staticOs.o


P_SHARED = ../zad2/sharedO.o
P_SHARED1 = ../zad2/sharedO2.o
P_SHARED2 = ../zad2/sharedOs.o

P_DYNAMIC = ../zad2/dynamicO.o
P_DYNAMIC1 = ../zad2/dynamicO2.o
P_DYNAMIC2 = ../zad2/dynamicOs.o

STATICO = results_static_O.txt
STATICO2 = result_static_O2.txt
STATICOS = result_static_Os.txt
SHAREDO = results_shared_O.txt
SHAREDO2 = results_shared_O2.txt
SHAREDOS = results_shared_Os.txt
DYNAMICO = results_dynamic_O.txt
DYNAMICO2 = results_dynamic_O2.txt
DYNAMICOS = results_dynamic_Os.txt

REPORT = report.txt

INPUT = input.txt



CC = gcc
CFLAGS = -Wall -Wextra

.PHONY: all clean

all: static shared dynamic report

static:
	echo "staticO:" >> $(STATICO)
	cat $(INPUT) | $(P_STATIC) >> $(STATICO)
	echo "staticO2:" >> $(STATICO2)
	cat $(INPUT) | $(P_STATIC1) >> $(STATICO2)
	echo "staticOs:" >> $(STATICOS)
	cat $(INPUT) | $(P_STATIC2) >> $(STATICOS)

shared:
	echo "sharedO:" >> $(SHAREDO)
	cat $(INPUT) | $(P_SHARED) >> $(SHAREDO)
	echo "sharedO2:" >> $(SHAREDO2)
	cat $(INPUT) | $(P_SHARED1) >> $(SHAREDO2)
	echo "sharedOs:" >> $(SHAREDOS)
	cat $(INPUT) | $(P_SHARED2) >> $(SHAREDOS)

dynamic:
	echo "dynamicO:" >> $(DYNAMICO)
	cat $(INPUT) | $(P_DYNAMIC) >> $(DYNAMICO)
	echo "dynamicO2:" >> $(DYNAMICO2)
	cat $(INPUT) | $(P_DYNAMIC1) >> $(DYNAMICO2)
	echo "dynamicOs:" >> $(DYNAMICOS)
	cat $(INPUT) | $(P_DYNAMIC2) >> $(DYNAMICOS)


report:
	cat $(STATICO) $(STATICO2) $(STATICOS) $(SHAREDO) $(SHAREDO2) $(SHAREDOS) $(DYNAMICO) $(DYNAMICO2) $(DYNAMICOS) >> $(REPORT)

clean:
	rm -f $(STATICO) $(STATICO2) $(STATICOS) $(SHAREDO) $(SHAREDO2) $(SHAREDOS) $(DYNAMICO) $(DYNAMICO2) $(DYNAMICOS)
