 /* Escriba una rutina que dibuje un rombo verde que ocupe toda la ventana. */


 #include <SDL2/SDL.h>
 #include <SDL2/SDL2_gfxPrimitives.h>
 #include <stdio.h>
#define WIDTH 680
#define HEIGHT 440

 int main(){
    SDL_Window* window = SDL_CreateWindow("ejercicio rombo", 100, 100, WIDTH, HEIGHT, SDL_WINDOW_OPENGL);
    if (!window){
        return 0;
    }
    SDL_Renderer* render = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (!render){
        SDL_DestroyWindow(window);
        SDL_Quit();
    }
    SDL_Event event;
    int quit = 0;
    const short rombo_x [] = {WIDTH / 2, WIDTH, WIDTH / 2, 0};
    const short rombo_y [] = {0, HEIGHT / 2, HEIGHT, HEIGHT / 2};
    const int rombo_n_puntos = sizeof(rombo_x) / sizeof(rombo_x[0]);
    while (!quit){
        if (SDL_PollEvent(&event)){
            if (event.type == SDL_QUIT){
                quit = 1;
            }
        }
        SDL_SetRenderDrawColor(render, 0, 0 , 0, 0);
        SDL_RenderClear(render);
        polygonRGBA(render, rombo_x, rombo_y, rombo_n_puntos, 0x00, 0xff, 0x00, 0xff);

        SDL_RenderPresent(render);
        SDL_Delay(10);
    }
    SDL_DestroyRenderer(render);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
 }
