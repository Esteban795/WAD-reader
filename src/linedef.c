#include "../headers/linedef.h"

linedef read_linedef(FILE* f, int offset){
    linedef line;
    line.start_vertex_id = read_bytes(f,offset,2);
    line.end_vertex_id = read_bytes(f,offset + 2,2);
    line.flag = read_bytes(f,offset + 4,2);
    line.line_type = read_bytes(f,offset + 6,2);
    line.sector_tag = read_bytes(f,offset + 8,2);
    line.front_sidedef_id = read_bytes(f,offset + 10,2);
    line.back_sidedef_id = read_bytes(f,offset + 12,2);
    return line;
}