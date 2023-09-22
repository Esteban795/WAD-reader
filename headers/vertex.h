#ifndef VERTEX_H
#define VERTEX_H

#include "byte_reader.h"
#include "lump.h"


struct Vertex {
    u16 x;
    u16 y;
};

typedef struct Vertex vertex;

vertex read_vertex(FILE* f,int offset);

vertex* get_vertexes_from_lump(FILE* f,lump* directory,int lump_index, int num_bytes,int header_length);

#endif
