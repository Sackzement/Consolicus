#pragma once

//#include <SDL2/SDL.h>
#include <SDL2/SDL.h>
#include <string>
#include "Size.h"

using namespace std;





class Window
{
private:    // PRIVATE ======================
            // VARIABLES --------------------
    SDL_Window *    m_sdlWin;
            // FUNCTIONS --------------------
    void            create          ();
    void            destroy         ();
    bool            existsSdlWindow ();
public:     // PUBLIC =======================
            // FUNCTIONS --------------------
                    Window          ();
                   ~Window          ();
    
    void            reset           ();
    void            show            ();
    void            hide            ();
    
    void            printSettings   ();
    
    string          getTitle        ();
    SizeRect        getRes          ();
    
    void            setTitle        ( string t );
    void            setRes          ( int w, int h );

    
};

