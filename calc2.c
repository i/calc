#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "utils.h"

int main(int argc, char ** argv){
    int num1, num2, ans;
    char * ret;

    if(argc != 5){
        fprintf(stderr, "ERROR wrong number args\n");
        exit(1);
    }

    num1 = lmfao(argv[2]);
    num2 = lmfao(argv[3]);

    if(argv[1][0] == '+') ans = num1 + num2;
    if(argv[1][0] == '-') ans = num1 - num2;

    ret = build(ans, argv[4][0]);

    return 0;
}
