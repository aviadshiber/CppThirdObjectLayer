
#ifndef METHOD_H_
#define METHOD_H_
#include "Object.h"
#include <string>


typedef void(*Func)(Object*);

class Method :public Member{

public:
	
	Method( std::string name , std::string className , Func f ) :Member( name , className , PUBLIC ),function(f) {}

	virtual void invoke(Object* const obj);

	virtual ~Method() = default;
private:
	std::string methodName;
	Func function;
};


#endif /* METHOD_H_ */
