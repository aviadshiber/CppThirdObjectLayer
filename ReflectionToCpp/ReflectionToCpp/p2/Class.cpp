#include "Class.h"
#include <iostream>


ClassMap & Class::getClassMapInstance()
{
	static ClassMap singletonMap;
	return singletonMap;

}

//ClassMap Class::classMap = getClassMapInstance();
bool Class::isAccessibleClass = false;



Class::Class(Class* c, const string name):parent(c), className(name), members(), classInstances() {
	ClassMapPair pair(name, this);
	getClassMapInstance().insert(pair);
}

Class* Class::getSuperClass() const { return this->parent; }

Object* Class::newInstance() {
	Object* newObject = new Object(this);
	classInstances.push_back(newObject);
	return newObject;
}

void Class::addMethod(string name, Func func) {
	Method* newMethod = new Method(name, this->name(), func);
	addMember(name, newMethod);
}

void Class::addInstanceField(string name, Type t) {
	Field* field = new Field(name, this->name(), t, false);
	addMember(name, field);
}

void Class::addStaticField(string name, Type t) {
	Field* field = new Field(name, this->name(), t, true);
	addMember(name, field);
}





void Class::addMember(string name, Member* member) {
	ClassMemberPair pair(name, member);
	members.insert(pair);
}

string Class::name() const { return this->className; }

Class::~Class() {
	//removing all members
	if ( members.size() > 0 ) {
		for ( auto it = members.begin(); it != members.end(); ++it )
		{
			Member* member = it->second;
			delete member;
		}
	}
	//removing all class instances
	if ( classInstances.size() > 0 ) {
		for ( auto it = classInstances.begin(); it != classInstances.end(); ++it )
		{
			Object* obj = *it;
			delete obj;
		}
	}
	getClassMapInstance().erase( this->className );
}

void Class::setAccessible(bool flag) {
	isAccessibleClass = flag;
	for(auto it= getClassMapInstance().begin(); it!= getClassMapInstance().end(); ++it ){
		Class* currentClass = it->second;
		currentClass->updateInstancesAccess( flag );
		//cout << "class " << currentClass->name() << " is now accessible?" << flag << endl;;
	}
}
bool Class::isAccessible() { return isAccessibleClass; }

Class* Class::forName(string name) {
	ClassMap::const_iterator iterator_result = getClassMapInstance().find(name);
	return iterator_result == getClassMapInstance().end() ? throw ClassNotFound() : iterator_result->second;
}


Field Class::getField(string name) { return *getOriginalField(name,true, true); }
Field* Class::getOriginalField(string name,bool searchAll,bool isStatic) { return getMember<Field, FieldNotFound>(name,searchAll,isStatic); }

list<Field> Class::getFields() { return getMembersOfType<Field>(); }

list<Field> Class::getStaticFields() {
	list<Field> staticFields;
	list<Field> allFields = getFields();
	for (auto it = allFields.begin(); it != allFields.end(); ++it) { if (it->isStatic()) { staticFields.push_back(*it); } }
	return staticFields;
}

Method Class::getMethod(string name) { return *getMember<Method, MethodNotFound>(name,true,false); }

list<Method> Class::getMethods() { return getMembersOfType<Method>(); }

int Class::getInt(string name) {
	Field* field = fetchClassField(name);
	return field->getInt();
}

void Class::setInt(string name, int value) {
	Field* field = fetchClassField(name);
	field->setInt(value);
}

Object* Class::getObj(string name) {
	Field* field = fetchClassField(name);
	return field->getObj();
}

void Class::setObj(string name, Object* value) {
	Field* field = fetchClassField(name);
	field->setObj(value);
}



Field* Class::fetchClassField(const string& fieldName) {
	Field* field = getOriginalField(fieldName,false,true );
	return field;
}

void Class::updateInstancesAccess(bool flag) {
	if ( classInstances.size() == 0 ) return;
	for ( auto it = this->classInstances.begin(); it != classInstances.end(); ++it ){
		Object* obj = *it;
		obj->canAccess = flag;
	}
}
