#include "Class.h"


Class::Class(Class* c, const std::string& name): parent(c), className(name), members(), staticFields(), classInstances() {
	ClassMapPair pair(name, this);
	classMap.insert(pair);
}

Class* Class::getSuperClass() { return this->parent; }

Object* Class::newInstance() {
	Object* newObject = new Object(this);
	classInstances.push_back(newObject);
	return newObject;
}

void Class::addMethod(std::string name, Func func) {
	Method* newMethod = new Method(name, this->name(), func);
	ClassMemberPair pair(name, newMethod);
	members.insert(pair);
}

void Class::addInstanceField( std::string name , Type t )
{
	
}

std::string Class::name() const { return this->className; }

void Class::setAccessible(bool flag) { isAccessibleClass = flag; }

Class* Class::forName(std::string name) {
	ClassMap::const_iterator iterator_result = classMap.find(name);
	return iterator_result == classMap.end() ? throw ClassNotFound() : iterator_result->second;
}

Field Class::getField( std::string name )
{
	return *getMember<Field , FieldNotFound>(name);
}

std::list<Field> Class::getFields()
{
	return getMembersOfType<Field>();
}

Method Class::getMethod(std::string name) {
	return *getMember<Method,MethodNotFound>(name);
}

std::list<Method> Class::getMethods(){
	return getMembersOfType<Method>();
}

