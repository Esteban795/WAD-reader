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
};

typedef struct WADData wadData;

struct Engine {
    bool running;
    SDL_Renderer* renderer;
};

typedef struct Engine engine
#endif