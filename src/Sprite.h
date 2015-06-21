#pragma once

#include <SDL2/SDL_video.h>
#include <string>
#include "Size.h"
#include "Object.h"
using namespace std;






class Sprite : public Object
{
private:    // PRIVATE ======================
    // VARIABLES --------------------
    SDL_Surface *   m_sdlSurface;
    // FUNCTIONS --------------------
    void            create          ( string filename ) ;
    void            create          ( int w = 1, int h = 1 ) ;
    bool            existsSdlSurface ();
public:     // PUBLIC =======================
    // FUNCTIONS --------------------
                    Sprite          ( string filename ) ;
                    Sprite          ( int w = 1, int h = 1 ) ;
    virtual        ~Sprite          ();
    
    /*void            show            ();
    void            hide            ();*/
    
    void            printData       ();
    
    SizeRect        getSize         ();
    /*
    void            setRes          ( int w, int h );*/
    
};

