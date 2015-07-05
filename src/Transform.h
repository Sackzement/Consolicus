#pragma once


struct Vector3pos
{
    Vector3pos(float x = 0.f, float y = 0.f, float z = 0.f) : v({x,y,z}) //x(x), y(y), z(z)
    {
        /*this->x = x;
        this->y = y;
        this->z = z;*/
    }
    /*Vector3pos(float x = 0.f, float y = 0.f, float z = 0.f) : x(x), y(y), z(z)
    {
         this->x = x;
         this->y = y;
         this->z = z;
    }*/
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

