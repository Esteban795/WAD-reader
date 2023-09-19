#include "../headers/map_renderer.h"


int max(int a, int b){
    return a > b ? a : b;
}

int min(int a, int b){
    return a < b ? a : b;
}
void DrawCircle(SDL_Renderer* renderer, int32_t centreX, int32_t centreY, int32_t radius){
   const int32_t diameter = (radius * 2);
   int32_t x = (radius - 1);
   int32_t y = 0;
   int32_t tx = 1;
   int32_t ty = 1;
   int32_t error = (tx - diameter);
   while (x >= y){
      //  Each of the following renders an octant of the circle
      SDL_RenderDrawPoint(renderer, centreX + x, centreY - y);
      SDL_RenderDrawPoint(renderer, centreX + x, centreY + y);
      SDL_RenderDrawPoint(renderer, centreX - x, centreY - y);
      SDL_RenderDrawPoint(renderer, centreX - x, centreY + y);
      SDL_RenderDrawPoint(renderer, centreX + y, centreY - x);
      SDL_RenderDrawPoint(renderer, centreX + y, centreY + x);
      SDL_RenderDrawPoint(renderer, centreX - y, centreY - x);
      SDL_RenderDrawPoint(renderer, centreX - y, centreY + x);
      if (error <= 0){
        ++y;
        error += ty;
        ty += 2;
      }
      if (error > 0){
        --x;
        tx += 2;
        error += (tx - diameter);
      }
   }
}

/*
map_bounds[0] = min_x
map_bounds[1] = max_x
map_bounds[2] = min_y
map_bounds[3] = max_y
*/
int* get_map_bounds(vect2* vertexes, int len){
    int* map_bounds = malloc(sizeof(int) * 4);
    map_bounds[0] = vertexes[0].x;
    map_bounds[1] = vertexes[0].x;
    map_bounds[2] = vertexes[0].y;
    map_bounds[3] = vertexes[0].y;
    for (int i = 1; i < len;i++){
        if (vertexes[i].x < map_bounds[0]){
            map_bounds[0] = vertexes[i].x;
        }
        else if (vertexes[i].x > map_bounds[1]){
            map_bounds[1] = vertexes[i].x;
        }
        if (vertexes[i].y < map_bounds[2]){
            map_bounds[2] = vertexes[i].y;
        }
        if (vertexes[i].y > map_bounds[3]){
            map_bounds[3] = vertexes[i].y;
        }
    }
    return map_bounds;
}

//remap to keep proportions
int remap_x(int current_x, int x_min, int x_max){
    return (max(x_min, min(current_x, x_max)) - x_min) * (OUT_MAX_W - OUT_MIN) / (x_max - x_min) + OUT_MIN;
}
// (max(self.x_min, min(n, self.x_max)) - self.x_min) * (out_max - out_min) / (self.x_max - self.x_min) + out_min


int remap_y(int current_y, int y_min, int y_max){
    return HEIGHT - (max(y_min, min(current_y, y_max)) - y_min) * (OUT_MAX_H - OUT_MIN) / (y_max - y_min) - OUT_MIN;
}
//HEIGHT - (max(self.y_min, min(n, self.y_max)) - self.y_min) * (out_max - out_min) / (self.y_max - self.y_min) - out_min
vect2* remap_vertexes(vect2* vertexes, int len, int* map_bounds){
    vect2* remapped_vertexes = malloc(sizeof(vect2) * len);
    for (int i = 0; i < len;i++){
        remapped_vertexes[i].x = remap_x(vertexes[i].x, map_bounds[0], map_bounds[1]);
        remapped_vertexes[i].y = remap_y(vertexes[i].y, map_bounds[2], map_bounds[3]);
    }
    return remapped_vertexes;
}

void draw_linedefs(SDL_Renderer* renderer,linedef* linedefs,int len,vect2* vertexes){
    SDL_SetRenderDrawColor(renderer,255,0,0,255);
    for (int i = 0; i < len; i++){
        vect2 p1 = vertexes[linedefs[i].start_vertex_id];
        vect2 p2 = vertexes[linedefs[i].end_vertex_id];
        SDL_RenderDrawLine(renderer,p1.x,p1.y,p2.x,p2.y);
    }
}

void draw_vertexes(SDL_Renderer* renderer,vect2* vertexes,int len){
    SDL_SetRenderDrawColor(renderer,255,255,255,255);
    for (int i = 0; i < len; i++){
        DrawCircle(renderer,vertexes[i].x,vertexes[i].y,20);
    }
}
