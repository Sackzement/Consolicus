#pragma once

//#include <SDL2/SDL.h>
#include <SDL2/SDL.h>
#include <string>
#include "Size.h"
#include "Object.h"

using namespace std;





class Window : public Object
{
    
public:
                    Window          ();
    virtual        ~Window          ();
    
    void            render          ();
    virtual void    printData       ();
    virtual void    printData2      ();
    void            show            ();
    void            hide            ();
    string          getTitle        ();
    SizeRect        getRes          ();
    
    void            setTitle        ( string t );
    void            setRes          ( int w, int h );
    void            toggleFullScreen();
    
private:
    bool            existsSdlWindow ();
    
    
    
    SDL_Window *    m_sdlWin;
    
};

