#include <stdio.h>
#include <stdlib.h>

#include "../headers/wad_reader.h"
#include "../headers/byte_reader.h"
#include "../headers/header.h"

#define RES_W 320
#define RES_H 200

#define SCALE 5.0

#define WIDTH RES_W * SCALE
#define HEIGHT RES_H * SCALE


// handles all kind of error at SDL startup
// int start_SDL(SDL_Window** window,SDL_Renderer** renderer,int width,int height, const char* title){
//     if (SDL_Init(SDL_INIT_VIDEO) != 0) return 1;
//     *window = SDL_CreateWindow(title,SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,width,height,SDL_WINDOW_SHOWN);
//     if (*window == NULL) return 1;
//     *renderer = SDL_CreateRenderer(*window,-1,SDL_RENDERER_ACCELERATED);
//     if (*renderer == NULL) return 1;
//     return 0;
// }

wadData initWadDATA(const char* path){
    FILE* file = fopen(path,"rb");
    wadData wd;
    wd.header = read_header(file);
    wd.directory = read_directory(file,wd.header);
    wd.map_index = get_lump_index(wd.directory,"E1M1",wd.header.lump_count);
    wd.vertexes = get_vertexes_from_lump(file,wd.directory,wd.map_index + VERTEXES,4,0);
    wd.linedefs = get_linedefs_from_lump(file,wd.directory,wd.map_index + LINEDEFS,14,0);
}

int main(int argc, char* argv[]){
    return 0;
}