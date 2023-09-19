#include <stdio.h>
#include <stdlib.h>

#include "../headers/byte_reader.h"
#include "../headers/map_renderer.h"


#define RES_W 320
#define RES_H 200

#define SCALE 5.0

#define WIDTH RES_W * SCALE
#define HEIGHT RES_H * SCALE


// handles all kind of error at SDL startup
int start_SDL(SDL_Window** window,SDL_Renderer** renderer,int width,int height, const char* title){
    if (SDL_Init(SDL_INIT_VIDEO) != 0) return 1;
    *window = SDL_CreateWindow(title,SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,width,height,SDL_WINDOW_SHOWN);
    if (*window == NULL) return 1;
    *renderer = SDL_CreateRenderer(*window,-1,SDL_RENDERER_ACCELERATED);
    if (*renderer == NULL) return 1;
    return 0;
}

int main(void){
    FILE* f = fopen("data/DOOM1.WAD","rb");
    char* str = read_string(f,0,1);
    printf("%s",str);
    free(str);
    return 0;
}