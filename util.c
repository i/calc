#include <math.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "util.h"

char * to_bin(char * s){
    int negative, i;
    char base, * ret;
    if(s[0] == '-') {
        negative = 1;
        base = s[1];
    }


    if(negative){
        /*        handle negative values*/
        i = 1;
        i++;
        ret = "";
        return ret;
    }

    else{
        switch(base){
            case 'b':
            case 'B':
                /*                do nothing*/
                break;

            case 'o':
            case 'O':
                /*                do a thing*/
                break;

            case 'd':
            case 'D':
                /*                do more things*/
                break;

            case 'x':
            case 'X':
            case 'h':
            case 'H':
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
    int i;
    long num = 0;
    char digit, * ret;

    switch (base){
        case 'b':
        case 'B':
            return bin;

        case 'o':
        case 'O':
            /*            binary to octal conversion*/
            break;

        case 'h':
        case 'H':
        case 'x':
        case 'X':
            /*            binary to hex conversion*/
            break;

        case 'd':
            for(i = 0; i < strlen(bin); i++){
                if(bin[i] == '1'){
                    printf("adding %f\n", pow(2, strlen(bin)-i-1));
                    num += pow(2, strlen(bin)-i-1);
                }
                else if(bin[i] == '0'){continue;}
                else{
                    fprintf(stderr, "Backend error: tried to convert nonbinary number as binary");
                    exit(1);
                }
            }

            printf("num:%ld\n", num);
            ret = malloc((int)log10(num)+2);
            printf("should be:%d\n", (int)log10(num)+2);
            printf("len:%d\n",(int)sizeof(ret));

            do{
                digit = (int) num % 10 + '0';
                printf("%c\n", digit);
                ret[i] = digit;
                num /= 10;
            }while(floor(num > 1));
            printf("ret:%s\n", ret);

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
