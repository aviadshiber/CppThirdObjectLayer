#include "Object.h"


Object::Object(Class* creator):klass(creator),fields(),canAccess(false) {
	if ( creator != nullptr ) {
		FieldList fieldsList = creator->getFields();
		//copy the fields of the creator until this point( that are not static)
		if ( fieldsList.size() > 0 ) {
			for ( FieldList::const_iterator it = fieldsList.begin(); it != fieldsList.end(); ++it ) {
				if ( !it->isStatic() ) {
					Field* copy = it->clone();
					copy->setInstanceToField( this );
					FieldMapPair pair( it->name() , copy );
					this->fields.insert( pair );
				}
			}
		}
		canAccess = creator->isAccessible();
	}
}

Class* Object::getClass() const { return this->klass; }

int Object::getInt(string name) { return findField(name)->getInt(this); }

void Object::setInt(string name, int value) { findField(name)->setInt(this, value); }

Object* Object::getObj(string name) { return findField(name)->getObj(this); }

void Object::setObj(string name, Object* value) { return findField(name)->setObj(this, value); }

Field* Object::findField(const string& name) {
	FieldMap::iterator iterator_result = fields.find(name);
	if (iterator_result == fields.end()){
		//field was not found in object,maybe it is a static field.. fetch it from the class
		Field* field = klass->getOriginalField(name,false,true );
		return field; 
	}
	return iterator_result->second;
}

void Object::invokeMethod(string name) {
	bool accessCheckPoint = this->canAccess;
	this->canAccess = true;
	try{
		Method method = getClass()->getMethod(name);
		method.invoke( this );
	}
	catch ( TypeError& e ) {
		this->canAccess = accessCheckPoint;
		throw e;
	}catch(MethodNotFound&e ){
		this->canAccess = accessCheckPoint;
		throw e;
	}catch ( FieldNotFound& e ) {
		this->canAccess = accessCheckPoint;
		throw e;
	}catch ( FieldNotAccessible& e ) {
		this->canAccess = accessCheckPoint;
		throw e;
	}
	this->canAccess = accessCheckPoint;
}

bool Object::isInstanceOf(string c) const {
	if ( getClass() == nullptr ) return true;
	return getClass()->name() == c;
}

bool Object::isKindOf(string c) const {
	Class* parent = getClass();
	//in case Class is the object
	if ( parent == nullptr ) return true;

	string name = parent->name();
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
