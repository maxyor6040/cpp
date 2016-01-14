
#include "Field.h"

Field::Field(std::string fieldName, std::string className):fieldName(fieldName), className(className) {
    type=INT;
}

void Field::setType(Type t) { type = t; }

Type Field::getType(){ return type;}

void Field::setInt(Object *obj, int value) { assertLegalAccess(obj); obj->setInt(fieldName, value); }

int Field::getInt(Object* obj){ assertLegalAccess(obj); obj->getInt(fieldName); }

void Field::setObj(Object* obj, Object* value){ assertLegalAccess(obj); obj->setObj(fieldName, value); }

Object* Field::getObj(Object* obj){ assertLegalAccess(obj); obj->getObj(fieldName); }

std::string Field::getDeclaringClass() const{ return className; }

std::string Field::name() const { return className; }



void Field::assertLegalAccess(Object *o){
    if (!o->isInstanceOf(className))
        throw TypeError();
}