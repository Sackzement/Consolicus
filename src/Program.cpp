#include "Program.h"
#include <iostream>
#include <iomanip>
#include <SDL2/SDL.h>



        Program::    Program() : Object(ot_program)
{
    
    m_state = ps_start ;
    setFPS(60);
    m_fpsReal = 60.0f ;
    
    if ( SDL_InitSubSystem( SDL_INIT_TIMER ) != 0 )
    {
        cout << "\nError:\t" << SDL_GetError() ;
        return ;
    }
    
    m_lastDelayTick = SDL_GetTicks();
    m_lastDeltaTick = m_lastDelayTick;
    m_delta    = 1.0 / 60.0 ;
    
}
        Program::   ~Program()
{
    m_state = ps_end ;
}


void    Program::    run()
{
    m_state = ps_initing ;
    init();
    
    m_state  = ps_running ;
    while ( m_state == ps_running || m_state == ps_pause )
    {
        calcDelta();
        
        input();
        
        if ( m_state == ps_running )
            update();
        
        fpsDelay();
        
        render();
        
    }
    
    m_state = ps_end ;
    
}
void    Program::    pause()
{
    if ( m_state == ps_running )
        m_state = ps_pause ;
    else if ( m_state == ps_pause )
        m_state = ps_running ;
}
void    Program::    quit()
{
    m_state = ps_quitting ;
}

void    Program::    printData()
{
    
    printNameAndType();
    
    cout << '\n'  << getStateStr()
         << '\n'  << getFPS()
         << fixed << setprecision(3)
         << ' '   << m_fpsReal
         << '\n'  << double( getRuntime() ) / 1000.0
         << '\n'  << getDelta() ;
    
    printParentAndChildren();
    
}
uint    Program::    getRuntime()
{
    if ( m_lastDelayTick > m_lastDeltaTick )
        return m_lastDelayTick;
    else
        return m_lastDeltaTick;
}

string  Program::    getStateStr()
{
    string ret = "" ;
    
    switch ( m_state )
    {
        case ps_start:
            ret = "start" ;
            break;
            
        case ps_initing:
            ret = "initing" ;
            break;
            
        case ps_running:
            ret = "running" ;
            break;
            
        case ps_pause:
            ret = "pause" ;
            break;
            
        case ps_quitting:
            ret = "quitting" ;
            break;
            
        case ps_end:
            ret = "end" ;
            break;
    }
    
    return ret;
    
}
double  Program::    getDelta()
{
    return m_delta;
}
uint    Program::    getFPS()
{
    return m_fps;
}
float    Program::   getFPSreal()
{
    return m_fpsReal;
}
void    Program::    setFPS( uint fps )
{
    m_fps = fps ;
    m_mspf = 1000.0 / double(fps) ;
}


void    Program::    calcDelta()
{
    
    uint thisTick = SDL_GetTicks();
    uint tickdiff = thisTick - m_lastDeltaTick ;
    
    m_delta   = double(tickdiff) / 1000.0 ;
    m_fpsReal = 1000.0f / float(tickdiff) ;
    
    m_lastDeltaTick = thisTick;
    
}
void    Program::    fpsDelay()
{
    uint thisTick = SDL_GetTicks();
    uint tickdiff = thisTick - m_lastDelayTick ;
    
    if ( m_mspf > double(tickdiff) )
        SDL_Delay( uint( m_mspf - double(tickdiff) ) ) ;
    
    m_lastDelayTick = SDL_GetTicks();
    
}

