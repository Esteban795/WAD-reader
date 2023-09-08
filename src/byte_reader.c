#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
    fread(bytes,sizeof(byte),num_bytes,f);
    return bytes;
}

char* read_string(FILE* f, int offset,int num_bytes){
    char* str = malloc(sizeof(char) * num_bytes + 1);
    byte* bytes = read_bytes(f,num_bytes,offset);
    strcpy(str,bytes);
    str[num_bytes] = '\0';
    free(bytes);
    return str;
}

