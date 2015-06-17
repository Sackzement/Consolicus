#pragma once

#include <string>
#include <stack>
using namespace std;
#include <SDL2/SDL_events.h>
#include <vector>
#include "Key.h"
#include "Word.h"


class Game;




class Console
{
private:        // PRIVATE ==========================================
                // VARIABLES ----------------------------------------
    // wordsToFunction datatype
    stack<string>   m_strings;
    bool            m_active;
    Game *          m_game;
                // FUNCTIONS ----------------------------------------
    string &        m_inputField();
    
    void            open();
    void            doToggle();
    void            addKey( SDL_KeyboardEvent key );
    void            removeKey();
    void            printInput();
    Keytype         getKeytype ( char key );
    Keytype         getKeytype ( SDL_KeyboardEvent key );
    void            interpretInput();
    void            strToWordlist ( const string &  str, vector<Word> &  words );
public:         // PUBLIC ===========================================
                // FUNCTIONS ----------------------------------------
                    Console( Game *  p_game ) ;
    void            close();
    void            input( SDL_KeyboardEvent key );
    bool            isOpen();
private:
    
    
};
