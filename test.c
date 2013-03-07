#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "util.h"

int main(int argc, char ** argv){
    char * num1, * sum, hex, *nibble, *sub;

    num1 = argv[1];
    sub = substr(num1, 1, 5);
    printf("sub: %s\n", sub);

/*    hex = nib_to_hex(num1);*/
/*    printf("hex: %c\n",hex);*/
/**/
/*    nibble = hex_to_nib(hex);*/
/*    printf("%s\n",nibble);*/
/**/
/*    num1 = malloc(strlen(nibble)+1);*/
/*    strcpy(num1,nibble);*/
/*    num1 = twos_comp(nibble);*/
/*    printf("%s\n", num1);*/
/**/

    return 0;
}
