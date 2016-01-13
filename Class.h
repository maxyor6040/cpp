#ifndef CLASS_H_
#define CLASS_H_

#include <list>
#include <map>
#include "Method.h"
#include "Field.h"
#include "Exceptions.h"
#include "Object.h"

using std::list;
using std::string;
using std::map;

class Field;
class Method;


typedef void(*Func)(Object *);

class Class {
private:
    list<Method> methods;
    map<string, Object*> objectFields;
    map<string, int> intFields;
    map<string, Object*> staticObjectFields;
    map<string, int> staticIntFields;
    Class *ancestor;

    map<string, int> getIntFieldsRecursively() {
        map<string, int> res;
        if (ancestor != NULL)
            res = ancestor->getIntFieldsRecursively();

        for(map<string, int>::iterator i = intFields.begin(); i!=intFields.end();i++) {
            res[i->first] = i->second;
        }
        return res;
    }

    std::map<std::string, Object*> getObjectFieldsRecursively() {
        map<string, Object*> res;
        if (ancestor != NULL)
            res = ancestor->getObjectFieldsRecursively();

        for(map<string, Object*>::iterator i = objectFields.begin(); i!=objectFields.end();i++) {
            res[i->first] = i->second;
        }
        return res;
    }
public:
    string name;

    Class(Class *ancestor, string name);

    Class *getSuperClass();

    Object *newInstance();

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
