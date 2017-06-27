#include "Object.h"



Object::Object( Class * creator )
{
	this->klass = creator;
	//TODO:copy fields from creator

}

Class * Object::getClass()
{
	return this->klass;
}

void Object::invokeMethod( std::string name )
{
	Method method=klass->getMethod( name );
	method.invoke( this );
}

bool Object::isInstanceOf( std::string c )
{
	return this->klass->name() == c;
}

bool Object::isKindOf( std::string c )
{
	Class* parent = getClass();
	std::string name = parent->name();
	while(c!=name && parent!=nullptr )
	{
		parent = parent->getSuperClass();
		name = parent->name();
	}
	return c == name;
}
