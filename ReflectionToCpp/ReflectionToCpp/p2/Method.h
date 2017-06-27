
#ifndef METHOD_H_
#define METHOD_H_
#include "Object.h"
#include <string>


typedef void(*Func)(Object*);

class Method{
private:


public:

	std::string getDeclaringClass() const;

	Method(std::string name,std::string className,Func f);

	virtual void invoke(Object* const obj);
	
	std::string name() const;

};


#endif /* METHOD_H_ */
