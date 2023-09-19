#include "../headers/vertex.h"

vect2 read_vertex(FILE* f,int offset){
    int x = (int) read_bytes(f,offset,2);
    int y = (int) read_bytes(f,offset,2);
    vect2 pos = {.x = x, .y = y};
    return pos;
}

vect2* get_vertexes_from_lump(FILE* f,lump* directory,int lump_index, int num_bytes,int header_length){
    lump lump_info = directory[lump_index];
    int count =  lump_info.lump_size / num_bytes;
    vect2* vertexes = malloc(sizeof(vect2) * count);
    for (int i = 0; i < count;i++){
        int offset = lump_info.lump_offset + i * num_bytes + header_length;
        vertexes[i] = read_vertex(f,offset);
    }
    return vertexes;
}