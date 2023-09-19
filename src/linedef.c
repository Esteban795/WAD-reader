#include "../headers/linedef.h"

linedef read_linedef(FILE* f, int offset){
    linedef line;
    line.start_vertex_id = (u16) read_bytes(f,offset,2);
    line.end_vertex_id = (u16) read_bytes(f,offset + 2,2);
    line.flag = (u16) read_bytes(f,offset + 4,2);
    line.line_type = (u16) read_bytes(f,offset + 6,2);
    line.sector_tag = (u16) read_bytes(f,offset + 8,2);
    line.front_sidedef_id = (u16) read_bytes(f,offset + 10,2);
    line.back_sidedef_id = (u16) read_bytes(f,offset + 12,2);
    return line;
}

linedef* get_linedefs_from_lump(FILE* f,lump* directory,int lump_index, int num_bytes,int header_length){
    lump lump_info = directory[lump_index];
    int count =  lump_info.lump_size / num_bytes;
    linedef* linedefs = malloc(sizeof(linedef) * count);
    for (int i = 0; i < count;i++){
        int offset = lump_info.lump_offset + i * num_bytes + header_length;
        linedefs[i] = read_linedef(f,offset);
    }
    return linedefs;
}
