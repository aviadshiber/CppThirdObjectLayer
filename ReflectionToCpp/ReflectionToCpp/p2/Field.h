
#ifndef FIELD_H_
#define FIELD_H_
#include "Exceptions.h"
#include <string>
#include "Member.h"

class Object;

class Field:public Member {

	
public:
	Field(std::string name, std::string className, Type t, bool isStatic);

	Type getType();
	
	void setInt(Object* obj, int value);

	int getInt(Object* obj);
	
	void setObj(Object* obj, Object* value);

	Object* getObj(Object* obj);

	bool isStatic() const;
private:
	Type fieldType;
	bool staticField;

	
};

#endif /* FIELD_H_ */
