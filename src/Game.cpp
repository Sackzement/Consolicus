#include "Game.h"
#include "Console.h"
#include <iostream>
#include <map>


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


void    Game::    init() //
{
    setFPS(60);
    
    m_console  = new Console(this) ;
    m_window   = new Window() ;
    
    m_window->setRes(2880, 1800);
    
    m_window->addChild( new Sprite("res/ululu.bmp") ) ;
    m_window->addChild( new Sprite("res/cat.png") ) ;

}
void    Game::    input()
{
    
    SDL_Event ev;
    while ( SDL_PollEvent(&ev) != 0 )
        
    switch(ev.type)
    {
        case SDL_QUIT:
            quit();
            break;
            
        case SDL_KEYDOWN:
            inputKeyDown( ev.key );
            break;
        case SDL_FINGERDOWN:
        case SDL_FINGERUP:
        case SDL_FINGERMOTION:
            //fingerEvent( ev.tfinger );
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


void    Game::    inputKeyDown( SDL_KeyboardEvent sdlKeyEv )
{
    
    if ( sdlKeyEv.repeat != 0 )  return;
    
    kb_key k = sdlKeyEv.keysym.sym;
    
    if ( ! m_console->isOpen() )
    {
        if ( k == k_esc )
            quit();
        
        if ( k == k_d )
            m_window->printData2();
            
        if ( k == k_f )
        {
            m_window->toggleFullScreen();
        }
        
        if ( k == k_space)
        {
            int numOfTouchDevs = SDL_GetNumTouchDevices();
            
            cout << "\n numOfTouchDevs =  " << numOfTouchDevs ;
            for(int i=0 ; i<numOfTouchDevs ; ++i)
            {
                SDL_TouchID touchdevid = SDL_GetTouchDevice(i);
                int numOfTouchFingers =  SDL_GetNumTouchFingers (touchdevid);
                cout << "\nTouch Dev " << i << "  numOfTouchFingers =  " << numOfTouchFingers ;
                
                for (int j=0 ; j<numOfTouchFingers ; ++j)
                {
                    SDL_Finger* finger = SDL_GetTouchFinger (touchdevid,j);
                    cout << "\nFinger  ID=" << finger->id << "  pres=" << finger->pressure << "  x=" << finger->x << "  y=" << finger->y ;
                }
            }
        }
    }
    
    else
        m_console->input( k );
    
}
void    Game::    fingerEvent( SDL_TouchFingerEvent fingerEv )
{
    /*static map<string,map<Sint64>> fingers;
    if ( fingers.empty() )
    {
        fingers["up"]
    }*/
    
    switch (fingerEv.type)
    {
        case SDL_FINGERDOWN:
            printf("\n Finger DOWN  %.3f %.3f",fingerEv.x, fingerEv.y);
            break;
            
        case SDL_FINGERUP:
            printf("\n Finger UP    %.3f %.3f",fingerEv.x, fingerEv.y);
            break;
            
        case SDL_FINGERMOTION:
            printf("\n Finger MOV   %.3f %.3f",fingerEv.dx, fingerEv.dy);
            break;
    }
}