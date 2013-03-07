#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "util.h"

/*input should be ./calc <op> <num1> <num2> <output base>*/
int main(int argc, char ** argv){
    char * bin1, * bin2, * binanswer, * ret, op, retbase;

    if(argc != 5){
        fprintf(stderr, "ERROR wrong number of arguments\n");
        exit(1);
    }

    op = argv[1][0];
    retbase = argv[4][0];

    bin1 = to_bin(argv[2]);
    bin2 = to_bin(argv[3]);

    switch(op){
        case '+':
            binanswer = add(bin1, bin2);
            break;

        case '-':
            binanswer = subtract(bin1, bin2);
            break;

        case '*':
/*            //things*/
            break;

        default:
            fprintf(stderr, "ERROR invalid operator");
            free(bin1);
            free(bin2);
            exit(1);
    }

    ret = from_bin(binanswer, retbase);
    printf("%c%s\n", retbase, ret);

    free(bin1);
    free(bin2);
    free(binanswer);
    free(ret);

    return 0;
}
