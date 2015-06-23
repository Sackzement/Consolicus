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
    
public:
                Object( Objecttype t );
virtual        ~Object();
    
virtual void    printData();
    Object *    addChild    ( Object *  ch ) ;
    Object *	getChild    ( string name ) ;
    Object *	getChild    ( Objecttype type ) ;
    void        removeChild ( Object *  ch ) ;
    
    string      getName     () ;
    Objecttype  getType     () ;
    string      getTypeStr  () ;
    Object *    getParent   () ;

    void        setName     ( string name ) ;
    void        setParent   ( Object *  par ) ;
    
protected:
    void                printNameAndType();
    void                printParentAndChildren();
    vector<Object*> &   getChildren();
    
private:
    void        deleteAllChildren();
    
    
    
    string              m_name;
    Objecttype          m_type;
    
    Object *            m_parent;
    vector<Object*>     m_children;
    
};


class ObjectManager
{
    static vector<Object*> m_objects ;
public:
    static void    printAll      () ;
    static string  genName       ( Objecttype t ) ;
    
    static void    addObject     ( Object *  obj ) ;
    static Object* getObject     ( string name ) ;
    static void    removeObject  ( Object *  obj ) ;
    
    
    static void    deleteObject  ( Object *  obj ) ;
    static void    deleteObject  ( string name ) ;
    static void    deleteAll     () ;
    static void    deleteAll     (Objecttype type) ;
    static void    deleteAllBut  () ;
};
