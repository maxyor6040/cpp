#ifndef OBJECT_H_
#define OBJECT_H_

#include <string>

class Class;

class Field;

class Object {
private:
    Class *objectClass;
    std::list<Field> fields;
public:

    // you must add a function called getClass() that returns a pointer to the object's class
    Class *getClass();

    int getInt(std::string name);

    void setInt(std::string name, int value);

    Object *getObj(std::string name);

    void setObj(std::string name, Object *value);

    virtual void invokeMethod(std::string name);

    bool isInstanceOf(std::string c);

};

#endif /* OBJECT_H_ */
