#include "Object.h"
#include "Class.h"
#include "Exceptions.h"
#include <assert.h>
#include <iostream>

using std::cout;

bool Object_test1();

int main() {
	bool res = Object_test1();
    std::cout << ((res) ? "true" : "false");
	return 0;
}

class A {
};

Class A_class(NULL, "A");

void g(Object* obj) {
	obj->setInt("x", 1001); //works well

	Object* o2 = A_class.newInstance();
	o2->setInt("x", 2); //throws fieldnotaccessible (trying to   the value of field of another object)

}

bool Object_test1() {
	//you can assume no call to get/set will be placed here.

	A_class.addInstanceField("x", INT);
	A_class.addMethod("g", g);

	Object* obj = A_class.newInstance();
	assert(obj->isInstanceOf("A"));

	try {
		obj->invokeMethod("g");
		return false;
	} catch (...) {

	}

	return true;
}