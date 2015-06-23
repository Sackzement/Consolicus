#include "Window.h"
#include <iostream>
#include <SDL2/SDL.h>
#include "Sprite.h"


Window::             Window     () : Object(ot_window)
{
    
    if ( ! SDL_WasInit(SDL_INIT_VIDEO) )
    {
        if ( SDL_InitSubSystem(SDL_INIT_VIDEO) != 0 )
        {
            cout << "\nError:\t" << SDL_GetError() ;
            return ;
        }
    }
    
    m_sdlWin = SDL_CreateWindow ( "ululu", 0, 0, 400, 300, SDL_WindowFlags::SDL_WINDOW_SHOWN );
    
    if( ! existsSdlWindow() )
        cout << "\nCreateWindow failed:\t", SDL_GetError() ;
    
}
Window::            ~Window     ()
{
    SDL_DestroyWindow(m_sdlWin);
    m_sdlWin = nullptr;
}


void     Window::    render     ()
{
    
    if ( ! existsSdlWindow() )     return;
    
    vector<Object*>& chs = getChildren();
    for ( Object* obj : chs )
    {
        if ( obj->getType() == ot_sprite )
        {
            Sprite* sp = (Sprite*)obj;
            sp->renderTo( SDL_GetWindowSurface(m_sdlWin) ) ;
        }
    }
    
    SDL_UpdateWindowSurface( m_sdlWin );
    
}
void     Window::    printData()
{
    
    printNameAndType();
    
    
    if ( existsSdlWindow() )
    {
        cout << '\n' << getTitle() ;
    
        SizeRect size = getRes();
        cout << '\n' << size.w() << " " << size.h() ;
    }
    
    printParentAndChildren() ;
    
}
void     Window::    show       ()
{
    if ( ! existsSdlWindow() )     return;
    
    cout << "\nWindow\tshowing" ;
    SDL_ShowWindow(m_sdlWin);
}
void     Window::    hide       ()
{
    if ( ! existsSdlWindow() )     return;
        
    cout << "\nWindow\thiding" ;
    SDL_HideWindow(m_sdlWin);
}
string   Window::    getTitle   ()
{
    string ret = "";
    
    if ( ! existsSdlWindow() )
        return ret;
    
    const char * title = SDL_GetWindowTitle(m_sdlWin);
    if (title != NULL)
        ret += title;
    
    return ret;
}
SizeRect Window::    getRes     ()
{
    SizeRect res= SizeRect();
    
    if ( ! existsSdlWindow() )
        return res;
    
    SDL_GetWindowSize( m_sdlWin, &res.w(), &res.h() );
    
    return res;
}


void     Window::    setTitle   ( string t )
{
    if ( ! existsSdlWindow() )
        return;
    
    SDL_SetWindowTitle( m_sdlWin, t.c_str() );
}
void     Window::    setRes     ( int w, int h )
{
    if ( ! existsSdlWindow() )
        return;
    
    SDL_SetWindowSize(m_sdlWin, w, h);
}



bool     Window::    existsSdlWindow()
{
    if ( m_sdlWin != nullptr )  return true;
    else                        return false;
}


