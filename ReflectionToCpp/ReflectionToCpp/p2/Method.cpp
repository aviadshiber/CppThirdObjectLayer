#include "Method.h"

Method::Method(string name, string className, Func f): Member(name, className, PUBLIC), function(f) {}

void Method::invoke( Object * const obj ){
	function( obj );
}

Method::~Method() {}
