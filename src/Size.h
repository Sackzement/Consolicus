#pragma once







class SizeRect
{
    int s[2];
public:
    SizeRect()
    {
        s[0] = 0;
        s[1] = 0;
    };
    SizeRect(int w, int h)
    {
        s[0] = w;
        s[1] = h;
    };
    int& operator[](unsigned int i)
    {
        if (i >= 2) i = 2-1;
        return s[i];
    }
    int& w()
    {
        return  s[0];
    }
    int& h()
    {
        return  s[1];
    }
};
