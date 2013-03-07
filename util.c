#include <math.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "util.h"

char * to_bin(char * s){
    int negative, num, i;
    char base, * ret, * bits;

    if(s[0] == '-') {
        negative = 1;
        base = s[1];
    }
    else{ base = s[0]; }

    if(negative){
        negative = 1;    /*        handle negative values*/
    }

    switch(base){
        case 'b':
        case 'B':
            ret = malloc(sizeof(strpbrk(s, "10")));
            strcpy(ret, strpbrk(s, "10"));
            return ret;
            break;

        case 'o':
        case 'O':
            /*                do a thing*/
            break;

        case 'd':
        case 'D':
            ret = malloc(1000);
            ret = "0";
            for(i=0; i < strlen(s); i++){
                bits = decbits(s[strlen(s)-i-1]);
                printf("%s\n",bits);
                strcat(ret, bits);
                free(bits);
            }


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
    return 0;
}

/*converts binary number to (o)octal, (h)hexadecimal, (d)decimal*/
char * from_bin(char * bin, char base){
    int i, len;
    long num = 0;
    char digit, * ret, nibble[4];

    switch (base){
        case 'b':
        case 'B':
            ret = malloc(strlen(bin)+1);
            strcpy(ret,strpbrk(bin, "1"));
            return ret;

        case 'o':
        case 'O':
            /*            binary to octal conversion*/
            break;

        case 'h':
        case 'H':
        case 'x':
        case 'X':
            for(i = 0; i < strlen(bin); i++){
                /*                grab four bytes*/



            }
            break;

        case 'd':
            for(i = 0; i < strlen(bin); i++){
                if(bin[i] == '1'){
                    num += pow(2, strlen(bin)-i-1);
                }
                else if(bin[i] == '0'){continue;}
                else{
                    fprintf(stderr, "Backend error: tried to convert nonbinary number as binary");
                    exit(1);
                }
            }

            len = (int)log10(num)+1;
            ret = malloc(len);

            for(i = 0; i < len; i++){
                digit = (int) num % 10 + '0';
                ret[i] = digit;
                num /= 10;
            }

            strrev(ret);
            return ret;
            break;

        default:
            fprintf(stderr, "ERROR invalid base for output!\n");
            exit(1);
    }
    return 0;
}


char * add(char * num1, char * num2){
    char * ret, * s, * big, * small;
    int i, carry;

    if(strlen(num1) > strlen(num2)){
        big = num1;
        small = num2;
    } else {
        big = num2;
        small = num1;
    }

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
    if(carry){
        ret[0] = '1';
    }
    free(s);
    return ret;
}

/*subtracts bin2 from bin1*/
char * subtract(char * minuend, char * subtrahend){
    char * diff, * temp;

    printf("adding: %s to %s\n",minuend, twos_comp(subtrahend));
    temp = add(minuend, twos_comp(subtrahend));
    /*    diff = malloc(strlen(strpbrk(++temp, "01")) + 1);*/
    /*    strcpy(diff, strpbrk(++temp, "10"));*/
    diff = malloc(strlen(temp) + 1);
    strcpy(diff, temp);
    if(diff[0] == '\0'){
        diff = "0";
    }

    return diff;
}

/*char * multiply(char * multiplicitand1, char * multiplix0r){*/
    /*    char * sum;*/
    /*    int i, multiplizagsxfr;*/
    /*    multiplizagsxfr = 0;*/
/*}*/


int addDigit(char d1, char d2, int carry){
    return (d1 - '0') + (d2 - '0') + carry;
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

void strrev(char * s){
    char * e, t;
    e = s + strlen(s) - 1;
    while(s < e){
        t = *s;
        *s = *e;
        *e = t;
        e--; s++;
        return;
    }
}

void flip_bits(char * bits){
    while (*bits != '\0'){
        if(*bits == '0') {*bits = '1';}
        else if(*bits == '1') {*bits = '0';}
        else{
            fprintf(stderr, "ERROR");
            exit(1);
        }
        bits++;
    }
}

char * twos_comp(char * bits){
    char * ret;
    flip_bits(bits);
    ret = add(bits, "1");
    return ret;
}

char nib_to_hex(char * nib){
    char * bits;
    int i;

    bits = calloc(sizeof(char), 5);
    for(i=0; i<4-strlen(nib); i++) strcat(bits,"0");

    strcat(bits, nib);
    printf("%s\n",bits);

    if( strcmp(bits, "0000") == 0) return '0';
    if( strcmp(bits, "0001") == 0) return '1';
    if( strcmp(bits, "0010") == 0) return '2';
    if( strcmp(bits, "0011") == 0) return '3';
    if( strcmp(bits, "0100") == 0) return '4';
    if( strcmp(bits, "0101") == 0) return '5';
    if( strcmp(bits, "0110") == 0) return '6';
    if( strcmp(bits, "0111") == 0) return '7';
    if( strcmp(bits, "1000") == 0) return '8';
    if( strcmp(bits, "1001") == 0) return '9';
    if( strcmp(bits, "1010") == 0) return 'A';
    if( strcmp(bits, "1011") == 0) return 'B';
    if( strcmp(bits, "1100") == 0) return 'C';
    if( strcmp(bits, "1101") == 0) return 'D';
    if( strcmp(bits, "1110") == 0) return 'E';
    if( strcmp(bits, "1111") == 0) return 'F';

    fprintf(stderr, "ERROR Invalid nibble!");
    exit(1);
}

char * hex_to_nib(char hex){
    if(hex == '0') return "0000";
    if(hex == '1') return "0001";
    if(hex == '2') return "0010";
    if(hex == '3') return "0011";
    if(hex == '4') return "0100";
    if(hex == '5') return "0101";
    if(hex == '6') return "0110";
    if(hex == '7') return "0111";
    if(hex == '8') return "1000";
    if(hex == '9') return "1001";
    if(hex == 'A') return "1010";
    if(hex == 'B') return "1011";
    if(hex == 'C') return "1100";
    if(hex == 'D') return "1101";
    if(hex == 'E') return "1110";
    if(hex == 'F') return "1111";

    fprintf(stderr, "ERROR Invalid hex digit");
    exit(1);
}

char * substr(char * str, int start, int stop){
    char * ret, * t;

    if(stop <= start || start < 0 || stop > strlen(str)){
        fprintf(stderr, "ERROR out of range");
        exit(1);
    }

    ret = calloc(sizeof(char), stop - start + 1);
    t = str;
    while(t != '\0'){
        printf("%s", ret);
    }
    return ret;
}

char * decbits(char a){
    char * dst;
    dst = malloc(5);
    switch(a){
        case '0':
            dst = "0";
            break;
        case '1':
            dst = "1";
            break;
        case '2':
            dst = "10";
            break;
        case '3':
            dst = "11";
            break;
        case '4':
            dst = "100";
            break;
        case '5':
            dst = "101";
            break;
        case '6':
            dst = "110";
            break;
        case '7':
            dst = "111";
            break;
        case '8':
            dst = "1000";
            break;
        case '9':
            dst = "1001";
            break;
    }
    return dst;
}
