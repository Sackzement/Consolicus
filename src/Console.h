#pragma once

#include <string>
#include <stack>
using namespace std;
#include <SDL2/SDL_events.h>
#include <vector>
#include <map>
#include "Key.h"
#include "Word.h"
#include "Object.h"


class Game;




class Console : public Object
{
public:
                    Console( Game *  p_game ) ;
    virtual        ~Console();
    
    void            close();
    void            input( SDL_KeyboardEvent key ) ;
    bool            isOpen();
    
private:
    void            open();
    void            doToggle();
    void            addKey( SDL_KeyboardEvent key ) ;
    void            removeKey();
    void            printInput();
    Keytype         getKeytype ( char key ) ;
    Keytype         getKeytype ( SDL_KeyboardEvent key ) ;
    void            interpretInput();
    void            strToWordlist ( const string &  str, vector<Word> &  words );
    
    
    string &        m_inputStr();
    // wordsToFunction datatype
    stack<string>   m_strings;
    bool            m_active;
    Game *          m_game;
    //map<string, >
};
