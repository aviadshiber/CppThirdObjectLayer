#include "Class.h"


Class::Class(Class* c, const std::string& name): Object(nullptr), parent(c), className(name), members(), classInstances() {
	ClassMapPair pair(name, this);
	classMap.insert(pair);
}

Class* Class::getSuperClass() const { return this->parent; }

Object* Class::newInstance() {
	Object* newObject = new Object(this);
	classInstances.push_back(newObject);
	return newObject;
}

void Class::addMethod(std::string name, Func func) {
	Method* newMethod = new Method(name, this->name(), func);
	addMember(name, newMethod);
}

void Class::addInstanceField(std::string name, Type t) {
	Field* field = new Field(name, this->name(), t, false);
	addMember(name, field);
}

void Class::addStaticField(std::string name, Type t) {
	Field* field = new Field(name, this->name(), t, true);
	addMember(name, field);
}

void Class::addMember(std::string name, Member* member) {
	ClassMemberPair pair(name, member);
	members.insert(pair);
}

std::string Class::name() const { return this->className; }

Class::~Class() {
	//removing all members
	for (auto it = members.begin(); it != members.end(); ++it)
	{
		Member* member = it->second;
		delete member;
	}
	//removing all class instances
	for (auto it = classInstances.begin(); it != classInstances.end(); ++it)
	{
		Object* obj = *it;
		delete obj;
	}
}

void Class::setAccessible(bool flag) { isAccessibleClass = flag; }
bool Class::isAccessible() { return isAccessibleClass; }

Class* Class::forName(std::string name) {
	ClassMap::const_iterator iterator_result = classMap.find(name);
	return iterator_result == classMap.end() ? throw ClassNotFound() : iterator_result->second;
}


Field Class::getField(std::string name) { return *getOriginalField(name); }
Field* Class::getOriginalField(std::string name) { return getMember<Field, FieldNotFound>(name); }

std::list<Field> Class::getFields() { return getMembersOfType<Field>(); }

std::list<Field> Class::getStaticFields() {
	std::list<Field> staticFields;
	std::list<Field> allFields = getFields();
	for (auto it = allFields.begin(); it != allFields.end(); ++it) { if (it->isStatic()) { staticFields.push_back(*it); } }
	return staticFields;
}

Method Class::getMethod(std::string name) { return *getMember<Method, MethodNotFound>(name); }

std::list<Method> Class::getMethods() { return getMembersOfType<Method>(); }

int Class::getInt(std::string name) {
	Field* field = fetchClassField(name);
	return field->getInt(this);
}

void Class::setInt(std::string name, int value) {
	Field* field = fetchClassField(name);
	field->setInt(this, value);
}

Object* Class::getObj(std::string name) {
	Field* field = fetchClassField(name);
	return field->getObj(this);
}

void Class::setObj(std::string name, Object* value) {
	Field* field = fetchClassField(name);
	field->setObj(this, value);
}

Field* Class::fetchClassField(const std::string& fieldName) {
	Field* field = getOriginalField(fieldName);
	//Class feilds are fields that are static. 
	//if we found a field that can be setted/getted from class that is not static it means it is taken by non-static and should be considered as not found
	if (!field->isStatic()) { throw FieldNotFound(); }
	return field;
}
