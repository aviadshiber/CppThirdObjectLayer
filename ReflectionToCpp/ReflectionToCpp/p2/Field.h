
#ifndef FIELD_H_
#define FIELD_H_
#include "Exceptions.h"
#include <string>
#include "Member.h"
#include "Object.h"

class Class;
class Object;

class Field:public Member {

	
public:
	Field(std::string name, std::string className, Type t, bool isStatic);
	Type getType() const;
	
	void setInt(Object* obj, int value);
	void setInt( Class* obj , int value );

	int getInt(Object* obj) const;
	int getInt( Class* obj ) const;

	void setObj(Object* obj, Object* value);
	void setObj( Class* obj , Object* value );

	Object* getObj(Object* obj) const;
	Object* getObj( Class* obj ) const;

	bool isStatic() const;

	Type getFieldType() const;

	Field* setInstanceToField( Object* obj );

private:
	Type fieldType;
	bool staticField;
	union Value { 
	Object* object;
	int number;
	}fieldValue;
	Object* instance;
	void validateField( Object* obj , Type t ) const;
};

#endif /* FIELD_H_ */
