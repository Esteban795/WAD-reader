#ifndef VERTEX_H
#define VERTEX_H

#include "vect2.h"
#include "byte_reader.h"
#include "lump.h"


vect2 read_vertex(FILE* f,int offset);

vect2* get_vertexes_from_lump(FILE* f,lump* directory,int lump_index, int num_bytes,int header_length);

#endif
