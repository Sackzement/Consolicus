#pragma once


#include <algorithm>
using namespace std;
#include "Object.h"



enum tagtype
{
    tt_undef     = 0x0,
    tt_object    = 0x1,
    tt_function  = 0x2,
};



typedef void (*fp_vv) ();



class tag{
    
private:
    
    int         m_type      = tt_undef;
    Object *    m_object    = nullptr;
    fp_vv       m_function  = nullptr;
    
public:
    
    int      const &    type        = m_type;
    Object * const &    object      = m_object;
    fp_vv    const &    function    = m_function;
    
    
    
    
    tag ()           {
        
        reset();
    }
    void reset ()    {
        
        m_type        = tt_undef;
        m_object      = nullptr;
        m_function    = nullptr;
        
    }
    
   ~tag ()    /*noexcept*/  {
        
        reset();
        
    }
    
    tag              ( tag const &  t )         {
        
        m_type      = t.type;
        m_object    = t.object;
        m_function  = t.function;
        
    }
    tag &  operator= ( tag const &  t )         {
        
        tag tmp(t);
        *this = move(tmp);
        
        return *this;
        
    }
    
    tag              ( tag &&  t )    /*noexcept*/  {
        
        m_type      = t.type;
        m_object    = t.object;
        m_function  = t.function;
        
        t.reset();
        
    }
    tag &  operator= ( tag &&  t )    /*noexcept*/  {
        
        swap( m_type, t.m_type ) ;
        swap( m_object, t.m_object ) ;
        swap( m_function, t.m_function ) ;
        
        return *this;
        
    }
    
    
    tag ( Object * const &  o )    {
        
        *this  = o;
        
    }
    tag ( fp_vv    const &  f )    {
        
        *this  = f;
        
    }
    
    tag &  operator= ( Object * const &  o )    {
        
        m_object = o;
        
        if ( m_object != nullptr )
            m_type  |=  tt_object;
        else
            m_type  &= ~tt_object;
        
        return *this;
        
    }
    tag &  operator= ( fp_vv    const &  f )    {
        
        m_function  = f;
        
        if ( m_function != nullptr )
            m_type  |=  tt_function;
        else
            m_type  &= ~tt_function;
        
        return *this;
        
    }
    
    bool   operator== ( tagtype const &  tt )  const    {
        
        if ( m_type & tt )
            return true;
        else
            return false;
        
    }
    
    
};
