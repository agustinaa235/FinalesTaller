
#include <SDL2/SDL.h>
#include <SDL2/SDL2_gfxPrimitives.h>

#define WIDTH 440
#define HEIGHT 440

int main(){

    SDL_Window* window = SDL_CreateWindow("rombo_verde", 100, 100, WIDTH,
    HEIGHT, SDL_WINDOW_OPENGL);
    SDL_Renderer* render = SDL_CreateRenderer(window, -1,
    SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    SDL_Event e;
    const short rombo_x [] ={WIDTH / 2, WIDTH *3/4, WIDTH / 2, WIDTH /4};
    const short rombo_y[] = {HEIGHT/4, HEIGHT / 2, HEIGHT*3/4, HEIGHT /2};
    int rombo_n_puntos = sizeof(rombo_x) / sizeof(rombo_x[0]);
    int quit = 0;
    while (!quit){
        if (SDL_PollEvent(&e)){
            if (e.type == SDL_QUIT){
                quit = 1;
            }
        }
        SDL_SetRenderDrawColor(render, 0, 0, 0, 0);
        SDL_RenderClear(render);
        polygonRGBA(render, rombo_x, rombo_y, rombo_n_puntos, 0x00, 0xff, 0x00,
        0xff);
        SDL_RenderPresent(render);
        SDL_Delay(10);
    }
    SDL_DestroyRenderer(render);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
