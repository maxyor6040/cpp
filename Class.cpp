//
// Created by Arye on 12/01/2016.
//

#include "Class.h"
#include "Object.h"
#include "Field.h"

Class::Class(Class *ancestor, string name): ancestor(ancestor), name(name) {}

Class* Class::getSuperClass(){return nullptr;}

Object* Class::newIstance(){return nullptr;}

void Class::addMethod(std::string name, Func func){}

void Class::addInstanceField(std::string name, Type t){}

void Class::addStaticField(std::string name, Type t){}

Field Class::getField(std::string name){ return Field("blah", "blah"); }

std::list<Field> Class::getFields();

Method Class::getMethod(std::string name);

std::list<Method> getMethods();

int getInt(std::string name);

void setInt(std::string name, int value);

Object* getObj(std::string name);

void setObj(std::string name, Object* value);