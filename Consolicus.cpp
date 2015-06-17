#include "src/Game.h"
#include "src/myvararg.h"




int main(int argc, const char * argv[])
{
    simple_printf("dcff", 3, 'a', 1.999, 42.5);
    FindMax(4, 3, 6, 7, 4);
    
    Game game = Game();
    
    game.loadStuff();
    
    game.mainloop();
    
    return 0;
}
