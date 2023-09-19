#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include "byte_reader.h"
struct Header {
    char* wad_type;
    u16 lump_count;
    u16 init_offset;
};

typedef struct Header header;

header read_header(FILE* f);
#endif