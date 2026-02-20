#pragma once

#include <SDL3/SDL.h>
#include <SDL3/SDL_rect.h>

class Player {
public:
  explicit Player(SDL_FPoint position, float radius, float speed);

  void movement(const bool* state, float delta = 1.0f);
  void rotate(const bool* state, float delta = 1.0f);
  void render(SDL_Renderer* renderer);

  [[nodiscard]] inline SDL_FPoint position() const {
    return position_;
  }

  [[nodiscard]] inline float radius() const {
    return radius_;
  }

  [[nodiscard]] inline float speed() const {
    return speed_;
  }

  [[nodiscard]] inline float angle() const {
    return angle_;
  }

private:
  SDL_FPoint position_{};
  SDL_Color color_{255, 0, 0, 255};
  float radius_{};
  float speed_{};
  float angle_ = 0.0f;
};
