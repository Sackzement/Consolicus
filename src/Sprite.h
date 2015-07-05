#pragma once

#include <SDL2/SDL_video.h>
#include <string>
#include "Size.h"
#include "Object.h"
#include "Transform.h"
using namespace std;


/*
getPixel(x,y)
setPixel(x,y)
*/

class Sprite : public Object , public Transform
{
public:
    
                    Sprite          ( string filename ) ;
                    Sprite          ( int w = 1, int h = 1 ) ;
    virtual        ~Sprite          ();
    
    void            renderTo        ( SDL_Surface *  renSurf );
virtual void        printData       ();
  /*void            show            ();
    void            hide            ();*/
    
    
protected:
    SDL_Surface *   m_sdlSurface;
    Uint32            getPixel ( uint x, uint y );
    Uint32            setPixel ( uint x, uint y, Uint32 col );
    Uint32*           pixel;
    
    
    bool            existsSdlSurface ();
    

};

