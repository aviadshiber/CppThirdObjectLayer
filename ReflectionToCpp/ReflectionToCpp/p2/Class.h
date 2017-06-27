#ifndef CLASS_H_
#define CLASS_H_
#include "Object.h"
#include "Field.h"
#include <list>
#include "Method.h"
#include "ClassDS.h"
#include <regex>


class Class{

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

	static Class* forName( std::string name );
private:
	static bool isAccessibleClass = false;
	static ClassMap classMap=ClassMap();
	Class* parent;
	std::string className;
	//map of name->member
	MemberMap members;
	//map of name->static fields
	FieldMap staticFields;
	std::vector<Object*> classInstances;
	

};

#endif /* CLASS_H_ */
