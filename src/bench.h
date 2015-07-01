#pragma once




#include <setjmp.h>

void jumpTest()
{
    jmp_buf env;
    int val = 0;
    val += setjmp (env);
    if (val >= 10) {
        fprintf (stderr,"Error %d happened",3);
        //exit (val);
    }
    
    
    
    longjmp (env,1);   /* signaling an error */2
    
}





#include <stdio.h>
#include <iostream>
#include <string>
#include <SDL2/SDL.h>
//#include <SDL2/SDL_thread.h>
//#include <SDL2/SDL_timer.h>

typedef unsigned long long int ulli;


char*  myMem;   // 00000000000000000...
ulli*  pos;     // 1234...
SDL_Thread** threads;

int threadFunc(void* param) // (void*)   int threadNum, int numThreads, ulli mSize
{
    int*         iparam      = (int*)param;
    
    const int&   tNum        = *iparam;
    const int&   numThreads  = *(iparam+1);
    const ulli&  mSize       = *( (ulli*)(iparam+2) ) ;
    
    //std::cout << "\nthread" << tNum+1 << " started" ;
    while ( pos[tNum] < mSize )
    {
        myMem[pos[tNum]] = tNum+65;
        pos[tNum] += numThreads;
    }
    //std::cout << "\n" << SDL_GetThreadName(threads[tNum]) << " finished" ;
}

void threadtest(int numThreads, ulli memSize)
{
    --numThreads;
    SDL_Init(SDL_INIT_EVERYTHING);
    
    Uint32 time = SDL_GetTicks();
    
    if (numThreads > memSize)
        numThreads = memSize;
    
    myMem  = new char[memSize];
    pos    = new ulli[numThreads];
    
    for (int i = 0; i < numThreads+1; ++i)
        pos[i] = ulli(i);

    int** data  = new int*[numThreads+1];
    threads     = new SDL_Thread*[numThreads];
    int ii = 0;
    for (; ii < numThreads; ++ii)
    {
        data[ii] = (int*)malloc( 2*sizeof(int) * sizeof(ulli) );
        *data[ii] = ii;
        *(data[ii]+1) = numThreads;
        *((ulli*)(data[ii]+2)) = memSize;
        string name = "thread" + to_string(ii+1) ;
        threads[ii] = SDL_CreateThread(threadFunc, name.c_str(), (void*)data[ii] );
    }
    data[ii] = (int*)malloc( 2*sizeof(int) * sizeof(ulli) );
    *data[ii] = ii;
    *(data[ii]+1) = numThreads+1;
    *((ulli*)(data[ii]+2)) = memSize;
    //string name = "thread" + to_string(ii+1) ;
    //threads[ii] = SDL_CreateThread(threadFunc, name.c_str(), data[ii] );
    threadFunc((void*)data);
    
    
    for (int i = 0; i < numThreads; ++i)
        SDL_WaitThread(threads[i], nullptr);
    
    for (int i = 0; i < numThreads+1; ++i)
        free(data[i]);
    delete [] data;
    
    //std::printf("\nThreads END") ;
    std::cout << "\nthreads: " << numThreads << "  ->  " << ( SDL_GetTicks() - time ) << " ms" ;
    
    
    delete []  myMem;
    delete []  pos;
    delete []  threads;
}



