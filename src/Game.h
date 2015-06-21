#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_video.h>
#include "Window.h"
#include "Sprite.h"
#include "Console.h"
#include "Program.h"






class Game : public Program
{
    
    friend class Console;
    
private:    // PRIVATE ==========================================
            // VARIABLES ----------------------------------------
    Window  *   m_window;
    Console *   m_console;
            // FUNCTIONS ----------------------------------------
    void        create();
    void        destroy();
    void        init();
    void        input();
    void        update();
    void        render();
    void        inputKeyDown( SDL_KeyboardEvent key );
public:
                Game();
    virtual    ~Game();

};

