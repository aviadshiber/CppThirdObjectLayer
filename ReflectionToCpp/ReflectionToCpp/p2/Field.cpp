#include "Field.h"


Field::Field(std::string name, std::string className, Type t, bool isStatic): Member(name, className, PRIVATE), fieldType(t), staticField(isStatic) ,fieldValue(),instance(nullptr){
	if (staticField) { privacy = PUBLIC; }
	fieldValue.number = 0; //same as NULL to object
}

Type Field::getType() const {
	return this->fieldType;
}

void Field::validateField(Object* obj,Type t) const {
	if ( fieldType != t ) { throw TypeError(); }
	if ( !obj->isKindOf( getDeclaringClass() )  ) { throw FieldNotFound(); }
	if ( !obj->isAccessible() && privacy != PUBLIC ) { throw FieldNotAccessible(); }
	//squeak like private access(only the object that created the object can acess the field)
	if ( this->instance != nullptr && obj != this->instance ) { throw FieldNotAccessible(); }
}




void Field::setInt( Object * obj , int value ){
	validateField( obj ,INT);
	fieldValue.number = value;
}

void Field::setInt( int value )
{
	validateStaticField( INT );
	fieldValue.number = value;
}


int Field::getInt(Object* obj) const {
	validateField( obj,INT );
	return fieldValue.number;
}

int Field::getInt(  ) const
{
	validateStaticField( INT );
	return fieldValue.number;
}

void Field::setObj( Object * obj , Object * value )
{
	validateField( obj , OBJECT );
	fieldValue.object = value;
}

void Field::setObj( Object * value )
{
	validateStaticField( OBJECT );
	fieldValue.object = value;
}

Object * Field::getObj( Object * obj ) const {
	validateField( obj , OBJECT );
	return fieldValue.object;
}

Object * Field::getObj() const
{
	validateStaticField( OBJECT );
	return fieldValue.object;
}

bool Field::isStatic() const {
	return staticField;
}

Type Field::getFieldType() const { return fieldType; }
Field* Field::setInstanceToField(Object* obj) {
	this->instance = obj;
	return this;
}


void Field::validateStaticField( Type t) const {
	if ( fieldType != t ) { throw TypeError(); }
}
