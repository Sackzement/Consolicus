#pragma once

#include "Object.h"
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_surface.h>
#include "Transform.h"
#include "Mask.h"
#include "Sprite.h"
#include <fstream>

enum state
{
    st_standing,
    st_walking,
    st_sprinting,
};

class Tobi : public Sprite
{
    
public:
    Tobi       () : Sprite(20, 20)  {
    
        updateSurface();
    }
    virtual        ~Tobi       ()     {}
    
    void            setState   ( state st )                  {
        switch (st)
        {
            case st_standing:
                m_w_is_down      = false;
                m_shift_is_down  = false;
                break;
                
            case st_walking:
                m_w_is_down      = true;
                m_shift_is_down  = false;
                break;
                
            case st_sprinting:
                m_w_is_down      = true;
                m_shift_is_down  = true;
                break;
        }
    }
    void            input      ( SDL_KeyboardEvent key_ev )  {
        
        // save surface to  "tobi.txt"
        if  ( key_ev.keysym.sym == SDLK_f )
        {
            std::ofstream ofs;
            ofs.open("tobi.txt",std::ofstream::out | std::ofstream::trunc );
            
            Uint32* pixels = (Uint32*)m_sdlSurface->pixels;
            for  ( int iy=0 ; iy < m_sdlSurface->h ; ++iy )
            {
                for  ( int ix=0 ; ix < m_sdlSurface->w ; ++ix )
                {
                    Uint32 pixel = pixels[iy*m_sdlSurface->w +ix];
                
                    char c = '0';
                    if ( pixel & 0xff000000 )
                        c = 'R';
                    else if ( pixel & 0x00ff0000 )
                        c = 'G';
                
                    ofs << c;
                }
                ofs << '\n';
            }
            
            ofs.close();
        }
        
        if ( key_ev.keysym.sym != SDLK_w )
            return;
        
        if  ( key_ev.type == SDL_KEYDOWN )
        {
            m_last2_w_down_time  = m_last_w_down_time;
            m_last_w_down_time   = SDL_GetTicks();
            
            if ( m_state == st_standing )
                setState(st_walking);
            
            else if  ( m_state == st_walking )
                if  ( m_last2_w_down_time < m_double_tap_time )
                    setState(st_sprinting);
            
            else if  ( m_state == st_sprinting )
                setState(st_walking);
                
        }
        
        else if ( key_ev.type == SDL_KEYUP )
        {
            
            if  ( m_state == st_walking )
                if  ( m_last_w_down_time > m_single_tap_time )
                    setState(st_standing);
            
            if  ( m_state == st_sprinting )
                if  ( m_last2_w_down_time > m_double_tap_time )
                    setState(st_standing);
            
        }
        
        updateSurface();
        
    }
    void            updateSurface     ()    {
        
        SDL_Rect rect;
        rect.x = 0;
        rect.y = 0;
        rect.w = m_sdlSurface->w / 2;
        rect.h = m_sdlSurface->h;
        
        Uint32 col = 0;
        
        
        if (m_w_is_down)    col = SDL_MapRGB(m_sdlSurface->format, 0, 255, 0);
        else                col = SDL_MapRGB(m_sdlSurface->format, 255, 0, 0);
        SDL_FillRect(m_sdlSurface, &rect, col );
        
        rect.x += rect.w/2;
        if (m_shift_is_down)  col = SDL_MapRGB(m_sdlSurface->format, 0, 255, 0);
        else                  col = SDL_MapRGB(m_sdlSurface->format, 255, 0, 0);
        SDL_FillRect(m_sdlSurface, &rect, col );
        
    }
    
public:
    uint   m_single_tap_time    = 500;
    uint   m_double_tap_time    = 1000;
    
private:
    bool   m_w_is_down          = false;
    bool   m_shift_is_down      = false;
    
    uint   m_last_w_down_time   = 0;
    uint   m_last2_w_down_time  = 0;
    
    
    state  m_state              = st_standing;
    
};
