#include "../headers/map_renderer.h"

#include <stdbool.h>
int start_SDL(SDL_Window** window,SDL_Renderer** renderer,int width,int height, const char* title){
    if (SDL_Init(SDL_INIT_VIDEO) != 0) return 1;
    *window = SDL_CreateWindow(title,SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,width,height,SDL_WINDOW_SHOWN);
    if (*window == NULL) return 1;
    *renderer = SDL_CreateRenderer(*window,-1,SDL_RENDERER_ACCELERATED);
    if (*renderer == NULL) return 1;
    return 0;
}


int main(void){
    SDL_Window* window;
    SDL_Renderer* renderer;
    int status = start_SDL(&window,&renderer,WIDTH,HEIGHT,"Doom");
    if (status != 0){
        printf("Error starting SDL\n");
        return 1;
    }
    vertex vertexes[4] = {{0,0},{0,100},{100,0},{100,100}};
    int* map_bounds = get_map_bounds(vertexes,4);
    vertex* temp = remap_vertexes(vertexes,4,map_bounds);
    for (int i = 0; i < 4; i++){
        printf("x: %d, y: %d\n",temp[i].x,temp[i].y);
    }
    while (true) {
        draw_vertexes(renderer,temp,4);
        SDL_RenderPresent(renderer);
        SDL_Delay(300);
        
    }
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    free(temp);
    free(map_bounds);
    return 0;
}