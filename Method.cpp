
#include "Method.h"

Method::Method(std::string name, std::string className, Func f):className(className),methodName(name), func(f) { }

std::string Method::getDeclaringClass() const {
    return className;
}

void Method::invoke(Object *const obj) {
    func(obj);
}

std::string Method::name() const {
    return methodName;
}
