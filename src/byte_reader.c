#include <stdio.h>
#include <stdlib.h>
#include "../headers/byte_reader.h"

byte read_1_byte(FILE* f, int offset){
    byte* b = read_bytes(f,1,offset);
    byte temp = b[0];
    free(b);
    return temp;
}

byte* read_bytes(FILE* f,int num_bytes,int offset){
    byte* bytes = malloc(sizeof(byte) * num_bytes);
    fseek(f,offset,0);
    fread(f,num_bytes,sizeof(byte),bytes);
    return bytes;
}

