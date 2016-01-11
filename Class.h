#ifndef CLASS_H_
#define CLASS_H_



class Class{

private:
public:
	/*
		you need to add a constructor that gets a pointer to the Base class and the name of this class.
		you must also add getSuperClass() that returns a pointer to the super class
	*/
	
	Object* newIstance();

	void addMethod(std::string name, Func func);
	

	void addInstanceField(std::string name, Type t);

	void addStaticField(std::string name, Type t);

	Field getField(std::string name);

	std::list<Field> getFields();

	Method getMethod(std::string name);

	std::list<Method> getMethods();

	int getInt(std::string name);

	void setInt(std::string name, int value);

	Object* getObj(std::string name);

	void setObj(std::string name, Object* value);


};

#endif /* CLASS_H_ */
