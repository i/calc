#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "util.h"

int main(int argc, char ** argv){
    char * ret, * big, * small;

    if(strlen(argv[1]) > strlen(argv[2])) {
        big = argv[1];
        small = argv[2];
     } else {
         big = argv[2];
         small = argv[1];
     }

    ret = add(big, small);

    printf("%s\n",ret);
    free(ret);

    return 0;
}
