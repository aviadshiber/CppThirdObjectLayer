#ifndef OBJECT_H_
#define OBJECT_H_

class Class;
class Field;
#include<string>
#include "ClassDS.h"
#include "Class.h"

/**
 * The object class describe an object in this world.
 * The Class is the factory of that Object.
 */
class Object {
	friend class Class;
public:
	Object() = default;
	/**
	 * \brief create an object from creator.
	 * all the fields from the creator will be copied(that are not static).
	 * \param creator is the factory object which created this object.
	 */
	explicit Object( Class* creator );

	/**
	 * \brief get the Class which created the object.
	 * nullptr will be returned when the object was created by his factory (Class class)
	 * \return the creator of that object.
	 */
	Class* getClass() const;


	/**
	 * \brief get the integer value from the object field.
	 * \param name the name of field
	 * \return the value of the field
	 */
	virtual int getInt(std::string name);

	/**
	 * \brief set the integer value from the object field.
	 * \param name the name of field
	 * \param value the value of the field
	 */
	virtual void setInt(std::string name, int value);

	/**
	 * \brief get the Object* value from the object field.
	 * \param name the name of the field.
	 * \return pointer to the Object value of that field.
	 */
	virtual Object* getObj(std::string name);

	/**
	 * \brief set the object field with new value.
	 * \param name  the name of the field.
	 * \param value the value of the field.
	 */
	virtual void setObj(std::string name, Object* value);

	/**
	 * \brief invoke a method of the object.
	 * \param name the name of the object.
	 */
	virtual void invokeMethod(std::string name);
	
	/**
	 * \brief checks if that object is an instance of a class.
	 * \param c the name of the class
	 * \return true if it is an instance of a class, false otherwise.
	 */
	bool isInstanceOf(std::string c) const;
	
	/**
	 * \brief checks if the object is an instance of the class, or one of the classes which inherit from that class. 
	 * \param c 
	 * \return 
	 */
	bool isKindOf(std::string c) const;

	/**
	 * \brief checks if the class allow the object to be accessible to none-public members.
	 * \return true if it allow access, false otherwise.
	 */
	bool isAccessible() const;

	virtual ~Object();
private:
	Class* klass;
	FieldMap fields;
	bool canAccess;

	/**
	 * \brief find the field in the object, or a static field.
	 * \param name the name of the field to look for.
	 * \return the original field that was created in that object or class(if static).
	 */
	Field* findField(const std::string& name);
	
};

#endif /* OBJECT_H_ */
