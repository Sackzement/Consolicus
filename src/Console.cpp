#include "Console.h"
#include "Game.h"
#include <iostream>
#include "Word.h"


//using namespace std;





        Console::  Console( Game *  p_game )
{
    m_strings = stack<string>() ;
    m_strings.push("") ;
    
    m_game = p_game;
    m_active = false;
}
void    Console::  close()
{
    if ( !m_active )  return;
    
    m_active = false;
    cout << "\nConsole\tclosed" ;
}
string& Console::  m_inputField()
{
    return m_strings.top();
}

void    Console::  open ()
{
    if ( m_active )  return;
    
    m_active = true;
    cout << "\nConsole\topened" ;
}
void    Console::  input ( SDL_KeyboardEvent key )
{
    if ( key.repeat > 0 ||  getKeytype(key) == kt_undef )   return;
    if ( getKeytype(key) == kt_exiter )                     return close();
    
    if ( getKeytype(key) == kt_toggle )                     return doToggle();
    
    if ( m_active )
    {
        if ( getKeytype(key) == kt_char )                    addKey(key);
        if ( getKeytype(key) == kt_deletelast )             removeKey();
        
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
    
    if ( m_inputField().length() == 0 )     return close();
    
    
    interpretInput();
    m_strings.push( "" );
    
}
void    Console::  addKey( SDL_KeyboardEvent key )
{
    m_inputField() += key.keysym.sym;
}
void    Console::  removeKey()
{
    m_inputField().pop_back();
}
void    Console::  printInput()
{
    cout << "\n" << m_inputField() ;
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
    vector<Word> wordlist;
    strToWordlist(m_inputField(), wordlist ) ;
    
    
    
    const vector<Word>  inWords;// = m_inputWords();
    
    for ( int i = 0 ; i < inWords.size() ; ++i )
    {
        //const Word& w = inWords[i];
        
        //if (inw )
    }
    
    
    
    
    //if ( m_inputField().find("win") != string::npos )
    if ( m_inputField() == "win" )
        m_game->m_window->printSettings();

    else if (m_inputField() == "win title")
        cout << "\nWindow Title\t" << m_game->m_window->getTitle() ;
    
    else if (m_inputField() == "win res")
        cout << "\nWindow Resolution\t" << m_game->m_window->getRes().w() << " " << m_game->m_window->getRes().h() ;
        
    else
        cout << "\n" << m_inputField() << "\t\tcant be interpreted";
    
}
void    Console::  strToWordlist ( const string &  str, vector<Word> &  words )
{
    words.clear();
    
    string    inStr     = m_inputField();
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
                words.push_back( Word() );
                curr_w = &words.back();
                curr_w->str += c;
                curr_w->interpretTypeOfWord();
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
        
    }
    
}
//void addScript(string scriptString, Func<> func)
