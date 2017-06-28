#ifndef OBJECT_H_
#define OBJECT_H_
#include<string>
#include "Class.h"
class Class;
/**
 * The object class describe an object in this world.
 * The Class is the factory of that Object.
 */
class Object {
public:
	Object() = default;
	explicit Object( Class* creator );

	Class* getClass() const;

	
	int getInt(std::string name);

	void setInt(std::string name, int value);
	
	Object* getObj(std::string name);

	void setObj(std::string name, Object* value);

	virtual void invokeMethod(std::string name);

	bool isInstanceOf(std::string c) const;
	
	bool isKindOf(std::string c) const;

	bool isAccessible() const {return this->klass->isAccessible();}

	virtual ~Object();
private:
	Class* klass;
	FieldMap fields;


	Field* findField(const std::string& name);
};

#endif /* OBJECT_H_ */
