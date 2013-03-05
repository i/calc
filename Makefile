FILES=util.c test.c
CFLAGS=-lm -ansi -pedantic -Wall -Werror

all:
	gcc $(FILES) $(CFLAGS) -o calc

debug:
	gcc $(FILES) $(CFLAGS) -g -o calc

clean:
	rm test
