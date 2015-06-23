#pragma once




enum Tagtype
{
    tt_object,
    tt_function,
};




class Tag
{
    
public:
    Tag ( string name, Tagtype type ) : m_name(name), m_type(type)  {}
private:
    string  m_name;
    Tagtype m_type;
    
};