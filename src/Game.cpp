#include "Game.h"
#include "Console.h"
#include <iostream>


        Game::    Game() : Program()
{
    m_window  = nullptr ;
    m_console = nullptr ;
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


void    Game::    init()
{
    setFPS(60);
    
    m_console  = new Console(this) ;
    m_window   = new Window() ;
    
    m_window->addChild( new Sprite("res/ululu.bmp") ) ;
    m_window->addChild( new Sprite("res/cat.png") ) ;

}
void    Game::    input()
{
    
    SDL_Event ev;
    while ( SDL_PollEvent(&ev) != 0 )
        
    switch(ev.type)
    {
        case SDL_EventType::SDL_QUIT:
            quit();
            break;
            
        case SDL_EventType::SDL_KEYDOWN:
            inputKeyDown( ev.key );
            break;
    }
    
}
void    Game::    update()
{
    
}
void    Game::    render()
{
    m_window->render();
}


void    Game::    inputKeyDown( SDL_KeyboardEvent key )
{
    
    if ( key.repeat != 0 )  return;
    
    if ( key.keysym.sym == SDLK_ESCAPE  &&  ! m_console->isOpen() )
        quit();
    else
        m_console->input( key );
    
}