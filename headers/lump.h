#ifndef LUMP_H
#define LUMP_H

#include <stdio.h>
#include <stdlib.h>
#include "byte_reader.h"
#include "header.h"


struct Lump {
    int lump_offset;
    int lump_size;
    char* lump_name;
};

typedef struct Lump lump;


lump* read_directory(FILE* f,header* h);


int get_lump_index(lump* directory,char* lump_name,int lump_count);
#endif

