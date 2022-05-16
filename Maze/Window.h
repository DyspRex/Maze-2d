
#ifndef WINDOW_H_
#define WINDOW_H_

#include <SDL.h>
#include <memory>

#include "Map.h"
#include "Player.h"

class Window final {

public:
  static constexpr int    CELL_SIZE         = 10;
  static constexpr int    MAP_OFFSET        = 20;
  static constexpr int    PLAYER_SIZE       = 7;
  static constexpr int    PLAYER_ARROW      = CELL_SIZE;
  static constexpr double PLAYER_WALK_DIST  = 0.03;
  static constexpr double PLAYER_TURN_ANGLE = 0.05;
  
  static constexpr double WALL_HEIGHT = 0.5;
  static constexpr double FOV         = 90.0;

private:
  int _width, _height;
  
  Player                        _player;
  int                           _wall_tex_width;
  int                           _wall_tex_height;
  int                           _door_tex_width;
  int                           _door_tex_height;
  std::shared_ptr<Map>          _map;
  std::shared_ptr<SDL_Window>   _window;
  std::shared_ptr<SDL_Renderer> _renderer;
  std::shared_ptr<SDL_Texture>  _wall_tex;
  std::shared_ptr<SDL_Texture>  _door_tex;
  
  struct {
    bool walk_forward{false};
    bool walk_back{false};
    bool shift_right{false};
    bool shift_left{false};
    bool turn_right{false};
    bool turn_left{false};
  }                             _controls;
  
  void create_window(int w, int h);
  void create_render();
  void draw_minimap(SDL_Renderer *r);
  
  void draw_col(SDL_Renderer *r, SDL_Texture *t,
                int col, int h, int tw, int th, double tx);
  
  void cast_ray(double &rx, double &ry, double dx, double dy);
  
  std::shared_ptr<SDL_Texture> load_texture(const char *filename);

public:
  Window(int w, int h);
  void main_loop();
  void render(SDL_Renderer *r);
  void event(const SDL_Event &e);
  void update();
};

#endif /* WINDOW_H_ */