#ifndef LINEDEF_H
#define LINEDEF_H

#include <stdio.h>
#include <stdlib.h>


struct Linedef {
    int start_vertex_id;
    int end_vertex_id;
    int flag;
    int line_type;
    int sector_tag;
    int front_sidedef_id;
    int back_sidedef_id;  
};

typedef struct Linedef linedef;

linedef read_linedef(FILE* f, int offset);

#endif
