#pragma once


struct Vector3pos
{
    float  v[3] = { 0, 0, 0 } ;
    float& x    = v[0] ;
    float& y    = v[1] ;
    float& z    = v[2] ;
};
struct Vector3size
{
    float  v[3] = { 1.0f, 1.0f, 1.0f } ;
    float& w    = v[0] ;
    float& h    = v[1] ;
    float& d    = v[2] ;
};

class Transform
{
public:
    Vector3pos  pos;
    Vector3size size;
    
};

