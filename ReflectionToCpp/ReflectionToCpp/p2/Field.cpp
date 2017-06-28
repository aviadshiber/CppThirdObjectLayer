#include "Field.h"

Field::Field(std::string name, std::string className, Type t, bool isStatic): Member(name, className, PRIVATE), fieldType(t), staticField(isStatic) {
	if (staticField) { privacy = PUBLIC; }
}

Type Field::getType() const {
	return this->fieldType;
}

void Field::validateField(Object* obj,Type t) const {
	if ( fieldType != t ) { throw TypeError(); }
	if ( !obj->isAccessible() && privacy != PUBLIC ) { throw FieldNotAccessible(); }
}

void Field::setInt( Object * obj , int value ){
	validateField( obj ,INT);
	fieldValue.number = value;
}

int Field::getInt(Object* obj) const {
	validateField( obj,INT );
	return fieldValue.number;
}

void Field::setObj( Object * obj , Object * value )
{
	validateField( obj , OBJECT );
	fieldValue.object = value;
}

Object * Field::getObj( Object * obj ) const {
	validateField( obj , OBJECT );
	return fieldValue.object;
}

bool Field::isStatic() const {
	return staticField;
}

Type Field::getFieldType() const { return fieldType; }


