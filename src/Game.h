#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_video.h>
#include <vector>
#include "Window.h"
#include "Sprite.h"
#include "Console.h"






class Game
{
    
    friend class Console;
    
private:    // PRIVATE ==========================================
            // VARIABLES ----------------------------------------
    Window  *   m_window;
    Console *   m_console;
    bool        m_running;
    vector<Sprite *>  m_sprites;
            // FUNCTIONS ----------------------------------------
    void        create();
    void        destroy();
    bool        isRunning();
    void        reset();
    void        quit();
    void        input();
    void        interpretKey( SDL_KeyboardEvent key );
public:     // PUBLIC ===========================================
            // FUNCTIONS ----------------------------------------
                Game();
    void        loadStuff();
    void        mainloop();
    virtual    ~Game();

};

