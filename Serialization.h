#ifndef SERIALIZATION_H_
#define SERIALIZATION_H_


#include "Object.h"
#include <string>

using std::string;

class Object;

class Serialization {
private:

public:

	static string serialize(Object& o);

	static Object* deserialize(string s);

	static Object* deserialize_aux(string& s);

};

#endif /* SERIALIZATION_H_ */
