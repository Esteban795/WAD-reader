#ifndef WAD_READER_H
#define WAD_READER_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "header.h"
#include "map_renderer.h"


#define DT 1/60 
struct WADData {
    header header;
    lump* directory;
    int map_index;
    vertex* vertexes;
    linedef* linedefs;
    int len_vertexes;
    int len_linedefs;
};

typedef struct WADData wad_data;

struct Engine {
    const char* wadPath;
    bool running;
    SDL_Renderer* renderer;
    wad_data wData;
};

typedef struct Engine engine;

#endif