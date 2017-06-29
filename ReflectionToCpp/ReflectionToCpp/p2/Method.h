
#ifndef METHOD_H_
#define METHOD_H_
#include "Member.h"
class Object;
typedef void( *Func )( Object* );
using namespace std;

/*
 * The Method class describes the method members in a class.
 */
class Method :public Member{

public:

	Method(string name, string className, Func f);

	virtual void invoke(Object* const obj);

	virtual ~Method();
private:
	Func function;
};


#endif /* METHOD_H_ */
