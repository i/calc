#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int getbase(char * b){
    printf("getbase -- base: %c\n", b[0]);
    switch (b[0]){
        case 'd':
        case 'D':
            return 10;
        case 'x':
        case 'X':
        case 'h':
        case 'H':
            return 16;
        case 'b':
        case 'B':
            return 2;
        case 'o':
        case 'O':
            return 8;
        default:
            fprintf(stderr, "ERROR invalid base\n");
            exit(1);
    }
}



int getdec(char d){
    switch (d){
        case '0':
            return 0;
        case '1':
            return 1;
        case '2':
            return 2;
        case '3':
            return 3;
        case '4':
            return 4;
        case '5':
            return 5;
        case '6':
            return 6;
        case '7':
            return 7;
        case '8':
            return 8;
        case '9':
            return 9;
        case 'A':
        case 'a':
            return 10;
        case 'B':
        case 'b':
            return 11;
        case 'C':
        case 'c':
            return 12;
        case 'D':
        case 'd':
            return 13;
        case 'E':
        case 'e':
            return 14;
        case 'F':
        case 'f':
            return 15;
        default:
            fprintf(stderr, "ERROR NOT A VALID CHARACTER!!!!!");
            exit(1);
    }
    return 0;
}

char fromdec(int d){
    switch(d){
        case 1:
            return '1';
        case 2:
            return '2';
        case 3:
            return '3';
        case 4:
            return '4';
        case 5:
            return '5';
        case 6:
            return '6';
        case 7:
            return '7';
        case 8:
            return '8';
        case 9:
            return '9';
        case 10:
            return 'A';
        case 11:
            return 'B';
        case 12:
            return 'C';
        case 13:
            return 'D';
        case 14:
            return 'E';
        case 15:
            return 'F';
        default:
            fprintf(stderr, "ERROR OH GOD SOMETHING BAD HAPPENTT!!!11");
            exit(1);
    }
}

int lmfao(char * s){
    int ret, base;

    base = getbase(s);
    ret = 0;
    s++;
    while(*s != '\0'){
        ret *= base;
        ret += getdec(*s);
        s++;
    }
    return ret;
}

char * build(int num, char base){
    char * ret;

    while(num > 1){


        return ret;
    }
}
