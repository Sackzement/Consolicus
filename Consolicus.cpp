#include "Game.h"
#include "Script.h"
#include "Object.h"
#include "myvararg.h"

//#include "bench.h"
#include "mythread.h"
#include "16_true_type_fonts.h"



int main(const int argc, const char ** argv)
{
    int m = mainFunc(argc, argv);
    cout << m;
    Game game;
    game.run();
    
    return 0;
    
}

