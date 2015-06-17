#pragma once
#include <iostream>


int FindMax (int n, ...)
{
    int i,val,largest;
    va_list vl;
    va_start(vl,n);
    largest=va_arg(vl,int);
    for (i=1;i<n;i++)
    {
        val=va_arg(vl,int);
        largest=(largest>val)?largest:val;
    }
    va_end(vl);
    return largest;
}



void simple_printf(const char* fmt...)
{
    va_list args;
    va_start(args, fmt);
    
    while (*fmt != '\0')
    {
        if (*fmt == 'd')
        {
            int i = va_arg(args, int);
            std::cout << i << '\n';
        } else if (*fmt == 'c') {
            // note automatic conversion to integral type
            int c = va_arg(args, int);
            std::cout << static_cast<char>(c) << '\n';
        } else if (*fmt == 'f') {
            double d = va_arg(args, double);
            std::cout << d << '\n';
        }
        ++fmt;
    }
    
    va_end(args);
}
