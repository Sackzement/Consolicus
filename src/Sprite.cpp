#include "Sprite.h"
#include "Mask.h"
#include <iostream>
#include <SDL2_image/SDL_image.h>




            Sprite::    Sprite          ( string filename ) : Object(ot_sprite)
{
    
    m_sdlSurface = IMG_Load( filename.c_str() );
    
    if( ! existsSdlSurface() )
        cout << "Error:\t" << IMG_GetError() ;
    
}
            Sprite::    Sprite          ( int w, int h )    : Object(ot_sprite)
{
    
    m_sdlSurface = SDL_CreateRGBSurface( 0, w, h, 32,
                                        mask_red, mask_green, mask_blue, mask_alpha ) ;
    if( ! existsSdlSurface() )
        cout << "CreateRGBSurface failed:\t", SDL_GetError() ;
    
}
            Sprite::   ~Sprite          ()
{
    SDL_FreeSurface(m_sdlSurface);
    m_sdlSurface = nullptr;
}


void        Sprite::    renderTo        ( SDL_Surface *  renSurf )
{
    
    if ( m_sdlSurface == nullptr  ||  renSurf == nullptr )
        return;
    
    SDL_Rect rect;
    rect.x = pos.x;
    rect.y = pos.y;
    rect.w = size.w * m_sdlSurface->w ;
    rect.h = size.h * m_sdlSurface->h ;
    
    SDL_BlitSurface( m_sdlSurface, &rect, renSurf, NULL );
    
}
void        Sprite::    printData       ()
{
    
    printNameAndType();
    
    if ( existsSdlSurface() )
        cout << '\n' << size.w << " " << size.h ;
    
    printParentAndChildren();

}
/*void        Sprite::    show            ()
 {
 
 }
 void        Sprite::    hide            ()
 {
 
 }*/

bool        Sprite::    existsSdlSurface ()
{
    if ( m_sdlSurface )  return true;
    else                 return false;
}


