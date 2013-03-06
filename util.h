#ifndef UTIL_H
#define UTIL_H

char * to_bin(char *);
char * from_bin(char *, char);

char * add(char *, char *);
char * subtract(char *, char *);
char * multiply(char *, char *);

int addDigit(char, char, int);
int max(int, int);
int min(int, int);

char * cat(char *, char *);
char * minstr(char *, char *);
char * maxstr(char *, char *);

void flip_bits(char *);
char * twos_comp(char *);
void strrev(char *);

#endif
