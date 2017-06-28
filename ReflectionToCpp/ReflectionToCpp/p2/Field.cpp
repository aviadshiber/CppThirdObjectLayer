#include "Field.h"

Field::Field(std::string name, std::string className, Type t, bool isStatic): Member(name, className, PRIVATE), fieldType(t), staticField(isStatic) {
	if (staticField) { privacy = PUBLIC; }
}

Type Field::getType()
{
	return this->fieldType;
}

bool Field::isStatic() const {
	return staticField;
}


