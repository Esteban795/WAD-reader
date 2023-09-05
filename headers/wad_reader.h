#ifndef WAD_READER_H
#define WAD_READER_H

#include <stdio.h>
#include <stdlib.h>

struct WADReader {
    FILE* wad_file;
    header* header;
    
}
#endif