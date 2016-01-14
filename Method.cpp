

#include "Method.h"

Method::Method(std::string name, std::string className, Func f):className(className),methodName(name), func(f) { }

std::string Method::getDeclaringClass() const {
    return className;
}

void Method::invoke(Object *const obj) {
    Object* previousContext = Class::currentContext;
    Class::currentContext = obj;
    func(obj);
    Class::currentContext = previousContext;
}

std::string Method::name() const {
    return methodName;
}
