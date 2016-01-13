#include <iostream>
#include "Object.h"
#include "Class.h"

using namespace std;

int main() {
    cout << "Hello, World!" << endl;

    Class A_class(NULL,"A");//building new class,(super=null)
    Class B_class(&A_class,"B");//B_class inherits A_class
    A_class.addInstanceField("x",INT);
    Object* a = A_class.newInstance();
    cout << a->getInt("x") ; //prints 0
    a->setInt("x",5);
    cout << a->getInt("x") ;

    return 0;
}