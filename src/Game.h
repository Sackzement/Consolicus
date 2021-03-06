#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_video.h>
#include "Window.h"
#include "Sprite.h"
#include "Console.h"
#include "Program.h"
#include "Key.h"
#include "tobi.h"






class Game : public Program
{
    
    friend class Console;
    
public:
                Game();
    virtual    ~Game();
    
private:
    void        init();
    void        input();
    void        update();
    void        render();
    
    void        inputKeyDown( SDL_KeyboardEvent sdlKeyEv );
    void        fingerEvent( SDL_TouchFingerEvent tfEv );
    
    
    
    Window  *   m_window;
    Console *   m_console;
    Tobi *      m_tobi;


};

