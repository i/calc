#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "util.h"
#include "calc.h"

int main(int argc, char ** argv){
    char * bin1, * bin2, * ret, op;

    if(argc != 5){
        fprintf(stderr, "ERROR wrong number of arguments");
        exit(1);
    }

    operator = argv[1][0];

    bin1 = to_bin(argv[2]);
    bin2 = to_bin(argv[3]);

    switch(operator){
        case '+':
            if(strlen(bin1) > strlen(bin2)){
                ret = add(bin1, bin2);
            } else {
                ret = add(bin2, bin1);
            }
            break;

        case '-':
            //things
            break;

        case '*':
            //things
            break;

        default:
            fprintf(stderr, "ERROR invalid operator");
            exit(1);
    }




    return 0;
}
