FILES=util.c calc.c
CFLAGS=-lm -ansi -pedantic -Wall

all:
	gcc $(FILES) $(CFLAGS) -o calc

debug:
	gcc $(FILES) $(CFLAGS) -g -o calc

clean:
	rm calc
