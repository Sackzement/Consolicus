#include "Program.h"


        Program::    Program() : Object(ot_program)
{
    m_state = ps_start ;
}
void    Program::    run()
{
    m_state = ps_initing ;
    init();
    
    m_state  = ps_running ;
    while ( m_state != ps_quitting )    // mainloop
    {
        
        input();
        
        if ( m_state == ps_running )
            update();
        
        render();
        
    }
    
    m_state = ps_end ;
    
}
        Program::   ~Program()
{
    m_state = ps_pause ;
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