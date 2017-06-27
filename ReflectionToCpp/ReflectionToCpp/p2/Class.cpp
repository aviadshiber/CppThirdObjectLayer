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

std::string Class::name() const { return this->className; }

void Class::setAccessible(bool flag) { isAccessibleClass = flag; }

Class* Class::forName(std::string name) {
	ClassMap::const_iterator iterator_result = classMap.find(name);
	return iterator_result == classMap.end() ? throw ClassNotFound() : iterator_result->second;
}

Method Class::getMethod(std::string name) {
	Member* member = nullptr;

	Class* currentClass = this;
	while (currentClass != nullptr)
	{
		MemberMap::iterator iterator_result = currentClass->members.find(name);
		if (iterator_result == members.end()) { currentClass = currentClass->getSuperClass(); }
		else{
			member = iterator_result->second;
			break;
		}
	}

	if (currentClass != nullptr && instanceof<Method>(member))
	{
		Method* method = static_cast<Method*>(member);
		return *method;
	}

	throw MethodNotFound();
}
