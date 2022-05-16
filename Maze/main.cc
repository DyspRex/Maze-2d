#include <iostream>
#include <SDL.h>
#include <SDL_main.h>

#include "Map.h"
#include "Window.h"

int main(int argc, char** argv) {
  SDL_Init(SDL_INIT_EVERYTHING);
  std::cout << "start" << std::endl;
  
  /*Map m1 {"map.txt"};
    for (int y = 0; y < m1.height(); ++y) { 
	for (int x = 0; x < m1.width(); ++x) {
		std::cout <<
				((m1.is_wall(x, y)) ? "\u2588\u2588" : "\u2591\u2591")
	}
	std::cout << std::endl;
  }*/
  
  Window w {720, 480};
//  Window w {1080, 720};
//  Window w {2560, 1440};
  w.main_loop();
  
  
  std::cout << "end" << std::endl;
  return 0;
}