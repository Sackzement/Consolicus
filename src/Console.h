#pragma once

#include <string>
#include <stack>
#include <vector>
#include <map>
using namespace std;
#include <SDL2/SDL_events.h>
#include "Key.h"
#include "Word.h"
#include "Object.h"
#include "tag.h"


class Game;




class Console : public Object
{
public:
                    Console( Game *  p_game ) ;
    virtual        ~Console();
    
    void            close();
    void            input( kb_key key ) ;
    bool            isOpen();
    
private:
    void            loadTags();
    void            open();
    void            doToggle();
    void            addKey( kb_key key ) ;
    void            removeKey();
    void            printInput();
    Keytype         getKeytype ( char key ) ;
    Keytype         getKeytype ( SDL_KeyboardEvent key ) ;
    void            interpretInput();
    void            strToWordlist ( const string &  str, vector<Word> &  words );
    
    
    string &           m_inputStr();
    // wordsToFunction datatype
    stack<string>      m_strings;
    bool               m_active;
    Game *             m_game;
    map<string,tag>    m_tags;
};
