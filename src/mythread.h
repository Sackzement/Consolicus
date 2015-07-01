#pragma once
#include "types.h"
#include <stdio.h>

//============================================


int threadFunc ( void* param )
{
    
}


class Copyclass
{
private:
    ulli    sizeMem   = 0;
    void*   mem       = nullptr;
    byte    numMems   = 0;
    byte    threadNum = 0;

    
public:
         Copyclass (ulli sizeMem, byte numMems, byte threadNum)
    {
        this->sizeMem = sizeMem;
        this->numMems = numMems;
        this->threadNum = threadNum;
    }
    void createMem ()
    {
        free(mem);
        
        mem  = malloc (numMems * sizeMem);
        
        byte* ptr  = (byte*)mem;
        
        for (byte i=1 ; i<=numMems ; ++i)
            for (byte j=1 ; j<=sizeMem ; ++j)
            {
                *ptr = rand()% 10;
                ++ptr;
            }
        
    }
    void printMem (byte memNum)
    {
        cout << "\n" ;
        
        byte* ptr = (byte*)mem;
        ptr += (memNum-1) *sizeMem ;
        
        for (byte i=1 ; i<=sizeMem ; ++i)
        {
            cout << (int)*ptr;
            ++ptr;
        }
        
    }
    void copyMem (byte fromMemNum, byte toMemNum)
    {
        byte* ptrA = (byte*)mem;
        ptrA += (fromMemNum-1) *sizeMem ;
        
        byte* ptrB = (byte*)mem;
        ptrB += (toMemNum-1) *sizeMem ;
        
        // devide mem1 into x-thread parts
        
        for (byte i=1 ; i<=sizeMem ; ++i)
        {
            *ptrB = *ptrA;
            
            ++ptrA;
            ++ptrB;
        }
        
    }
    
};

void runTest (ulli sizeOfTotalMemInBytes, byte numofmemblocks, byte numOfAdditionalThreads)
{
    
    Copyclass a = Copyclass(sizeOfTotalMemInBytes, numofmemblocks, numOfAdditionalThreads) ;
    a.createMem();
    
    //a.printMem(1);
    //a.printMem(2);
    uint tick1 = SDL_GetTicks();
    a.copyMem(1, 2);
    cout << "\ncopied in  " << SDL_GetTicks() - tick1 << " ms" ;
    
    //a.printMem(1);
    //a.printMem(2);
    
}










