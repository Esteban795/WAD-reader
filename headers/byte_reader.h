#ifndef BYTE_READER_H
#define BYTE_READER

typedef unsigned char byte;

byte read_1_byte(FILE* f, int offset);

byte* read_bytes(FILE* f,int num_bytes,int offset);

char* read_string(FILE* f, int offset,int num_bytes);
#endif

