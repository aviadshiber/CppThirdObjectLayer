#include "Object.h"


Object::Object(Class* creator):klass(creator),fields() {
	if ( creator != nullptr ) {
		FieldList fieldsList = creator->getFields();
		//copy the fields of the creator until this point( that are not static)
		if ( fieldsList.size() > 0 ) {
			for ( FieldList::iterator it = fieldsList.begin(); it != fieldsList.end(); ++it ) {
				if ( !it->isStatic() ) {
					Field* copy = new Field( *it );
					copy->setInstanceToField( this );
					FieldMapPair pair( it->name() , copy );
					fields.insert( pair );
				}
			}
		}
	}
}

Class* Object::getClass() const { return this->klass; }

int Object::getInt(std::string name) { return findField(name)->getInt(this); }

void Object::setInt(std::string name, int value) { findField(name)->setInt(this, value); }

Object* Object::getObj(std::string name) { return findField(name)->getObj(this); }

void Object::setObj(std::string name, Object* value) { return findField(name)->setObj(this, value); }

Field* Object::findField(const std::string& name) {
	FieldMap::iterator iterator_result = fields.find(name);
	if (iterator_result == fields.end()){
		//field was not found in object,maybe it is a static field.. fetch it from the class
		Field* field = klass->getOriginalField(name);
		if (field->isStatic()) { return field; }
		//if it is not a static field then we should not get it from class. the field was not found.
		throw FieldNotFound();
	}
	return iterator_result->second;
}

void Object::invokeMethod(std::string name) {
	this->canAccess = true;
	Method method = getClass()->getMethod(name);
	method.invoke(this);
	this->canAccess = getClass()->isAccessible();
}

bool Object::isInstanceOf(std::string c) const {
	if ( getClass() == nullptr ) return true;
	return getClass()->name() == c;
}

bool Object::isKindOf(std::string c) const {
	Class* parent = getClass();
	//in case Class is the object
	if ( parent == nullptr ) return true;

	std::string name = parent->name();
	while (c != name && parent != nullptr){
		name = parent->name();
		parent = parent->getSuperClass();
	}
	return c == name;
}

Object::~Object() {
	if ( fields.size() > 0 ) {
		for ( auto it = fields.begin(); it != fields.end(); ++it ) {
			Field* fieldToFree = it->second;
			delete fieldToFree;
		}
	}
}

bool Object::isAccessible() const {
	//special case for Class object
	if ( getClass() == nullptr ) return true;
	return canAccess;
}
