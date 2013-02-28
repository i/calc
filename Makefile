FILES=util.c test.c
CFLAGS=-ansi -pedantic -Wall -Werror

all:
	gcc $(FILES) $(CFLAGS) -o test

debug:
	gcc $(FILES) $(CFLAGS) -g -o test

clean:
	rm test
