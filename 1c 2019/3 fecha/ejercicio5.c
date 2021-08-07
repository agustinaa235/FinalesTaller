/*
**5) Escriba una rutina que dibuje las dos diagonales de la pantalla en color rojo..**
*/
#include <SDL2/SDL.h>
#include <SDL2/SDL2_gfxPrimitives.h>
#include <stdio.h>

#define WIDTH 640
#define HEIGHT 480
#define N 7

int main(int argc, char** argv){
    SDL_Window* ventana = SDL_CreateWindow("SDL_GRAFICA", 100, 100, WIDTH, HEIGHT, SDL_WINDOW_OPENGL);
    SDL_Renderer* render = SDL_CreateRenderer(ventana, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    SDL_Event event;
    int salir = 0;

    while (!salir){
        if (SDL_PollEvent(&event)){
            if (event.type == SDL_QUIT){
                salir = 1;
            }
        }

        SDL_SetRenderDrawColor(render, 0, 0, 0, 0);
        SDL_RenderClear(render);

        lineRGBA(render, 0, 0 , WIDTH, HEIGHT, 0xff, 0x00, 0x00, 0xff);
        lineRGBA(render, WIDTH, 0, 0, HEIGHT, 0xff, 0x00, 0x00, 0xff);
        SDL_RenderPresent(render);
        SDL_Delay(10);
    }
    SDL_DestroyRenderer(render);
    SDL_DestroyWindow(ventana);
    SDL_Quit();
    return 0;
}
