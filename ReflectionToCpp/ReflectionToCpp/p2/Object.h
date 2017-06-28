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

	Class* getClass();

	int getInt(std::string name);

	void setInt(std::string name, int value);
	
	Object* getObj(std::string name);

	void setObj(std::string name, Object* value);

	virtual void invokeMethod(std::string name);

	/**
	 * \brief check if c is an instance of the class c.
	 * \param c 
	 * \return 
	 */
	bool isInstanceOf(std::string c);
	
	bool isKindOf(std::string c);

	bool isAccessible() const {return this->klass->isAccessible();}

	virtual ~Object();
private:
	Class* klass;
	FieldMap fields;
};

#endif /* OBJECT_H_ */
