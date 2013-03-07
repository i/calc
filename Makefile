<<<<<<< HEAD
FILES=utils.c calc2.c
CFLAGS=-lm -ansi -pedantic -Wall -Werror
=======
FILES=util.c calc.c
CFLAGS=-lm -ansi -pedantic -Wall
>>>>>>> 886fe1de95e168a9ff79fa2837f6f1c485808863

all:
	gcc $(FILES) $(CFLAGS) -o calc

debug:
	gcc $(FILES) $(CFLAGS) -g -o calc

clean:
	rm calc
