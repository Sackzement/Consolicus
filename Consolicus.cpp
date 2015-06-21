#include "src/Game.h"
#include "src/myvararg.h"
#include "Script.h"
#include "Object.h"



int main(int argc, const char * argv[])
{
    simple_printf("dcff", 3, 'a', 1.999, 42.5);
    FindMax(4, 3, 6, 7, 4);
    
    Script sc = Script() ;
    sc << Word("upp") ;
    
    Game* game = new Game();
    
    game->run();
    
    delete game;
    
    return 0;
}
