#include "Sprite.h"
#include "Mask.h"
#include <iostream>
#include <SDL2_image/SDL_image.h>




            Sprite::    Sprite          ( string filename ) : Object(ot_sprite)
{
    create(filename);
}
            Sprite::    Sprite          ( int w, int h )    : Object(ot_sprite)
{
    create(w,h);
}
            Sprite::   ~Sprite          ()
{
    SDL_FreeSurface(m_sdlSurface);
    m_sdlSurface = NULL;
}

/*void        Sprite::    show            ()
{
    
}
void        Sprite::    hide            ()
{
    
}*/

void        Sprite::    printData       ()
{
    if ( ! existsSdlSurface() )
    {
        cout << "\nm_sdlSurface\t== NULL" ;
        return;
    }
    
    cout << "\nSprite Data" ;
    cout << "\nName\t" << getName() ;
    
    SizeRect size = getSize();
    cout << "\nResolution\t" << size.w() << " " << size.h() ;

}

SizeRect    Sprite::    getSize         ()
{
    if ( ! existsSdlSurface() )  return  SizeRect();
    else                         return  SizeRect( m_sdlSurface->w, m_sdlSurface->h );
}


void        Sprite::    create          ( string filename )
{
    m_sdlSurface = IMG_Load( filename.c_str() );
    
    if( ! existsSdlSurface() )
        cout << "Error:\t" << IMG_GetError() ;
}
void        Sprite::    create          ( int w, int h )
{
    m_sdlSurface = SDL_CreateRGBSurface( 0, w, h, 32,
                                   mask_red, mask_green, mask_blue, mask_alpha ) ;
    if( ! existsSdlSurface() )
        cout << "CreateRGBSurface failed:\t", SDL_GetError() ;
}
bool        Sprite::    existsSdlSurface ()
{
    if ( m_sdlSurface )  return true;
    else                 return false;
}
