#include <math.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "util.h"

char * to_bin(char * s){
    int basei = 0;

    if(s[basei] == '-'){
/*        handle negative values*/
    }

    else{
        switch(s[0]){
            case 'b':
/*                do nothing*/
                break;

            case 'o':
/*                do a thing*/
                break;

            case 'd':
/*                do more things*/
                break;

            case 'x':
/*                do things*/
                break;

            default:
                fprintf(stderr, "ERROR Invalid operand\n");
                exit(1);
        }
    }
    return 0;
}

/*converts binary number to (o)octal, (h)hexadecimal,*/
/*(d)decimal,*/
char * from_bin(char * bin, char base){

    switch (base){
        case 'o':
/*            binary to octal conversion*/
            break;

        case 'h':
/*            binary to hex conversion*/
            break;

        case 'd':
/*            binary to decimal conversion*/
            break;

        default:
            fprintf(stderr, "ERROR invalid base for output!\n");
            exit(1);
    }
    return 0;
}


/*binary addition.*/
/*works only when big >= small*/
char * add(char * big, char * small){
    char * ret, * s;
    int i, carry;

    s = malloc(strlen(big));
    for(i = 0; i < strlen(big)-strlen(small); i++) {strcat(s,"0");}
    strcat(s, small);

    carry = 0;
    ret = cat("0", big);

    for(i = 0; i < strlen(big); i++){

        switch ( addDigit(ret[strlen(ret)-i-1], s[strlen(s)-i-1], carry) ){

            case 0:
                ret[strlen(ret)-i-1] = '0';
                carry = 0;
                break;

            case 1:
                ret[strlen(ret)-i-1] = '1';
                carry = 0;
                break;

            case 2:
                ret[strlen(ret)-i-1] = '0';
                carry = 1;
                break;

            case 3:
                ret[strlen(ret)-i-1] = '1';
                carry = 1;
                break;

            default:
                fprintf(stderr, "ERROR something went wrong!\n");
                exit(1);
       }
    }
    if(carry)
        ret[0] = '1';

    free(s);
    return ret;
}

int addDigit(char d1, char d2, int carry){
    return (d1 - '0') + (d2 - '0') + carry ;
}

char * cat(char * s1, char * s2){
    char * ret;
    ret = malloc(strlen(s1) + strlen(s2) + 1);
    strcpy(ret,s1);
    strcat(ret,s2);
    return ret;
}

int max(int num1,int num2){
    if(num1 >= num2)
        return num1;
    return num2;
}

int min(int num1, int num2){
    if(num1 < num2)
        return num1;
    return num2;
}

/*returns the shorter of two strings*/
char * shorter(char * s1, char * s2){
    if(strlen(s1) <= strlen(s2))
        return s1;
    return s2;
}
