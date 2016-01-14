
#ifndef FIELD_H_
#define FIELD_H_


#include "Object.h"
#include "Exceptions.h"

class Object;

class Field  {
private:
    std::string fieldName;
    std::string className;
    Type type;

	void assertLegalAccess(Object *o);
public:
	Field(std::string fieldName, std::string className);

	Type getType();

    void setType(Type);
	
	void setInt(Object* obj, int value);

	int getInt(Object* obj);
	
	void setObj(Object* obj, Object* value);

	Object* getObj(Object* obj);

	std::string getDeclaringClass() const;
	
	std::string name() const;

	
};


#endif /* FIELD_H_ */
