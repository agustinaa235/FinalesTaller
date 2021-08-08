/*
** Escriba una rutina dibuje un triángulo amarillo del tamaño de la ventana **
 */


 #include <SDL2/SDL.h>
 #include <SDL2/SDL2_gfxPrimitives.h>
 #include <stdio.h>

#define WIDTH 640
#define HEIGHT 480

 int main(){
    SDL_Window* window = SDL_CreateWindow("triangulo", 100, 100, WIDTH, HEIGHT,
                                          SDL_WINDOW_OPENGL);
    SDL_Renderer* render = SDL_CreateRenderer(window, -1,
                                              SDL_RENDERER_ACCELERATED |
                                              SDL_RENDERER_PRESENTVSYNC);
    SDL_Event e;
    int salir = 0;
    const short rombo_x[] = { WIDTH / 2, WIDTH, WIDTH / 2, 0 };
    const short rombo_y[] = { 0, HEIGHT / 2, HEIGHT, HEIGHT / 2 };
    const int rombo_n_puntos = sizeof(rombo_x) / sizeof(rombo_x[0]);

    const short triangulo_x [] = {WIDTH/2, WIDTH, 0};
    const short triangulo_y [] = {0, HEIGHT -1, HEIGHT -1};
    const int triangulo_n_puntos = sizeof(triangulo_x)/ sizeof(rombo_x[0]);
    while (!salir){
        if (SDL_PollEvent(&e)){
            if (e.type == SDL_QUIT){
                salir = 1;
            }
        }
        SDL_SetRenderDrawColor(render, 0, 0, 0, 0);
        SDL_RenderClear(render);

        polygonRGBA(render, triangulo_x, triangulo_y, triangulo_n_puntos, 0xff, 0xff, 0x00, 0xff);
        SDL_RenderPresent(render);
        SDL_Delay(10);
    }
    SDL_DestroyRenderer(render);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
 }
