#include "player.hpp"

#include <SDL3/SDL.h>
#include <SDL3/SDL_scancode.h>

Player::Player(SDL_FPoint position, float radius, float speed)
             : position_(position), radius_(radius), speed_(speed) {}

void Player::movement(const bool* state, float delta) {
  if (state[SDL_SCANCODE_A]) {
    position_.x -= speed_ * delta;
  }

  else if (state[SDL_SCANCODE_D]) {
    position_.x += speed_ * delta;
  }

  if (state[SDL_SCANCODE_W]) {
    position_.y -= speed_ * delta;
  }

  else if (state[SDL_SCANCODE_S]) {
    position_.y += speed_ * delta;
  }
}

void Player::rotate(const bool* state, float delta) {

}

void Player::render(SDL_Renderer* renderer) {
  SDL_SetRenderDrawColor(renderer, color_.r, color_.g, color_.b, color_.a);
  SDL_FRect rect{position_.x-radius_, position_.y-radius_, radius_*2, radius_*2};
  SDL_RenderFillRect(renderer, &rect);
}
