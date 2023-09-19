#ifndef BYTE_READER_H
#define BYTE_READER_H


#include <stdint.h>
typedef uint16_t u16;


#define THINGS 1
#define LINEDEFS 2
#define SIDEDEFS 3
#define VERTEXES 4
#define SEGS 5
#define SSECTORS 6
#define NODES 7
#define SECTORS 8
#define REJECT 9
#define BLOCKMAP 10

typedef unsigned char byte;

byte read_1_byte(FILE* f, int offset);

byte* read_bytes(FILE* f,int offset,int num_bytes);

char* read_string(FILE* f, int offset,int num_bytes);
#endif

