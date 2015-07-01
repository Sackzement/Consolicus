#include "Console.h"
#include "Game.h"
#include <iostream>
#include <cctype>
#include "Word.h"
#include "Object.h"


//using namespace std;





        Console::  Console( Game *  p_game ) : Object(ot_console)
{
    m_strings = stack<string>() ;
    m_strings.push("") ;
    
    m_game = p_game;
    m_active = false;
    
    m_tags = map<string,tag> () ;
    
    
    loadTags();
    
}
        Console:: ~Console()
{
    
    while ( ! m_strings.empty() )
        m_strings.pop() ;
    
    m_active = false ;
    m_game   = nullptr ;
    
    m_tags.clear();
    
}
void    Console::  close()
{
    if ( !m_active )  return;
    
    m_active = false;
    cout << "\nConsole\tclosed" ;
}
string& Console::  m_inputStr()
{
    return m_strings.top();
}

void    Console::  loadTags  ()
{
    //tag t_game  = m_game;
    m_tags["game"] = m_game;
}
void    Console::  open ()
{
    if ( m_active )  return;
    
    m_active = true;
    cout << "\nConsole\topened" ;
}
void    Console::  input ( kb_key key )
{
    if ( key == k_esc )         return close();
    if ( key == k_enter )       return doToggle();
    
    if ( m_active )
    {
        if ( isalnum(key) )     addKey(key);
        if ( key == k_backspace )             removeKey();
        
        printInput();
    }
    
}
bool    Console::  isOpen()
{
    return m_active;
}
void    Console::  doToggle()
{
    if ( ! isOpen() )                      return open();
    
    if ( m_inputStr().length() == 0 )     return close();
    
    
    interpretInput();
    m_strings.push( "" );
    
}
void    Console::  addKey( kb_key key )
{
    m_inputStr() += key;
    //m_inputStr() += key.keysym.sym;
}
void    Console::  removeKey()
{
    m_inputStr().pop_back();
}
void    Console::  printInput()
{
    cout << "\n" << m_inputStr() ;
}
Keytype Console::  getKeytype ( char key )
{
    Keytype ret = kt_undef;
    
    switch (key)
    {
        case k_enter:
            ret = kt_toggle;
            break;
        case k_esc:
            ret = kt_exiter;
            break;
        case k_backspace:
            ret = kt_deletelast;
            break;
        case k_space:
            ret = kt_seperator;
            break;
    }
    
    if ( key >= k_0  &&  key <= k_9 )   ret = kt_number;
    if ( key >= k_a  &&  key <= k_z )   ret = kt_char;
    
    return ret;
}
Keytype Console::  getKeytype ( SDL_KeyboardEvent key )
{
    Keytype ret = kt_undef;
    
    if ( key.keysym.scancode == SDL_SCANCODE_RETURN )   ret = kt_toggle;
    
    if ( key.keysym.scancode == SDL_SCANCODE_ESCAPE )   ret = kt_exiter;
    
    if ( key.keysym.scancode == SDL_SCANCODE_BACKSPACE )   ret = kt_deletelast;
    
    if ( key.keysym.scancode == SDL_SCANCODE_SPACE )   ret = kt_char;
    
    if ( key.keysym.scancode >= SDL_SCANCODE_0  &&  key.keysym.scancode <= SDL_SCANCODE_9 )   ret = kt_char;
    
    if ( key.keysym.scancode >= SDL_SCANCODE_A  &&  key.keysym.scancode <= SDL_SCANCODE_Z )   ret = kt_char;
    
    return ret;
}
void    Console::  interpretInput()
{
    
    vector<Word>    words ;     strToWordlist( m_inputStr(), words ) ;
    size_t          s           = words.size() ;
    bool smtdone = false;
    
    for ( int i = 0; i < s; ++i )
    {
        
        if ( words[i].type == wt_name )
        {
            if ( words[i].str == "win" )
            {
                if ( s == 1 )
                {
                    m_game->m_window->printData();
                    smtdone = true;
                }
                if ( s == 2)
                {
                    if ( words[i+1].type == wt_name )
                    {
                        if ( words[i+1].str == "title" )
                        {
                            cout << "\nWindow Title\t" << m_game->m_window->getTitle() ;
                            smtdone = true;
                        }
                        else if ( words[i+1].str == "res" )
                        {
                            cout    << "\nWindow Resolution\t"
                                    << m_game->m_window->getRes().w() << " "
                                    << m_game->m_window->getRes().h() ;
                            smtdone = true;
                        }
                        else if ( words[i+1].str == "fs" )
                        {
                            //m_game->m_window->
                            cout << "\nFullscreen\t" << m_game->m_window->getTitle() ;
                            smtdone = true;
                        }
                    }
                }
            }
            else if ( words[i].str == "objs" && s == 1 )
            {
                ObjectManager::printAll();
                smtdone = true ;
            }
            else if ( words[i].str == "da" && s == 1 )
            {
                ObjectManager::deleteAll() ;
                smtdone = true ;
            }
            else if ( words[i].str == "ds" && s == 1 )
            {
                ObjectManager::deleteAll(ot_sprite) ;
                smtdone = true ;
            }
            else if ( words[i].str == "db" && s == 1 )
            {
                ObjectManager::deleteAllBut() ;
                smtdone = true ;
            }
            else if ( words[i].str == "pa" && s == 1 )
            {
                m_game->printData() ;
                m_game->m_window->printData() ;
                smtdone = true ;
            }
            
        }
        
    }
    
    if ( ! smtdone )
        cout << "\n" << m_inputStr() << "\t\tcant be interpreted";
    
}
void    Console::  strToWordlist ( const string &  str, vector<Word> &  words )
{
    words.clear();
    
    string    inStr     = m_inputStr();
    Keytype   last_ct   = kt_undef;
    Word *    curr_w    = nullptr;
    
    for (char c : inStr)
    {
        Keytype ct = getKeytype(c);
        
        if ( ct == kt_char || ct == kt_number )
        {
            if ( last_ct != kt_char && last_ct != kt_number )
            {
                // Add new Word to m_inputWords
                words.push_back( Word( string(1,c) ) );
                curr_w = &words.back();
            }
            else
            {
                if ( curr_w != nullptr )
                    curr_w->str += c;
            }
            
        }
        else
        {
            curr_w = nullptr;
        }
        
        last_ct = ct ;
    }
    
}
//void addScript(string scriptString, Func<> func)
