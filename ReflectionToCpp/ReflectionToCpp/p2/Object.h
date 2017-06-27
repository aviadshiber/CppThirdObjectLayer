#ifndef OBJECT_H_
#define OBJECT_H_
#include<string>
#include "Class.h"
class Class;

class Object {
private:
	Class* klass;
	FieldMap fields;
public:
	Object() = default;
	Object( Class* creator );

	Class* getClass();

	int getInt(std::string name);

	void setInt(std::string name, int value);
	
	Object* getObj(std::string name);

	void setObj(std::string name, Object* value);

	virtual void invokeMethod(std::string name);

	bool isInstanceOf(std::string c);
	
	bool isKindOf(std::string c);

	virtual ~Object();

};

#endif /* OBJECT_H_ */
