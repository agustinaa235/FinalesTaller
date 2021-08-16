
/* descirbua una rutina con un cuadrado amarillo centrado y de 1/ 3 de alto */

#include <SDL2/SDL.h>
#include <SDL2/SDL2_gfxPrimitives.h>

#define WIDTH 440
#define HEIGHT 440

int main(){
    SDL_Window* window = SDL_CreateWindow("circulo amarillo", 100, 100, WIDTH, HEIGHT, SDL_WINDOW_OPENGL);
    SDL_Renderer* render = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED| SDL_RENDERER_PRESENTVSYNC);
    SDL_Event e;
    int quit =0;
    while(!quit){
        if (!SDL_PollEvent(&e)){
            if (e.type == SDL_QUIT){
                quit = 1;
            }
        }
        SDL_SetRenderDrawColor(render, 0, 0, 0, 0);
        SDL_RenderClear(render);
        // el box te lo deja arriba a la esquina
        //boxRGBA(render, WIDTH / 3, HEIGHT/3, WIDTH*(2/3), HEIGHT*(2/3), 0xff, 0xff, 0x00, 0xff);
        lineRGBA(render, WIDTH / 3, HEIGHT / 3, (WIDTH*2)/3, HEIGHT / 3, 0xff, 0xff, 0x00, 0xff);
        lineRGBA(render, WIDTH / 3, HEIGHT / 3, WIDTH / 3, (HEIGHT*2) / 3, 0xff, 0xff, 0x00, 0xff);
        lineRGBA(render, WIDTH / 3, (HEIGHT*2)/3, (WIDTH*2)/3, (HEIGHT*2)/3, 0xff, 0xff, 0x00, 0xff);
        lineRGBA(render, (WIDTH*2)/3, HEIGHT /3 , (WIDTH*2)/3, (HEIGHT*2)/3, 0xff, 0xff, 0x00, 0xff);
        SDL_RenderPresent(render);
        SDL_Delay(10);
    }
    SDL_DestroyRenderer(render);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
