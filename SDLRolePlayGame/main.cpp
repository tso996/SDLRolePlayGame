#include "Game.hpp"


Game *game = nullptr;

int main(int argc, char* argv[]){

    const int FPS = 60;
    const int frameDelay = 1000/FPS;

    Uint32 frameStart;
    int frameTime;

    game = new Game();
    (void) game->prepend_exe_path("", argv[0]);//casting the return type as void..
    
    

    game->init("One Fighter", SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,800,640,false);
    while(game->running()){
        frameStart = SDL_GetTicks();

        game->handleEvents();
        game->update();
        game->render();
        
        frameTime = SDL_GetTicks() - frameStart;

        if(frameDelay>frameTime){
            SDL_Delay(frameDelay - frameTime);
        }
    }

    game->clean();
    std::cout<<"Quitting.."<<std::endl;


    return 0;
}
