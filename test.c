#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "util.h"

int main(int argc, char ** argv){
    char * ret;

    ret = add(argv[1],argv[2]);

    printf("%s\n",ret);

    return 0;
}
