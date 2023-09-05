#ifndef HEADER_H
#define HEADER_H

struct Header {
    char* wad_type;
    int lump_count;
    int init_offset;
};

typedef struct Header header;

#endif