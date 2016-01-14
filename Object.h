#ifndef OBJECT_H_
#define OBJECT_H_

#include <map>
#include <string>
#include "Class.h"
#include "Serialization.h"

class Class;


using std::map;
using std::string;

class Object {
private:
    Class *objectClass;
    map<string, Object*> objectFields;
    map<string, int> intFields;

    friend class Serialization;
public:

    Object(Class *objectClass, const map<string, Object *>& objectFields, const map<string, int>& intFields);

    Class* getClass();

    int getInt(std::string name);

    void setInt(std::string name, int value);

    Object *getObj(std::string name);

    void setObj(std::string name, Object *value);

    virtual void invokeMethod(std::string name);

    bool isInstanceOf(std::string c);

};

#endif /* OBJECT_H_ */
