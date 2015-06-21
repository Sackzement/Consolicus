#include "Game.h"
#include "Console.h"
#include <iostream>


Game::    Game() : Program()
{
    m_window  = nullptr ;
    m_console = nullptr ;
}
void    Game::    init()
{
    
    if ( SDL_Init( SDL_INIT_EVERYTHING ) != 0 )
    {
        cout << "\nError:\t" << SDL_GetError() ;
        return ;
    }
    
    m_console  = new Console(this) ;
    m_window   = new Window() ;
    
    addChild( new Sprite() ) ;
    addChild( new Sprite("ululu.png") ) ;

}
        Game::   ~Game()
{
    if ( m_window != nullptr )
        delete  m_window;
    m_window  = nullptr ;
    if ( m_console != nullptr )
        delete  m_console;
    m_console = nullptr ;
    
}

void    Game::    input()
{
    
    SDL_Event ev;
    while ( SDL_PollEvent(&ev) != 0 )
        
    switch(ev.type)
    {
        // INPUT ---------------------------------------
        case SDL_EventType::SDL_QUIT:
            quit();
            break;
            
        case SDL_EventType::SDL_KEYDOWN:
            if ( ev.key.repeat == 0 )       inputKeyDown( ev.key );
            break;
    }
    
}

void    Game::    update()
{
    
}
void    Game::    render()
{
    
}
void    Game::    inputKeyDown( SDL_KeyboardEvent key )
{
    if ( key.keysym.sym == SDLK_ESCAPE  &&  ! m_console->isOpen() )
        quit();
    else
        m_console->input( key );
}