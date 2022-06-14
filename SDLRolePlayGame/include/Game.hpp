#pragma once

#include "SDL.h"
#include <iostream>
#include "SDL_image.h"
#include <fstream>
#include <filesystem>
namespace fs = std::filesystem;


class Game {

public:
    Game();
    ~Game();

    void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
    
    std::filesystem::path prepend_exe_path(const std::string& filename, const std::string& exe_path = "");

    int hello(){return 5;}
    void handleEvents();
    void update();
    void render();
    void clean();
    bool running() const { return isRunning;}
    
    static SDL_Renderer *renderer;
    static fs::path exeParentPath;

private:
    bool isRunning;
    SDL_Window *window;
    //since there are pointers used here a copy constructor and destructor along with copy assignment constructor is needed
};
