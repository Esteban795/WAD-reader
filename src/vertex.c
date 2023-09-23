#include "../headers/vertex.h"

vertex read_vertex(FILE* f,int offset){
    u16 x = read_u16(f,offset);
    u16 y = read_u16(f,offset + 2);
    vertex pos = {.x = x, .y = y};
    return pos;
}

vertex* get_vertexes_from_lump(FILE* f,lump* directory,int lump_index, int num_bytes,int header_length){
    lump lump_info = directory[lump_index];
    int count =  lump_info.lump_size / num_bytes;
    vertex* vertexes = malloc(sizeof(vertex) * count);
    for (int i = 0; i < count;i++){
        int offset = lump_info.lump_offset + i * num_bytes + header_length;
        vertexes[i] = read_vertex(f,offset);
    }
    return vertexes;
}