#include <stdio.h>
#include <stdlib.h>
#include "../headers/byte_reader.h"


int main(void){
    FILE* f = fopen("data/DOOM1.WAD","rb");
    char* str = read_string(f,0,4);
    printf("%s",str);
    free(str);
    return 0;
}