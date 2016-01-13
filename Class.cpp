//
// Created by Arye on 12/01/2016.
//

#include <assert.h>
#include "Class.h"

Class::Class(Class *ancestor, string name) : ancestor(ancestor), name(name) { }

Class *Class::getSuperClass() { return ancestor; }

Object *Class::newInstance() {

    Object *newObject = new Object(this, getObjectFieldsRecursively(), getIntFieldsRecursively());
    return newObject;
}

void Class::addMethod(std::string name, Func func) {
    methods.push_back(Method(name, this->name, func));
}

void Class::addInstanceField(std::string name, Type t) {
    if (t == INT) {
        intFields[name] = 0;
    } else if (t == OBJECT) {
        objectFields[name] = 0;
    } else {
        assert(false);
    }
}

void Class::addStaticField(std::string name, Type t) {
    if (t == INT) {
        intFields[name] = 0;
    } else if (t == OBJECT) {
        objectFields[name] = 0;
    } else {
        assert(false);
    }
}

Field Class::getField(std::string name) {
    list<Field> fields = getFields();
    for (list<Field>::iterator i = fields.begin(); i != fields.end(); i++) {
        if (i->name() == name)
            return *i;
    }
}

std::list<Field> Class::getFields() {
    list<Field> res;
    if (ancestor != NULL) {
        res = ancestor->getFields();
    }
    for (map<string, int>::iterator i = intFields.begin(); i != intFields.end(); i++) {
        Field temp(i->first, name);
        temp.setType(INT);
        res.push_front(temp);
    }

    for (map<string, int>::iterator i = staticIntFields.begin(); i != staticIntFields.end(); i++) {
        Field temp(i->first, name);
        temp.setType(INT);
        res.push_front(temp);
    }

    for (map<string, Object *>::iterator i = objectFields.begin(); i != objectFields.end(); i++) {
        Field temp(i->first, name);
        temp.setType(OBJECT);
        res.push_front(temp);
    }

    for (map<string, Object *>::iterator i = staticObjectFields.begin(); i != staticObjectFields.end(); i++) {
        Field temp(i->first, name);
        temp.setType(OBJECT);
        res.push_front(temp);
    }
    return res;
}

Method Class::getMethod(std::string name) {
    for (std::list<Method>::iterator i = methods.begin(); i != methods.end(); i++) {
        if (i->name() == name)
            return *i;
    }
    if (ancestor != NULL) {
        return ancestor->getMethod(name);
    }
    throw MethodNotFound();
}

std::list<Method> Class::getMethods() {
    list<Method> res;
    if (ancestor != NULL) {
        res = ancestor->getMethods();
    }
    res.insert(res.begin(), methods.begin(), methods.end());
    return res;
}

int Class::getInt(std::string name) {
    if (staticIntFields.find(name) == staticIntFields.end())
        throw FieldNotFound();

    return staticIntFields[name];
}

void Class::setInt(std::string name, int value) {
    if (staticIntFields.find(name) == staticIntFields.end())
        throw FieldNotFound();

    staticIntFields[name] = value;
}

Object *Class::getObj(std::string name) {
    if (staticObjectFields.find(name) == staticObjectFields.end())
        throw FieldNotFound();

    return staticObjectFields[name];
}

void Class::setObj(std::string name, Object *value) {
    if (staticObjectFields.find(name) == staticObjectFields.end())
        throw FieldNotFound();

    staticObjectFields[name] = value;
}
