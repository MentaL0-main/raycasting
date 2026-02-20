#include "player.hpp"
#include <SDL3/SDL.h>
#include <SDL3/SDL_keyboard.h>
#include <SDL3/SDL_render.h>
#include <SDL3/SDL_scancode.h>
#include <iostream>

const char* WINDOW_TITLE = "Raycasting";
constexpr unsigned int WINDOW_WIDTH = 900;
constexpr unsigned int WINDOW_HEIGHT = 600;
constexpr unsigned int WINDOW_HALF_WIDTH = WINDOW_WIDTH / 2;
constexpr unsigned int WINDOW_HALF_HEIGHT = WINDOW_HEIGHT / 2;

SDL_Window* window = nullptr;
SDL_Renderer* renderer = nullptr;

SDL_Event event{};

bool running = true;

bool init();
bool init_sdl();
bool init_window();
bool init_renderer();

void destroy_renderer();
void destroy_window();
void destroy_sdl();
void destroy();

void input();
void logic();
void render();

void mainloop();

Player player(SDL_FPoint{WINDOW_HALF_WIDTH, WINDOW_HALF_HEIGHT}, 12.0f, 4.0f);

int main() {
  if (!init()) {
    std::cerr << "init(): Failed\n";
    goto cleanup;
  }

  mainloop();

  cleanup:
  destroy();
  return 0;
}

bool init() {
  return init_sdl() && init_window() && init_renderer();
}

bool init_sdl() {
  return SDL_Init(SDL_INIT_VIDEO);
}

bool init_window() {
  return window = SDL_CreateWindow(WINDOW_TITLE,
                                   WINDOW_WIDTH,
                                   WINDOW_HEIGHT,
                                   SDL_WINDOW_HIGH_PIXEL_DENSITY);
}

bool init_renderer() {
  return renderer = SDL_CreateRenderer(window, nullptr);
}

void destroy_renderer() {
  if (renderer) SDL_DestroyRenderer(renderer);
}

void destroy_window() {
  if (window) SDL_DestroyWindow(window);
}

void destroy_sdl() {
  SDL_Quit();
}

void destroy() {
  destroy_renderer();
  destroy_window();
  destroy_sdl();
}

void input() {
  while (SDL_PollEvent(&event)) {
    if (event.type == SDL_EVENT_QUIT) {
      running = false;
    }
  }

  const bool* state = SDL_GetKeyboardState(NULL);

  if (state[SDL_SCANCODE_ESCAPE]) {
    running = false;
  }

  player.movement(state);
}

void logic() {
}

void render() {
  SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
  SDL_RenderClear(renderer);

  player.render(renderer);

  SDL_RenderPresent(renderer);
}

void mainloop() {
  while (running) {
    input();
    logic();
    render();

    SDL_Delay(16);
  }
}
