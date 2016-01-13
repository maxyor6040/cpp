//
// Created by Arye on 12/01/2016.
//

#include "Object.h"
#include "Class.h"
#include "Method.h"
#include "Exceptions.h"

Object::Object(Class *objectClass, const map<string, Object *>& objectFields, const map<string, int>& intFields) :
        objectClass(objectClass), objectFields(objectFields), intFields(intFields) {}

Class* Object::getClass() { return objectClass; }

int Object::getInt(std::string name) {

    if (intFields.find(name) == intFields.end())
        throw FieldNotFound();

    return intFields[name];
}

void Object::setInt(std::string name, int value) {
    if (intFields.find(name) == intFields.end())
        throw FieldNotFound();

    intFields[name] = value;
}

Object* Object::getObj(std::string name) {
    if (objectFields.find(name) == objectFields.end())
        throw FieldNotFound();

    return objectFields[name];
}

void Object::setObj(std::string name, Object *value) {
    if (objectFields.find(name) == objectFields.end())
        throw FieldNotFound();

    objectFields[name] = value;
}

void Object::invokeMethod(std::string name) { objectClass->getMethod(name).invoke(this); }

bool Object::isInstanceOf(std::string c) {
    Class* current = objectClass;
    while (current != NULL) {
        if (current->name == c)
            return true;

        current = current->getSuperClass();
    }
    return false;
}
