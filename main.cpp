#include "Object.h"
#include "Class.h"
#include "Exceptions.h"
#include <assert.h>
#include <iostream>

using std::cout;

bool Object_test1();

bool Object_test2() ;

int main() {
    bool res = Object_test1();
    std::cout << ((res) ? "true" : "false");
    res = Object_test2();
    return 0;
}

class A {
};

Class A_class(NULL, "A");
Class B_class(NULL, "B");

void g(Object *obj) {
    obj->setInt("x", 1001); //works well

    Object *o2 = A_class.newInstance();
    o2->setInt("x", 2); //throws fieldnotaccessible (trying to   the value of field of another object)

}

bool Object_test1() {
    //you can assume no call to get/set will be placed here.

    A_class.addInstanceField("x", INT);
    A_class.addMethod("g", g);

    Object *obj = A_class.newInstance();
    assert(obj->isInstanceOf("A"));

    try {
        obj->invokeMethod("g");
        return false;
    } catch (...) {

    }

    return true;
}

bool Object_test2() {
    //you can assume no call to get/set will be placed here.
    Class::setAccesible(true);
    A_class.addInstanceField("x", INT);
    A_class.addInstanceField("y", INT);
    A_class.addInstanceField("subObj", OBJECT);
    A_class.addInstanceField("subObjAgain", OBJECT);
    B_class.addInstanceField("bx", INT);
    B_class.addInstanceField("by", INT);
    //B_class.addInstanceField("bSubObj",OBJECT);
    //B_class.addInstanceField("bSubObjAgain",OBJECT);
    Object *objA = A_class.newInstance();
    Object *objB = B_class.newInstance();
    objA->setInt("x", 1);
    objA->setInt("y", 2);
    objB->setInt("bx", 3);
    objB->setInt("by", 4);
    objA->setObj("subObj", objB);
    objA->setObj("subObjAgain", objB);
    string s = Serialization::serialize(*objA);
    Serialization::deserialize(s);
    return true;
}