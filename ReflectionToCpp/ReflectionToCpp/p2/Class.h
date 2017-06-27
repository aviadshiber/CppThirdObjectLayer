#ifndef CLASS_H_
#define CLASS_H_
#include <string>
#include "Object.h"


class Class{

private:
public:
	Class(Class* c, const std::string& name);
		
	Class* getSuperClass();
	
	Object* newInstance();

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
	
	std::string name() const;

	static void setAccessible(bool flag);


};

#endif /* CLASS_H_ */
