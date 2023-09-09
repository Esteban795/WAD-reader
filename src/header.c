#include "../headers/header.h"

header read_header(FILE* f){
    header head = {
        .wad_type = read_string(f,0,4),
        .lump_count = read_bytes(f,4,4),
        .init_offset = read_bytes(f,4,8)
        };
    return head;
}