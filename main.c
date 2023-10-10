#include <SDL2/SDL.h>
#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>

#define WIDTH 800
#define HEIGHT 600
#define FULLSCREEN false

void sdl_init(SDL_Window **window, SDL_Renderer **renderer) {
    SDL_Init(SDL_INIT_VIDEO);
    uint32_t window_flags = FULLSCREEN ? SDL_WINDOW_FULLSCREEN : 0;
    SDL_CreateWindowAndRenderer(WIDTH, HEIGHT, window_flags, window, renderer);
    SDL_SetRenderDrawColor(*renderer, 0, 0, 0, 0);
    SDL_RaiseWindow(*window);
    SDL_RenderClear(*renderer);
    SDL_RenderPresent(*renderer);
}

void sdl_quit(SDL_Window *window, SDL_Renderer *renderer) {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

int main(int argc, char **argv) {
    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Event event;
    sdl_init(&window, &renderer);
    
    for (;;) {
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_QUIT:
                    sdl_quit(window, renderer);
                    return 0;
                /* case OUTROS_EVENTOS: */
                /*     lidar com outros eventos, como mouse, teclado, janela, etc */
            }
        }
        /* limpar e desenhar tela */
        /* atualizar estado */
    } 
}

