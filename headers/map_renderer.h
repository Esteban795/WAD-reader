#ifndef MAP_RENDERER_H
#define MAP_RENDERER_H

#include <SDL2/SDL.h>
#include "vect2.h"
#include "linedef.h"

#define RES_W 320
#define RES_H 200

#define SCALE 5.0

#define WIDTH RES_W * SCALE
#define HEIGHT RES_H * SCALE

#define OUT_MIN 30
#define OUT_MAX_W (WIDTH - 30)
#define OUT_MAX_H (HEIGHT - 30)

int* get_map_bounds(vect2* vertexes, int len);

vect2* remap_vertexes(vect2* vertexes, int len, int* map_bounds);

void draw_linedefs(SDL_Renderer* renderer,linedef* linedefs,int len,vect2* vertexes);

void draw_vertexes(SDL_Renderer* renderer,vect2* vertexes,int len);
#endif