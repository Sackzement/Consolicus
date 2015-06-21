#pragma once

#include "Console.h"
#include "Object.h"




enum ProgramState
{
    ps_start    ,
    
    ps_initing  ,
    ps_running  ,
    ps_pause    ,
    
    ps_quitting ,
    
    ps_end
};



class Program : public Object
{
private:
    ProgramState m_state ;
protected:
virtual void    init()   = 0;
virtual void    input()  = 0;
virtual void    update() = 0;
virtual void    render() = 0;
public:
                Program();
    void        run();
    void        pause();
    void        quit();
    virtual    ~Program();
    
};

