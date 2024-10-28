CC = gcc
IDIR = ../include
HGET = $(wildcard $(IDIR)/*.h)
CFLAGS = -Wall -I$(IDIR) -lncurses
SOURCES = $(wildcard src/*.c)
CTO = $(SOURCES:.c=.o)

.PHONY: all run time clean  

all: programa-principal programa-testes

programa-principal: $(CTO)
	$(CC) -g -o $@ $^ $(CFLAGS)

%.o: %.c $(HGET)
	$(CC) -g -c -o $@ $< $(CFLAGS)

programa-testes: $(CTO)
	$(CC) -g -o $@ $^ $(CFLAGS)

run: programa-principal
	./programa-principal ../../data ../../input.txt

bigrun: programa-principal
	./programa-principal ../../data_big ../../input_big.txt

interativo: programa-principal
	./programa-principal

test_run: programa-testes
	./programa-testes ../../data ../../input.txt ../../outputs

test_bigrun: programa-testes
	./programa-testes ../../data_big ../../input_big.txt ../../outputs_big

programa-principal.debug: $(CTO)
	$(CC) -o programa-principal.debug $^ $(CFLAGS) -g -Og

debug: programa-principal.debug
	gdb programa-principal.debug

grind: programa-principal.debug
	valgrind --leak-check=full --show-reachable=no --show-leak-kinds=all --log-file=valgrind-out.txt ./programa-principal.debug ../../data ../../input.txt

meow: grind
	cat valgrind-out.txt

clean:
	rm -f programa-principal src/*.o programa-principal.debug valgrind-out.txt programa-testes program Resultados/*.csv Resultados/*.txt