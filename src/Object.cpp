#include "Object.h"
#include <algorithm>
#include <iostream>



Object::            Object      ( Objecttype type )
{
    
    m_name      = ObjectManager::genName(type) ;
    m_type      = type;
    m_parent    = nullptr;
    m_children  = vector<Object*> () ;
    
    ObjectManager::addObject(this) ;
    
}
Object::           ~Object      ()
{
    
    deleteAllChildren() ;
    setParent( nullptr ) ;
    m_name = "";
    m_type = ot_undef;
    
    ObjectManager::removeObject(this) ;
    
}


void    Object::    printData()
{
    printNameAndType();
    printParentAndChildren();
}
void    Object::    printNameAndType()
{
    cout << "\n" << getName() << "\t" << getTypeStr() ;
}
void    Object::    printParentAndChildren()
{
    
    string parentName;
    if ( m_parent != nullptr )
        parentName = m_parent->getName() ;
    else
        parentName = "noParent" ;
    cout << "\n" << parentName ;
    
    if ( m_children.size() > 0 )    cout << "\n" ;
    for ( Object* child : m_children )
    {
        if ( child != nullptr )
        {
            cout << child->getName() << " ";
        }
    }
    
}
Object * Object::   addChild    ( Object *  ch )
{
    
    if ( ch != nullptr )
    {
        auto found = find( std::begin(m_children), std::end(m_children), ch ) ;
        
        if ( found == std::end(m_children) )
        {
            m_children.push_back(ch) ;
            ch->setParent(this) ;
        }
    }
    
    return ch ;
    
}
Object* Object::    getChild    ( string name )
{
    for ( Object* o : m_children )
        if ( o->getName() == name )
            return o;
    
    return nullptr;
}
Object* Object::    getChild    ( Objecttype type )
{
    for ( Object* o : m_children )
        if ( o->getType() == type )
            return o;
    
    return nullptr;
}
void    Object::    removeChild ( Object *  ch )
{
    
    vector<Object*>::iterator it = m_children.begin();
    
    for ( ; it != m_children.end() ; ++it )
    {
        if ( ch == *it )
        {
            Object* erasedObj = *it;
            m_children.erase(it);
            erasedObj->setParent(nullptr) ;
            break;
        }
    }
    
}


string  Object::    getName     ()
{
    return m_name ;
}
Objecttype Object:: getType     ()
{
    return m_type ;
}
string  Object::    getTypeStr  ()
{
    
    string ret = "" ;
    
    switch ( m_type )
    {
        case ot_program:
            ret = "program" ;
            break;
            
        case ot_window:
            ret = "window" ;
            break;
            
        case ot_sprite:
            ret = "sprite" ;
            break;
            
        case ot_console:
            ret = "console" ;
            break;
            
        default:
            ret = "undef" ;
            break;
    }
    
    return ret ;
}
Object* Object::    getParent   ()
{
    return m_parent ;
}


void    Object::    setName     ( string name )
{
    m_name = name ;
}
void    Object::    setParent   ( Object *  par )
{
    if ( m_parent != par )
    {
        Object* lastParent = m_parent ;
        m_parent = par ;
        
        if ( lastParent != nullptr )
            lastParent->removeChild( this ) ;
        
        if ( m_parent != nullptr )
            m_parent->addChild( this ) ;
        
    }
}


vector<Object*>& Object:: getChildren()
{
    return m_children;
}


void    Object::    deleteAllChildren ()
{
    for (Object* o : m_children)    delete o ;
    m_children.clear() ;
}




vector<Object*> ObjectManager:: m_objects = vector<Object*>() ;


void  ObjectManager::   printAll        ()
{
    cout << "\nObject Manager\n"
         << m_objects.size() << " Objects" ;
    
    for ( int i = 0 ; i < m_objects.size() ; ++i )
    {
        cout << "\n" << m_objects[i]->getName() << "\t" << m_objects[i]->getTypeStr() ;
    }
    
}
string ObjectManager::  genName         ( Objecttype t )
{
    
    string name ;
    
    switch (t)
    {
        case ot_undef:
            name = "window_" ;
            break ;
            
        case ot_program:
            name = "program_" ;
            break ;
            
        case ot_window:
            name = "window_" ;
            break ;
            ;
        case ot_sprite:
            name = "sprite_" ;
            break ;
            
        case ot_console:
            name = "console_" ;
            break ;
            
        default:
            name = "undef_" ;
            break ;
    }
    
    for ( int i = 1; i < 1000 ; ++i )
    {
        string nn = name + to_string(i) ;
        if ( getObject(nn) == nullptr )
        {
            name = nn ;
            break ;
        }
        
    }
    
    
    return name;
    
}


void  ObjectManager::   addObject       ( Object *  obj )
{
    
    if ( obj != nullptr )
    {
        auto found = find( std::begin(m_objects), std::end(m_objects), obj ) ;
        
        if ( found == std::end(m_objects) )
            m_objects.push_back(obj) ;
    }
    
}
Object* ObjectManager:: getObject       ( string name )
{
    
    for (Object* o : m_objects)
        if ( o->getName() == name )
            return o;
    
    return nullptr;
    
}
void  ObjectManager::   removeObject    ( Object *  obj )
{
    if ( obj != nullptr )
    {
        
        vector<Object*>::iterator it = m_objects.begin();
        for ( ; it != m_objects.end() ; ++it )
        {
            if ( obj == *it )
            {
                m_objects.erase(it) ;
                break;
            }
        }
        
    }
}


void  ObjectManager::   deleteObject    ( Object *  obj )
{
    if ( obj != nullptr )
    {
        
        vector<Object*>::iterator it = m_objects.begin();
        for ( ; it != m_objects.end() ; ++it )
        {
            if ( obj == *it )
            {
                m_objects.erase(it) ;
                delete obj ;
                break;
            }
        }
        
    }
}
void  ObjectManager::   deleteObject    ( string name )
{
    
    vector<Object*>::iterator it = m_objects.begin();
    for ( ; it != m_objects.end() ; ++it )
    {
        if ( name == (*it)->getName() )
        {
            Object* toDelete = *it ;
            m_objects.erase(it);
            delete toDelete ;
            break;
        }
    }
    
}
void  ObjectManager::   deleteAll       ()
{
    
    while ( m_objects.size() > 0 )
    {
        delete m_objects.back() ;
        m_objects.pop_back();
    }
    
    m_objects.clear() ;
    
}
void  ObjectManager::   deleteAll       (Objecttype type)
{
    
    vector<Object*>::iterator it = m_objects.begin();
    
    for ( ; it != m_objects.end() ; ++it )
    {
        if ( type == (*it)->getType() )
        {
            Object* toDelete = *it ;
            m_objects.erase(it);
            delete toDelete ;
            --it;
        }
    }
    
}
void  ObjectManager::   deleteAllBut    ()
{
    
    vector<Object*>::iterator it = m_objects.begin();
    
    for ( ; it != m_objects.end() ; ++it )
    {
        if ( ot_program != (*it)->getType() && ot_console != (*it)->getType() )
        {
            Object* toDelete = *it ;
            m_objects.erase(it);
            delete toDelete ;
            --it;
        }
    }
    
}






