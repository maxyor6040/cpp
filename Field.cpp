
using namespace std;
#include <iostream>
#include "Field.h"

Field::Field(std::string fieldName, std::string className):fieldName(fieldName), className(className) {
    intValue=0;
    type=INT;
}

void Field::setType(Type t) { type = t; }

Type Field::getType(){ return type;}

void Field::setInt(Object *obj, int value) { obj->setInt(fieldName,value); }

int Field::getInt(Object* obj){ obj->getInt(fieldName); }

void Field::setObj(Object* obj, Object* value){ obj->setObj(fieldName, value); }

Object* Field::getObj(Object* obj){ obj->getObj(fieldName); }

std::string Field::getDeclaringClass() const{ return className; }

std::string Field::name() const { return className; }
