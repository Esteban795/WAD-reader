#include "../headers/lump.h"

lump* read_directory(FILE* f,header* h){
    lump* directory = malloc(sizeof(lump) * h->lump_count);
    int offset = 0;
    for (int i = 0; i < h->lump_count;i++){
        offset = h->init_offset + i * 16;
        lump l = {
            .lump_offset = (int) read_bytes(f,4,offset),
            .lump_size = (int) read_bytes(f,offset + 4,4),
            .lump_name = read_string(f,offset + 8,8)
            
        };
        directory[i] = l;
    }
    return directory;
}