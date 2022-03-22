#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>
#include <glm/glm.hpp>
#include <imgui/imgui.h>
#include <sol/sol.hpp>

int main() {
	sol::state lua;
	lua.open_libraries(sol::lib::base);
	std::cout << "Starting project!" << std::endl;
	return 0;
}
