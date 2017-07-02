#include "Method.h"
#include "Exceptions.h"

Method::Method(string name, string className, Func f): Member(name, className, PUBLIC), function(f) {}

void Method::invoke( Object * const obj ){
	if ( obj == nullptr ) throw MethodNotFound();
	function( obj );
}

Method::~Method() {}
