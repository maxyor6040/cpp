
#ifndef FIELD_H_
#define FIELD_H_

#include "Object.h"

class Field  {
private:

public:
	Field(std::string name, std::string className);

	Type getType();
	
	void setInt(Object* obj, int value);

	int getInt(Object* obj);
	
	void setObj(Object* obj, Object* value);

	int getObj(Object* obj);

	std::string getDeclaringClass() const;
	
	std::string name() const;

	
};

#endif /* FIELD_H_ */
