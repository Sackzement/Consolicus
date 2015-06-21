#pragma once
#include "Word.h"









class Script
{
    
    vector<Word> m_words = vector<Word> () ;
    
public:
    Script &  operator << (Word w)
    {
        m_words.push_back(w) ;
        
        return *this;
    }
    Script &  operator << (string s)
    {
        Word w = Word(s) ;
        m_words.push_back(w) ;
        
        return *this;
    }
    Script &  operator << (char c)
    {
        Word w = Word(c) ;
        m_words.push_back(w) ;
        
        return *this;
    }
    void execute()
    {
        size_t s = m_words.size() ;
        
        for ( int i = 0; i < s; ++i )
        {
            Word w = m_words[i] ;
            
            
            if ( w.type == wt_name )
            {
                if (  s == 1 )
                {
                    if ( w.str == "win" )
                    {
                        
                    }
                }
                
            }
            
        }
        
        
    }
    
    
};

