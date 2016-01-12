#ifndef METHOD_H_
#define METHOD_H_

#include <string>
#include "Object.h"


typedef void(*Func)(Object *);

class Method {
private:
    std::string methodName;
    std::string className;
    Func func;

public:

    std::string getDeclaringClass() const;

    Method(std::string name, std::string className, Func f);

    virtual void invoke(Object *const obj);

    std::string name() const;

};


#endif /* METHOD_H_ */
