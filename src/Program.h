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
public:
                Program() ;
    virtual    ~Program() ;
    
    void        run() ;
    void        pause() ;
    void        quit() ;
    
virtual void    printData();
    uint        getRuntime();
    
protected:
    string      getStateStr  () ;
    double      getDelta() ;
    uint        getFPS() ;
    float       getFPSreal() ;
    void        setFPS( uint fps ) ;
    
virtual void    init()   = 0;
virtual void    input()  = 0;
virtual void    update() = 0;
virtual void    render() = 0;
    
    
private:
    void        calcDelta();
    void        fpsDelay();
    
    
    ProgramState m_state;
    uint         m_fps;
    double       m_mspf;
    float        m_fpsReal;
    uint         m_lastDelayTick;
    uint         m_lastDeltaTick;
    double       m_delta;
    
};

