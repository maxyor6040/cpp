//
// Created by Arye on 12/01/2016.
//

#include "Class.h"
#include "Object.h"
#include "Field.h"
#include "Method.h"

#include "Exceptions.h"


Class::Class(Class *ancestor, string name): ancestor(ancestor), name(name) {}

Class* Class::getSuperClass(){return ancestor;}

Object* Class::newIstance(){
    Object *newObject = new Object();/*
    for(std::list<Field>::iterator i=fields.begin(); i != fields.end(); i++) {
        newObject.
    }*/ //TODO: Ary finish this method
    return newObject;
}

void Class::addMethod(std::string name, Func func){
    methods.push_back(Method(name, this->name, func));
}

void Class::addInstanceField(std::string name, Type t){
    Field f(name, this->name);
    f.setType(t);
    fields.push_back(f);
}

void Class::addStaticField(std::string name, Type t){
    Field f(name, this->name);
    f.setType(t);
    staticFields.push_back(f);
}

Field Class::getField(std::string name){
    for(std::list<Field>::iterator i=fields.begin(); i != fields.end(); i++) {
        if (i->name() == name)
            return *i;
    }
    for(std::list<Field>::iterator i=staticFields.begin(); i != staticFields.end(); i++) {
        if (i->name() == name)
            return *i;
    }
    if(ancestor!=NULL)
    {
        return ancestor->getField(name);
    }
    throw FieldNotFound();
}

std::list<Field> Class::getFields() {
    list<Field> res;
    if (ancestor != NULL){
        res=ancestor->getFields();
    }
    res.insert(res.begin(), staticFields.begin(),staticFields.end());
    res.insert(res.begin(), fields.begin(),fields.end());
    return res;
}

Method Class::getMethod(std::string name){
    for(std::list<Method>::iterator i=methods.begin(); i != methods.end(); i++) {
        if (i->name() == name)
            return *i;
    }
    for(std::list<Method>::iterator i=staticMethods.begin(); i != staticMethods.end(); i++) {
        if (i->name() == name)
            return *i;
    }
    if(ancestor!=NULL)
    {
        return ancestor->getMethod(name);
    }
    throw MethodNotFound();
}

std::list<Method> Class::getMethods(){
    list<Method> res;
    if (ancestor != NULL){
        res=ancestor->getMethods();
    }
    res.insert(res.begin(), staticMethods.begin(),staticMethods.end());
    res.insert(res.begin(), methods.begin(),methods.end());
    return res;
}

int Class::getInt(std::string name){
    for(std::list<Field>::iterator i=staticFields.begin(); i != staticFields.end(); i++) {
        if (i->name() == name)
            return i->getInt();
    }
    if(ancestor!=NULL)
    {
        return ancestor->getField(name);
    }
}

void Class::setInt(std::string name, int value);

Object* Class::getObj(std::string name);

void Class::setObj(std::string name, Object* value);