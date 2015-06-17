#include "Game.h"
#include "Console.h"
#include <iostream>


        Game::    Game()
{
    create();
}
void    Game::    loadStuff()
{
    m_sprites.push_back( new Sprite("ululu.png") );
}
void    Game::    mainloop()
{
    while ( isRunning() )
    {
        input();
        
        //update();
        
        //render();
    }
}
        Game::   ~Game()
{
    destroy();
}

void    Game::    create()
{
    m_window   = new Window();
    m_console  = new Console(this);
    m_sprites  = vector<Sprite *> ();
    
    m_running  = true;
}
void    Game::    destroy()
{
    delete  m_window;
    delete  m_console;
    m_window  = NULL;
    m_console = NULL;
    
    for ( Sprite * sprite : m_sprites )     delete sprite;
    m_sprites.clear();
    
    m_running = false;
}
bool    Game::    isRunning()
{
    return m_running;
}

void    Game::    reset()
{
    destroy();
    create();
}
void    Game::     quit()
{
    cout << "\nGame\tquitting" ;
    m_running = false;
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
            if ( ev.key.repeat == 0 )       interpretKey( ev.key );
            break;
    }
}
void    Game::    interpretKey( SDL_KeyboardEvent key )
{
    if ( key.keysym.sym == SDLK_ESCAPE  &&  ! m_console->isOpen() )
        quit();
    else
        m_console->input( key );
}