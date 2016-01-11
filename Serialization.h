#ifndef SERIALIZATION_H_
#define SERIALIZATION_H_



class Serialization {
private:

public:

	static string serialize(Object& o);
	
	static Object* deserialize(string s);

};

#endif /* SERIALIZATION_H_ */
