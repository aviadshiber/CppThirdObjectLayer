
#ifndef FIELD_H_
#define FIELD_H_
#include "Exceptions.h"
#include <string>
#include "Member.h"
#include "Object.h"
#include <memory>

class Class;
class Object;
using namespace std;
union Value {
	Object* object;
	int number;
};
typedef std::shared_ptr<Value> ValuePtr;

class Field:public Member {

	
public:
	Field(string name, string className, Type t, bool isStatic);
	Type getType() const;
	
	void setInt(Object* obj, int value) const;
	void setInt(int value) const;

	int getInt(Object* obj) const;
	int getInt() const;

	void setObj(Object* obj, Object* value) const;
	void setObj(Object* value) const;

	Object* getObj(Object* obj) const;
	Object* getObj() const;

	Type getFieldType() const;

	Field* setInstanceToField( Object* obj );

	Field* clone() const;


private:
	Type fieldType;
	ValuePtr fieldValue;
	Object* instance;
	void validateField( Object* obj , Type t ) const;
	void validateStaticField(Type t) const;
};

#endif /* FIELD_H_ */
