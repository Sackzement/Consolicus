#pragma once

#include <SDL2/SDL_video.h>
#include <string>
#include "Size.h"
using namespace std;






class Sprite
{
private:    // PRIVATE ======================
    // VARIABLES --------------------
    SDL_Surface *   m_sdlSurface;
    string          m_name;
    // FUNCTIONS --------------------
    void            create          ( string filename ) ;
    void            create          ( int w = 1, int h = 1 ) ;
    void            destroy         ();
    bool            existsSdlSurface ();
public:     // PUBLIC =======================
    // FUNCTIONS --------------------
                    Sprite          ( string filename ) ;
                    Sprite          ( int w = 1, int h = 1 ) ;
                   ~Sprite          ();
    
    void            reset           ();
    /*void            show            ();
    void            hide            ();*/
    
    void            printData       ();
    
    string          getName         ();
    SizeRect        getSize         ();
    
    /*void            setName         ( string t );
    void            setRes          ( int w, int h );*/
    
};

