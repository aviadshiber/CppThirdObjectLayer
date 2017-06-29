#ifndef OBJECT_H_
#define OBJECT_H_

class Class;
class Field;
class Object;
#include<string>
#include <list>
#include <unordered_map>
#include "Class.h"
using namespace std;
typedef unordered_map< string , Field* >  FieldMap;
typedef pair< string , Field* >  FieldMapPair;
typedef list< Field > FieldList;

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
	virtual int getInt(string name);

	/**
	 * \brief set the integer value from the object field.
	 * \param name the name of field
	 * \param value the value of the field
	 */
	virtual void setInt(string name, int value);

	/**
	 * \brief get the Object* value from the object field.
	 * \param name the name of the field.
	 * \return pointer to the Object value of that field.
	 */
	virtual Object* getObj(string name);

	/**
	 * \brief set the object field with new value.
	 * \param name  the name of the field.
	 * \param value the value of the field.
	 */
	virtual void setObj(string name, Object* value);

	/**
	 * \brief invoke a method of the object.
	 * \param name the name of the object.
	 */
	virtual void invokeMethod(string name);
	
	/**
	 * \brief checks if that object is an instance of a class.
	 * \param c the name of the class
	 * \return true if it is an instance of a class, false otherwise.
	 */
	bool isInstanceOf(string c) const;
	
	/**
	 * \brief checks if the object is an instance of the class, or one of the classes which inherit from that class. 
	 * \param c 
	 * \return 
	 */
	bool isKindOf(string c) const;

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
	Field* findField(const string& name);
	
};

#endif /* OBJECT_H_ */
