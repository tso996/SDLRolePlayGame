#include "Game.hpp"
#include <unistd.h>
#include "TextureManager.h"
#include "GameObject.h"

GameObject* player1;
GameObject* player2;
fs::path Game::exeParentPath;

SDL_Renderer* Game::renderer = nullptr;

Game::Game(){
    //default constructor
}

Game::~Game(){
    //default destructor
}

fs::path Game::prepend_exe_path(const std::string& filename, const std::string& exe_path)
{
    Game::exeParentPath = fs::path(exe_path).parent_path();
    return Game::exeParentPath / filename;
}

void Game::init(const char *title, int xpos, int ypos, int width, int height, bool fullscreen){
    int flags = 0;
    if(fullscreen){
        flags = SDL_WINDOW_FULLSCREEN;
    }

    if(SDL_Init(SDL_INIT_EVERYTHING) == 0){
        std::cout<< "subsystems are initialised.."<<std::endl;
        window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
        if(window){
            std::cout<<"Window is ready.."<<std::endl;
        }
        
        renderer = SDL_CreateRenderer(window, -1, 0);
        if(renderer){
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            std::cout<<"Render is ready.."<<std::endl;
        }

        isRunning = true;
    
    }else{
        std::cout<<"subsystems ecountered a problem.."<<std::endl;
        isRunning = false;
    }

    char cwd[256];
    
#if defined DEBUG
    std::cout<<"debug build"<<std::endl;
#else
    std::cout<<"release build"<<std::endl;
    std::filesystem::current_path(Game::exeParentPath);//if it is release build, then we change the current working directory to the parent path of where the executable file is located
    std::cout<<"the current working directory has been changed to the executable file path.."<<std::endl;
#endif
    
    getcwd(cwd, 256);
    std::string cwd_str = std::string(cwd);
    std::cout<<"current directory: "<<cwd_str<<std::endl;

    
    std::cout<<"exe parent path: "<<Game::exeParentPath<<std::endl;
    
    std::string myFile = cwd_str + "/SDLRolePlayGame/Assets/ArcherSprites/archer_idle_right1@2x.png";//This gets found during run time. The #include paths are during compilation. That's why they need paths from the file level and this only needs from the project level. From the getcwd. However the executable is in a deeper folder so it's still not evident.
    std::cout<<"Fixed file path: "<<myFile<<std::endl;
    std::ifstream file(myFile.c_str());
    if (file) {
        player1 = new GameObject("SDLRolePlayGame/Assets/ArcherSprites/archer_idle_right1@2x.png",renderer,0,0);
        player2 = new GameObject("SDLRolePlayGame/Assets/ArcherSprites/archer_idle_right1@2x.png",renderer,100,0);
        std::cout<<"Texture found."<<std::endl;
    }else{
        std::cout<<"Texture not found."<<std::endl;
    }
    file.close(); 
}

void Game::clean(){
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    std::cout<<"Clean complete.."<<std::endl;
}

void Game::handleEvents(){
    SDL_Event event;
    SDL_PollEvent(&event);
    switch (event.type) {
        case SDL_QUIT:
            std::cout<<"Closing window.."<<std::endl;
            isRunning = false;
            break;
        default:
            break;
    }
}

void Game::render(){
    SDL_RenderClear(renderer);
    //we add stuff to render here
    //whatever is rendered first is going to be behind recent renders
    //so render tilemaps first
    // SDL_RenderCopy(renderer, playerTexture, NULL, &dstR);//The 2 nulls are source rectangle and destination rectangle
    player1->render();
    player2->render();

    SDL_RenderPresent(renderer);
}

void Game::update(){
    player1->update();
    player2->update();
}

