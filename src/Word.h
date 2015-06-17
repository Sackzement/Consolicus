#pragma once
#include <string>
using namespace std;



enum Wordtype
{
    wt_undef,
    wt_name,
    wt_number,
};





class Word
{
public:
    string   str = "";
    Wordtype type = wt_undef;
    
    Wordtype interpretTypeOfWord()
    {
        if ( str.length() == 0 )
            type  = wt_undef;
        else
        {
            if ( ( str[0] >= 'a' && str[0] <= 'z' )
                || ( str[0] >= 'A' && str[0] <= 'Z' ) )
            {
                type = wt_name;
            }
            else if ( str[0] >= '0' && str[0] <= '9' )
            {
                type = wt_number;
            }
            else
            {
                type = wt_undef;
            }
        }
        
        return type;
    }
};
