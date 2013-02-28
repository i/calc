#ifndef UTIL_H
#define UTIL_H

char * bin_to_dec(char *);
char * bin_to_oct(char *);
char * bin_to_hex(char *);

char * dec_to_bin(char *);
char * oct_to_bin(char *);
char * hex_to_bin(char *);

char * subtract(char *, char *);
char * multiply(char *, char *);

char * add(char *, char *);
int addDigit(char, char, int);

char * cat(char *, char *);
int max(int, int);
int min(int, int);
char * minstr(char *, char *);
char * maxstr(char *, char *);

#endif
