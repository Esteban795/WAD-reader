#include <stdio.h>
#include <stdlib.h>

#include "../headers/wad_reader.h"

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

wadData initWadDATA(const char* path){
    FILE* file = fopen(path,"rb");
    wadData wd;
    wd.header = read_header(file);
    wd.directory = read_directory(file,wd.header);
    wd.map_index = get_lump_index(wd.directory,"E1M1",wd.header.lump_count);
    wd.len_vertexes = wd.directory[wd.map_index + VERTEXES].lump_size / 4; // 4 = number of bytes per vertex
    wd.len_linedefs = wd.directory[wd.map_index + LINEDEFS].lump_size / 14; // 14 = number of bytes per linedef
    wd.vertexes = get_vertexes_from_lump(file,wd.directory,wd.map_index + VERTEXES,4,0,wd.len_vertexes); // 4 = number of bytes per vertex
    wd.linedefs = get_linedefs_from_lump(file,wd.directory,wd.map_index + LINEDEFS,14,0,wd.len_linedefs); // 14 = number of bytes per linedef
    
    int* bounds = get_map_bounds(wd.vertexes,wd.len_vertexes);
    //wd.vertexes = remap_vertexes(wd.vertexes,wd.len_vertexes,bounds); // frees the old version of vertexes
    free(bounds); //won't be used anymore
    return wd;
}

engine initEngine(SDL_Renderer* renderer,const char* path){
    engine engi;
    engi.wadPath = path;
    engi.running = true;
    engi.renderer = renderer;
    engi.wData = initWadDATA(path);
    return engi;
}

void draw(engine engi){
    draw_linedefs(engi.renderer,engi.wData.linedefs,engi.wData.len_linedefs,engi.wData.vertexes);
    draw_vertexes(engi.renderer,engi.wData.vertexes,engi.wData.len_vertexes);
    SDL_RenderPresent(engi.renderer);
}

int main(int argc, char* argv[]){
    if (argc < 2) exit(-1);
    // SDL_Window* window;
    // SDL_Renderer* renderer;
    // int status = start_SDL(&window,&renderer,WIDTH,HEIGHT,"Map rendering..");
    // if (status == 1){
    //     printf("Error at SDL startup");
    //     exit(-1);
    // }
    SDL_Renderer* renderer;
    engine engi = initEngine(renderer,argv[1]);
    SDL_Event e;
    for (int i = 0; i < engi.wData.len_vertexes; i++){
        vertex v = engi.wData.vertexes[i];
        printf("Vertex %d : (x,y) = (%d,%d)\n\n",i,v.x,v.y);
    }
    // while (engi.running) {
    //     SDL_PollEvent(&e);
    //     draw(engi);
    //     switch (e.type) {
    //     case SDL_QUIT:
    //         engi.running = false;
    //         break;
    //     case SDL_KEYDOWN:
    //         switch (e.key.keysym.sym) {
    //         case SDLK_ESCAPE:
    //             engi.running = false;
    //             break;
    //         case SDLK_q:
    //             engi.running = false;
    //         default:
    //             break;
    //         }
    //     default:
    //         break;
    //     }
    //     SDL_Delay(100);
    // }
    free(engi.wData.vertexes);
    free(engi.wData.linedefs);
    free(engi.wData.header.wad_type);
    return 0;
}