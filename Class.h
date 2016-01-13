#ifndef CLASS_H_
#define CLASS_H_

#include <list>
#include <string>
#include "Exceptions.h"


using std::list;
using std::string;

class Method;

class Field;

class Object;

typedef void(*Func)(Object *);


class Class {
    list<Method> methods;
    list<Method> staticMethods;
    list<Field> fields;
    list<Field> staticFields;
    Class *ancestor;
    string name;
    Object *dummy;
private:

public:
    /*
        you need to add a constructor that gets a pointer to the Base class and the name of this class.
        you must also add getSuperClass() that returns a pointer to the super class
    */
    Class(Class *ancestor, string name);

    Class *getSuperClass();

    Object *newIstance();

    void addMethod(std::string name, Func func);


    void addInstanceField(std::string name, Type t);

    void addStaticField(std::string name, Type t);

    Field getField(std::string name);

    std::list<Field> getFields();

    Method getMethod(std::string name);

    std::list<Method> getMethods();

    int getInt(std::string name);

    void setInt(std::string name, int value);

    Object *getObj(std::string name);

    void setObj(std::string name, Object *value);


};

#endif /* CLASS_H_ */
