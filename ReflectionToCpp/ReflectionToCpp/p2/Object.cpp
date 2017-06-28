#include "Object.h"


Object::Object(Class* creator) {
	this->klass = creator;
	FieldList fieldsList = creator->getFields();
	//copy the fields of the creator until this point( that are not static)
	for (FieldList::iterator it = fieldsList.begin(); it != fieldsList.end(); ++it)
	{
		if ( !it->isStatic() ) {
			Field* copy = new Field( *it );
			FieldMapPair pair( it->name() , copy );
			fields.insert( pair );
		}
		
	}
}

Class* Object::getClass() { return this->klass; }

void Object::invokeMethod(std::string name) {
	Method method = klass->getMethod(name);
	method.invoke(this);
}

bool Object::isInstanceOf(std::string c) { return this->klass->name() == c; }

bool Object::isKindOf(std::string c) {
	Class* parent = getClass();
	std::string name = parent->name();
	while (c != name && parent != nullptr)
	{
		parent = parent->getSuperClass();
		name = parent->name();
	}
	return c == name;
}

Object::~Object() {
	for (auto it = fields.begin(); it != fields.end(); ++it){
		Field* fieldToFree = it->second;
		delete fieldToFree;
	}
}
