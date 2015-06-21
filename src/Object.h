#pragma once
#include <vector>
#include <string>
using namespace std;




enum Objecttype
{
    ot_undef,
    ot_program,
    ot_console,
    ot_window,
    ot_sprite,
};





class Object
{
    
    string              m_name;
    Objecttype          m_type;

    Object *            m_parent;
    vector<Object*>     m_children;
    
public:
		Object( Objecttype t );
virtual        ~Object();
private:
    void        deleteAllChildren();
public:
    string      getName     () ;
    Objecttype  getType     () ;
    string      getTypeStr  () ;
    Object *    getParent   () ;
    Object *	getChild    ( string name );
    Object *	getChild   ( Objecttype type );

    void        setName     ( string name ) ;
    void        setParent   ( Object *  par ) ;
    Object *    addChild    ( Object *  ch ) ;
    void        removeChild ( Object *  ch ) ;
    
};





class ObjectManager
{
    static vector<Object*> m_objects ;
public:
    static void    printAll      () ;
    static void    addObject     ( Object *  obj ) ;
    static void    removeObject  ( Object *  obj ) ;
    static void    deleteObject  ( Object *  obj ) ;
    static void    deleteObject  ( string name ) ;
    static void    deleteAll     () ;
    static void    deleteAll     (Objecttype type) ;
    static void    deleteAllBut  () ;
    static string  genName       ( Objecttype t ) ;
    static Object* getObject     ( string name ) ;
};
