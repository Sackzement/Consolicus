#include "Window.h"
#include <iostream>
#include <SDL2/SDL.h>


Window::             Window     ()
{
    create();
}
Window::            ~Window     ()
{
    destroy();
}

void     Window::    reset      ()
{
    destroy();
    create();
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

void     Window::    printSettings()
{
    if ( ! existsSdlWindow() )
    {
        cout << "\nm_sdlWindow\t== NULL" ;
        return;
    }
    
    cout << "\nWindow Settings" ;
    cout << "\nTitle\t" << getTitle() ;
    
    SizeRect size = getRes();
    cout << "\nResolution\t" << size.w() << " " << size.h() ;
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


void     Window::    create     ()
{
    if ( ! SDL_WasInit(SDL_INIT_VIDEO) )     SDL_InitSubSystem(SDL_INIT_VIDEO) ;
    
    m_sdlWin = SDL_CreateWindow ( "ululu", 0, 0, 400, 300, SDL_WindowFlags::SDL_WINDOW_SHOWN );
    
    if( ! existsSdlWindow() )
        cout << "\nCreateWindow failed:\t", SDL_GetError() ;

}
void     Window::    destroy    ()
{
    SDL_DestroyWindow(m_sdlWin);
    m_sdlWin = NULL;
}
bool     Window::existsSdlWindow()
{
    if ( m_sdlWin )  return true;
    else             return false;
}