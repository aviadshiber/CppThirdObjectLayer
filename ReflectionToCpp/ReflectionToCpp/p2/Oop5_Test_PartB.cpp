/*
* Oop5_Test_PartB.cpp
*
*  Created on: Jun 21, 2017
*      Author: danie_000
*/
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <assert.h>
#include "Exceptions.h"
#include <exception>
#include "Class.h"

Class ZZZGetInt_class( nullptr , "ZZZGetInt_class" );
Class ZZZGetObj_class( nullptr , "ZZZGetObj_class" );
Class ZZZSetInt_class( nullptr , "ZZZSetInt_class" );
Class ZZZSetObj_class( nullptr , "ZZZSetObj_class" );

void foo1GetInt( Object* obj ) {
	Object* o2 = ZZZGetInt_class.newInstance();
	o2->getInt( "m_x" ); // FieldNotAccessible even though o2 is of same class like obj, since m_x is OBJECT Private as in squeak
}

void foo2GetInt( Object* obj ) {
	Object* o2 = ZZZGetInt_class.newInstance();
	o2->getInt( "s_x" ); // OK since static fields are public, as written in the pdf
}

void foo3GetInt( Object* obj ) {
	obj->getInt( "m_x" ); // OK cause invoking a method on obj is like obj->foo3() and obj == this inside the method, and the method is "inside" Class_A
}

void foo1GetObj( Object* obj ) {
	Object* o2 = ZZZGetObj_class.newInstance();
	o2->getObj( "m_x" ); // FieldNotAccessible even though o2 is of same class like obj, since m_x is OBJECT Private as in squeak
}

void foo2GetObj( Object* obj ) {
	Object* o2 = ZZZGetObj_class.newInstance();
	o2->getObj( "s_x" ); // OK since static fields are public, as written in the pdf
}

void foo3GetObj( Object* obj ) {
	obj->getObj( "m_x" ); // OK cause invoking a method on obj is like obj->foo3() and obj == this inside the method, and the method is "inside" Class_A
}

void foo1SetInt( Object* obj ) {
	Object* o2 = ZZZSetInt_class.newInstance();
	o2->setInt( "m_x" , 2 ); // FieldNotAccessible even though o2 is of same class like obj, since m_x is OBJECT Private as in squeak
}

void foo2SetInt( Object* obj ) {
	Object* o2 = ZZZSetInt_class.newInstance();
	o2->setInt( "s_x" , 2 ); // OK since static fields are public, as written in the pdf
}

void foo3SetInt( Object* obj ) {
	obj->setInt( "m_x" , 32 ); // OK cause invoking a method on obj is like obj->foo3() and obj == this inside the method, and the method is "inside" Class_A
}

void foo1SetObj( Object* obj ) {
	Object* o2 = ZZZSetObj_class.newInstance();
	o2->setObj( "m_x" , nullptr ); // FieldNotAccessible even though o2 is of same class like obj, since m_x is OBJECT Private as in squeak
}

void foo2SetObj( Object* obj ) {
	Object* o2 = ZZZSetObj_class.newInstance();
	o2->setObj( "s_x" , nullptr ); // OK since static fields are public, as written in the pdf
}

void foo3SetObj( Object* obj ) {
	obj->setObj( "m_x" , nullptr ); // OK cause invoking a method on obj is like obj->foo3() and obj == this inside the method, and the method is "inside" Class_A
}

void setNullptr( Object* object );
void setThree( Object* object );

void throwOnFalse( bool result , std::string s );

bool printTestSuccessOrFail( bool test_result , std::string test_name );

bool testExample();

bool testField();

bool testFieldConstructor();

bool testFieldName();

bool testFieldGetDeclaringClass();

bool testFieldGetType();

bool testFieldGetInt();

bool testFieldGetObj();

bool testFieldSetInt();

bool testFieldSetObj();

bool testMethod();

bool testMethodConstructor();

bool testMethodName();

bool testMethodInvoke();

bool testMethodGetDeclaringClass();

bool testObject();

bool testObjectConstructor();

bool testObjectGetClass();

bool testObjectGetInt();

bool testObjectGetObj();

bool testObjectSetInt();

bool testObjectSetObj();

bool testObjectInvokeMethod();

bool testObjectIsInstanceOf();

bool testObjectIsKindOf();

bool testClass();

bool testClassConstructor();

bool testClassName();

bool testClassNewInstance();

bool testClassAddMethod();

bool testClassAddInstanceField();

bool testClassAddStaticField();

bool testClassGetField();

bool testClassGetMethod();

bool testClassGetFields();

bool testClassGetMethods();

bool testClassGetInt();

bool testClassGetObj();

bool testClassSetInt();

bool testClassSetObj();

bool testClassGetSuperClass();

bool testClassSetAccessible();

bool testSameFieldName();

bool testMethodInvokesMethod();

std::string info = "The next exception happened :( @@@ Failed at: ";
class myexception : public std::exception {
	std::string s;
public:
	myexception( std::string message ) :
		s( info + message + " @@@" ) {
	}
	virtual const char* what() const throw ( ) {
		return s.c_str();
	}
};

void throwOnFalse( bool result , std::string s ) {
	if ( !result )
		throw myexception( s );
}
bool printTestSuccessOrFail( bool test_result , std::string test_name ) {
	std::cout << test_name;
	if ( test_result )
		std::cout << ": SUCCESS :)";
	else
		std::cout << ": FAILURE :(";
	std::cout << std::endl;
	return test_result;
}

/*******************************Tests section :)*******************************/
/******************************************************************************/
/******************************************************************************/

/******************************Example section :)******************************/
/******************************************************************************/
/******************************************************************************/
bool testExample() {
	try {
		Class A_class( nullptr , "A" );
		Class B_class( &A_class , "B" );
		A_class.addInstanceField( "x" , INT );
		Object* a = A_class.newInstance();
		Class::setAccessible( true );
		throwOnFalse( a->getInt( "x" ) == 0 , "a->getInt('x')==0" );
		a->setInt( "x" , 5 );
		throwOnFalse( a->getInt( "x" ) == 5 , "a->getInt('x')==5" );
	}
	catch ( std::exception& e ) {
		std::cout << e.what() << std::endl;
		return false;
	}
	return true;
}
/******************************************************************************/
/******************************************************************************/
/******************************Example section :)******************************/

/*******************************Field section :)*******************************/
/******************************************************************************/
/******************************************************************************/
bool testFieldConstructor() {
	try {
		Class A_class( nullptr , "A" );
		A_class.addInstanceField( "x" , INT );
		A_class.addInstanceField( "y" , INT );
		A_class.addInstanceField( "a" , OBJECT );
		A_class.addInstanceField( "b" , OBJECT );
		A_class.addStaticField( "counter" , INT );
		A_class.addStaticField( "cool" , OBJECT );
		A_class.newInstance();

	}
	catch ( std::exception& e ) {
		std::cout << e.what() << std::endl;
		return false;
	}
	return true;
}
bool testFieldName() {
	try {
		Class A_class( nullptr , "A" );
		A_class.addStaticField( "x" , INT );
		A_class.addStaticField( "y" , INT );
		A_class.addStaticField( "a" , OBJECT );
		A_class.addStaticField( "b" , OBJECT );
		A_class.addStaticField( "counter" , INT );
		A_class.addStaticField( "cool" , OBJECT );
		Object* a = A_class.newInstance();
		Class::setAccessible( true );
		throwOnFalse( a->getClass()->getField( "x" ).name().compare( "x" ) == 0 ,
			"a->getClass()->getField('x').name().compare('x')==0" );
		throwOnFalse( a->getClass()->getField( "y" ).name().compare( "y" ) == 0 ,
			"a->getClass()->getField('y').name().compare('y')==0" );
		throwOnFalse( a->getClass()->getField( "a" ).name().compare( "a" ) == 0 ,
			"a->getClass()->getField('a').name().compare('a')==0" );
		throwOnFalse( a->getClass()->getField( "b" ).name().compare( "b" ) == 0 ,
			"a->getClass()->getField('b').name().compare('b')==0" );
		throwOnFalse(
			a->getClass()->getField( "counter" ).name().compare( "counter" )
			== 0 ,
			"a->getClass()->getField('counter').name().compare('counter')==0" );
		throwOnFalse(
			a->getClass()->getField( "cool" ).name().compare( "cool" ) == 0 ,
			"a->getClass()->getField('cool').name().compare('cool')==0" );
	}
	catch ( std::exception& e ) {
		std::cout << e.what() << std::endl;
		return false;
	}
	return true;
}
bool testFieldGetDeclaringClass() {
	try {
		Class A_class( nullptr , "A" );
		Class B_class( &A_class , "B" );
		A_class.addStaticField( "x" , INT );
		B_class.addStaticField( "y" , INT );
		A_class.addStaticField( "a" , OBJECT );
		B_class.addStaticField( "b" , OBJECT );
		A_class.addStaticField( "counter" , INT );
		B_class.addStaticField( "cool" , OBJECT );
		Object* b = B_class.newInstance();
		Class::setAccessible( true );
		throwOnFalse(
			b->getClass()->getField( "x" ).getDeclaringClass().compare( "A" )
			== 0 ,
			"b->getClass()->getField('x').getDeclaringClass().compare('A')==0" );
		throwOnFalse(
			b->getClass()->getField( "y" ).getDeclaringClass().compare( "B" )
			== 0 ,
			"b->getClass()->getField('y').getDeclaringClass().compare('B')==0" );
		throwOnFalse(
			b->getClass()->getField( "a" ).getDeclaringClass().compare( "A" )
			== 0 ,
			"b->getClass()->getField('a').getDeclaringClass().compare('A')==0" );
		throwOnFalse(
			b->getClass()->getField( "b" ).getDeclaringClass().compare( "B" )
			== 0 ,
			"b->getClass()->getField('b').getDeclaringClass().compare('B')==0" );
		throwOnFalse(
			b->getClass()->getField( "counter" ).getDeclaringClass().compare(
				"A" ) == 0 ,
			"b->getClass()->getField('counter').getDeclaringClass().compare('A')==0" );
		throwOnFalse(
			b->getClass()->getField( "cool" ).getDeclaringClass().compare( "B" )
			== 0 ,
			"b->getClass()->getField('cool').getDeclaringClass().compare('B')==0" );

	}
	catch ( std::exception& e ) {
		std::cout << e.what() << std::endl;
		return false;
	}
	return true;
}
bool testFieldGetType() {
	try {
		Class A_class( nullptr , "A" );
		Class B_class( &A_class , "B" );

		A_class.addStaticField( "x" , INT );
		B_class.addStaticField( "y" , INT );
		A_class.addStaticField( "a" , OBJECT );
		B_class.addStaticField( "b" , OBJECT );
		A_class.addStaticField( "counter" , INT );
		B_class.addStaticField( "cool" , OBJECT );
		Object* b = B_class.newInstance();
		Class::setAccessible( true );
		throwOnFalse( b->getClass()->getField( "x" ).getType() == INT ,
			"b->getClass()->getField('x').getType()==INT" );
		throwOnFalse( b->getClass()->getField( "y" ).getType() == INT ,
			"b->getClass()->getField('y').getType()==INT" );
		throwOnFalse( b->getClass()->getField( "a" ).getType() == OBJECT ,
			"b->getClass()->getField('a').getType()==OBJECT" );
		throwOnFalse( b->getClass()->getField( "b" ).getType() == OBJECT ,
			"b->getClass()->getField('b').getType()==OBJECT" );
		throwOnFalse( b->getClass()->getField( "counter" ).getType() == INT ,
			"b->getClass()->getField('counter').getType()==INT" );
		throwOnFalse( b->getClass()->getField( "cool" ).getType() == OBJECT ,
			"b->getClass()->getField('cool').getType()==OBJECT" );

	}
	catch ( std::exception& e ) {
		std::cout << e.what() << std::endl;
		return false;
	}
	return true;
}
bool testFieldGetInt() {
	try {
		Class A_class( nullptr , "A" );
		Class B_class( &A_class , "B" );
		Class C_class( nullptr , "C" );
		Object* c = C_class.newInstance();
		A_class.addStaticField( "x" , INT );
		B_class.addStaticField( "y" , INT );
		A_class.addStaticField( "a" , OBJECT );
		B_class.addStaticField( "b" , OBJECT );
		A_class.addStaticField( "counter" , INT );
		B_class.addStaticField( "cool" , OBJECT );
		Object* b = B_class.newInstance();
		Class::setAccessible( true );
		throwOnFalse( b->getClass()->getField( "x" ).getInt( b ) == 0 ,
			"b->getClass()->getField('x').getInt(b)==0" );
		throwOnFalse( b->getClass()->getField( "y" ).getInt( b ) == 0 ,
			"b->getClass()->getField('y').getInt(b)==0" );
		throwOnFalse( b->getClass()->getField( "counter" ).getInt( b ) == 0 ,
			"b->getClass()->getField('counter').getInt(b)==0" );

		try {
			b->getClass()->getField( "a" ).getInt( b );
			return false; //
		}
		catch ( TypeError& e ) {

		}
		catch ( std::exception& e ) {
			std::cout << e.what() << std::endl;
			return false;

		}
		try {
			b->getClass()->getField( "b" ).getInt( b );
			return false; //
		}
		catch ( TypeError& e ) {

		}
		catch ( std::exception& e ) {
			std::cout << e.what() << std::endl;
			return false;

		}
		try {
			b->getClass()->getField( "cool" ).getInt( b );
			return false; //
		}
		catch ( TypeError& e ) {

		}
		catch ( std::exception& e ) {
			std::cout << e.what() << std::endl;
			return false;

		}

		try {
			b->getClass()->getField( "x" ).getInt( c );
			return false; //
		}
		catch ( FieldNotFound& e ) {

		}
		catch ( std::exception& e ) {
			std::cout << e.what() << std::endl;
			return false;

		}
		try {
			b->getClass()->getField( "x" ).getInt( nullptr );
			return false; //
		}
		catch ( FieldNotFound& e ) {

		}
		catch ( std::exception& e ) {
			std::cout << e.what() << std::endl;
			return false;

		}
	}
	catch ( std::exception& e ) {
		std::cout << e.what() << std::endl;
		return false;
	}
	return true;
}
bool testFieldGetObj() {
	try {
		Class A_class( nullptr , "A" );
		Class B_class( &A_class , "B" );
		Class C_class( nullptr , "C" );
		Object* c = C_class.newInstance();
		A_class.addStaticField( "x" , INT );
		B_class.addStaticField( "y" , INT );
		A_class.addStaticField( "a" , OBJECT );
		B_class.addStaticField( "b" , OBJECT );
		A_class.addStaticField( "counter" , INT );
		B_class.addStaticField( "cool" , OBJECT );
		Object* b = B_class.newInstance();
		Class::setAccessible( true );
		throwOnFalse( b->getClass()->getField( "a" ).getObj( b ) == nullptr ,
			"b->getClass()->getField('a').getObj(b) == nullptr" );
		throwOnFalse( b->getClass()->getField( "b" ).getObj( b ) == nullptr ,
			"b->getClass()->getField('b').getObj(b) == nullptr" );
		throwOnFalse( b->getClass()->getField( "cool" ).getObj( b ) == nullptr ,
			"b->getClass()->getField('cool').getObj(b) == nullptr" );

		try {
			b->getClass()->getField( "x" ).getObj( b );
			return false; //
		}
		catch ( TypeError& e ) {

		}
		catch ( std::exception& e ) {
			std::cout << e.what() << std::endl;
			return false;

		}
		try {
			b->getClass()->getField( "y" ).getObj( b );
			return false; //
		}
		catch ( TypeError& e ) {

		}
		catch ( std::exception& e ) {
			std::cout << e.what() << std::endl;
			return false;

		}
		try {
			b->getClass()->getField( "counter" ).getObj( b );
			return false; //
		}
		catch ( TypeError& e ) {

		}
		catch ( std::exception& e ) {
			std::cout << e.what() << std::endl;
			return false;

		}

		try {
			b->getClass()->getField( "a" ).getObj( c );
			return false; //
		}
		catch ( FieldNotFound& e ) {

		}
		catch ( std::exception& e ) {
			std::cout << e.what() << std::endl;
			return false;

		}
		try {
			b->getClass()->getField( "a" ).getObj( nullptr );
			return false; //
		}
		catch ( FieldNotFound& e ) {

		}
		catch ( std::exception& e ) {
			std::cout << e.what() << std::endl;
			return false;

		}

	}
	catch ( std::exception& e ) {
		std::cout << e.what() << std::endl;
		return false;
	}
	return true;
}
bool testFieldSetInt() {
	try {
		Class A_class( nullptr , "A" );
		Class B_class( &A_class , "B" );
		Class C_class( nullptr , "C" );
		Object* c = C_class.newInstance();
		A_class.addStaticField( "x" , INT );
		B_class.addStaticField( "y" , INT );
		A_class.addStaticField( "a" , OBJECT );
		B_class.addStaticField( "b" , OBJECT );
		A_class.addStaticField( "counter" , INT );
		B_class.addStaticField( "cool" , OBJECT );
		Object* b = B_class.newInstance();
		Class::setAccessible( true );

		throwOnFalse( b->getClass()->getField( "x" ).getInt( b ) == 0 ,
			"b->getClass()->getField('x').getInt(b)==0" );
		b->getClass()->getField( "x" ).setInt( b , 1 );
		throwOnFalse( b->getClass()->getField( "x" ).getInt( b ) == 1 ,
			"b->getClass()->getField('x').getInt(b)==1" );

		throwOnFalse( b->getClass()->getField( "y" ).getInt( b ) == 0 ,
			"b->getClass()->getField('y').getInt(b)==0" );
		b->getClass()->getField( "y" ).setInt( b , 2 );
		throwOnFalse( b->getClass()->getField( "y" ).getInt( b ) == 2 ,
			"b->getClass()->getField('y').getInt(b)==2" );

		throwOnFalse( b->getClass()->getField( "counter" ).getInt( b ) == 0 ,
			"b->getClass()->getField('counter').getInt(b)==0" );
		b->getClass()->getField( "counter" ).setInt( b , 3 );
		throwOnFalse( b->getClass()->getField( "counter" ).getInt( b ) == 3 ,
			"b->getClass()->getField('counter').getInt(b)==3" );

		try {
			b->getClass()->getField( "a" ).setInt( b , -1 );
			return false; //
		}
		catch ( TypeError& e ) {

		}
		catch ( std::exception& e ) {
			std::cout << e.what() << std::endl;
			return false;

		}
		try {
			b->getClass()->getField( "b" ).setInt( b , -2 );
			return false; //
		}
		catch ( TypeError& e ) {

		}
		catch ( std::exception& e ) {
			std::cout << e.what() << std::endl;
			return false;

		}
		try {
			b->getClass()->getField( "cool" ).setInt( b , -3 );
			return false; //
		}
		catch ( TypeError& e ) {

		}
		catch ( std::exception& e ) {
			std::cout << e.what() << std::endl;
			return false;

		}

		try {
			b->getClass()->getField( "x" ).setInt( c , -4 );
			return false; //
		}
		catch ( FieldNotFound& e ) {

		}
		catch ( std::exception& e ) {
			std::cout << e.what() << std::endl;
			return false;

		}
		try {
			b->getClass()->getField( "x" ).setInt( nullptr , -5 );
			return false; //
		}
		catch ( FieldNotFound& e ) {

		}
		catch ( std::exception& e ) {
			std::cout << e.what() << std::endl;
			return false;

		}

	}
	catch ( std::exception& e ) {
		std::cout << e.what() << std::endl;
		return false;
	}
	return true;
}
bool testFieldSetObj() {
	try {
		Class A_class( nullptr , "A" );
		Class B_class( &A_class , "B" );
		Class C_class( nullptr , "C" );
		Object* c = C_class.newInstance();
		A_class.addStaticField( "x" , INT );
		B_class.addStaticField( "y" , INT );
		A_class.addStaticField( "a" , OBJECT );
		B_class.addStaticField( "b" , OBJECT );
		A_class.addStaticField( "counter" , INT );
		B_class.addStaticField( "cool" , OBJECT );
		Object* b = B_class.newInstance();
		Class::setAccessible( true );

		throwOnFalse( b->getClass()->getField( "a" ).getObj( b ) == nullptr ,
			"b->getClass()->getField('a').getObj(b) == nullptr" );
		b->getClass()->getField( "a" ).setObj( b , b );
		throwOnFalse( b->getClass()->getField( "a" ).getObj( b ) == b ,
			"b->getClass()->getField('a').getObj(b) == b" );

		throwOnFalse( b->getClass()->getField( "b" ).getObj( b ) == nullptr ,
			"b->getClass()->getField('b').getObj(b) == nullptr" );
		b->getClass()->getField( "b" ).setObj( b , b );
		throwOnFalse( b->getClass()->getField( "b" ).getObj( b ) == b ,
			"b->getClass()->getField('b').getObj(b) == b" );

		throwOnFalse( b->getClass()->getField( "cool" ).getObj( b ) == nullptr ,
			"b->getClass()->getField('cool').getObj(b) == nullptr" );
		b->getClass()->getField( "cool" ).setObj( b , b );
		throwOnFalse( b->getClass()->getField( "cool" ).getObj( b ) == b ,
			"b->getClass()->getField('cool').getObj(b) == b" );

		try {
			b->getClass()->getField( "x" ).setObj( b , b );
			return false; //
		}
		catch ( TypeError& e ) {

		}
		catch ( std::exception& e ) {
			std::cout << e.what() << std::endl;
			return false;

		}
		try {
			b->getClass()->getField( "y" ).setObj( b , b );
			return false; //
		}
		catch ( TypeError& e ) {

		}
		catch ( std::exception& e ) {
			std::cout << e.what() << std::endl;
			return false;

		}
		try {
			b->getClass()->getField( "counter" ).setObj( b , b );
			return false; //
		}
		catch ( TypeError& e ) {

		}
		catch ( std::exception& e ) {
			std::cout << e.what() << std::endl;
			return false;

		}

		try {
			b->getClass()->getField( "a" ).setObj( c , b );
			return false; //
		}
		catch ( FieldNotFound& e ) {

		}
		catch ( std::exception& e ) {
			std::cout << e.what() << std::endl;
			return false;

		}
		try {
			b->getClass()->getField( "a" ).setObj( nullptr , b );
			return false; //
		}
		catch ( FieldNotFound& e ) {

		}
		catch ( std::exception& e ) {
			std::cout << e.what() << std::endl;
			return false;

		}

	}
	catch ( std::exception& e ) {
		std::cout << e.what() << std::endl;
		return false;
	}
	return true;
}

bool testField() {
	return true
		&& printTestSuccessOrFail( testFieldConstructor() ,
			"testFieldConstructor" )
		&& printTestSuccessOrFail( testFieldName() , "testFieldName" )
		&& printTestSuccessOrFail( testFieldGetDeclaringClass() ,
			"testFieldGetDeclaringClass" )
		&& printTestSuccessOrFail( testFieldGetType() , "testFieldGetType" )
		&& printTestSuccessOrFail( testFieldGetInt() , "testFieldGetInt" )
		&& printTestSuccessOrFail( testFieldGetObj() , "testFieldGetObj" )
		&& printTestSuccessOrFail( testFieldSetInt() , "testFieldSetInt" )
		&& printTestSuccessOrFail( testFieldSetObj() , "testFieldSetObj" );

}

/******************************************************************************/
/******************************************************************************/
/*******************************Field section :)*******************************/

/******************************Method section :)*******************************/
/******************************************************************************/
/******************************************************************************/
void setThree( Object* object ) {
	object->getClass()->getMethod( "setThree" );
	object->setInt( "x" , 3 );
}

bool testMethodConstructor() {
	try {
		Class A_class( nullptr , "A" );
		Class B_class( &A_class , "B" );
		A_class.addInstanceField( "x" , INT );
		Object* b = B_class.newInstance();
		A_class.addMethod( "setThree" , setThree );
		Class::setAccessible( true );
	}
	catch ( std::exception& e ) {
		std::cout << e.what() << std::endl;
		return false;
	}
	return true;
}
bool testMethodName() {
	try {
		Class A_class( nullptr , "A" );
		Class B_class( &A_class , "B" );
		A_class.addInstanceField( "x" , INT );
		Object* b = B_class.newInstance();
		A_class.addMethod( "setThree" , setThree );
		Class::setAccessible( true );
		throwOnFalse(
			b->getClass()->getMethod( "setThree" ).name().compare( "setThree" )
			== 0 ,
			"b->getClass()->getMethod('setThree').name().compare('setThree')==0" );

	}
	catch ( std::exception& e ) {
		std::cout << e.what() << std::endl;
		return false;
	}
	return true;
}

bool testMethodGetDeclaringClass() {
	try {
		Class A_class( nullptr , "A" );
		Class B_class( &A_class , "B" );
		A_class.addInstanceField( "x" , INT );
		Object* b = B_class.newInstance();
		A_class.addMethod( "setFree" , setThree );
		Class::setAccessible( true );
		throwOnFalse(
			b->getClass()->getMethod( "setFree" ).getDeclaringClass().compare(
				"A" ) == 0 ,
			"b->getClass()->getMethod('setFree').getDeclaringClass().compare('A')== 0" );

	}
	catch ( std::exception& e ) {
		std::cout << e.what() << std::endl;
		return false;
	}
	return true;
}

bool testMethodInvoke() {
	try {
		Class A_class( nullptr , "A" );
		Class B_class( &A_class , "B" );
		Class C_class( nullptr , "C" );

		A_class.addInstanceField( "x" , INT );
		Object* b = B_class.newInstance();
		Object* c = C_class.newInstance();
		A_class.addMethod( "setThree" , setThree );
		Class::setAccessible( true );
		throwOnFalse( b->getInt( "x" ) == 0 , "b->getInt('x')==0" );
		b->getClass()->getMethod( "setThree" ).invoke( b );
		try {
			b->getClass()->getMethod( "setThree" ).invoke( b );
		}
		catch ( MethodNotFound& e ) {
			std::cout << e.what() << std::endl;
			return false;
		}
		catch ( std::exception& e ) {
			std::cout << e.what() << std::endl;
			return false;

		}
		throwOnFalse( b->getInt( "x" ) == 3 , "b->getInt('x')==3" );

		try {
			b->getClass()->getMethod( "setThree" ).invoke( c );
			return false; //
		}
		catch ( MethodNotFound& e ) {

		}
		catch ( std::exception& e ) {
			std::cout << e.what() << std::endl;
			return false;

		}

		try {
			b->getClass()->getMethod( "setThree" ).invoke( nullptr );
			return false; //
		}
		catch ( MethodNotFound& e ) {

		}
		catch ( std::exception& e ) {
			std::cout << e.what() << std::endl;
			return false;

		}

	}
	catch ( std::exception& e ) {
		std::cout << e.what() << std::endl;
		return false;
	}
	return true;
}
bool testMethod() {
	return true
		&& printTestSuccessOrFail( testMethodConstructor() ,
			"testMethodConstructor" )
		&& printTestSuccessOrFail( testMethodName() , "testMethodName" )
		&& printTestSuccessOrFail( testMethodGetDeclaringClass() ,
			"testMethodGetDeclaringClass" )
		&& printTestSuccessOrFail( testMethodInvoke() , "testMethodInvoke" );

}
/******************************************************************************/
/******************************************************************************/
/******************************Method section :)*******************************/

/******************************Object section :)*******************************/
/******************************************************************************/
/******************************************************************************/
bool testObjectConstructor() {
	try {
		Class A_class( nullptr , "A" );
		Class B_class( &A_class , "B" );
		A_class.addInstanceField( "x" , INT );
		Object* b = B_class.newInstance();

	}
	catch ( std::exception& e ) {
		std::cout << e.what() << std::endl;
		return false;
	}
	return true;
}
bool testObjectGetClass() {
	try {
		Class A_class( nullptr , "A" );
		Class B_class( &A_class , "B" );
		A_class.addInstanceField( "x" , INT );
		Object* b = B_class.newInstance();
		Class::setAccessible( true );
		throwOnFalse( b->getClass()->name().compare( "B" ) == 0 ,
			"b->getClass()->name().compare('B')==0" );
	}
	catch ( std::exception& e ) {
		std::cout << e.what() << std::endl;
		return false;
	}
	return true;
}
bool testObjectGetInt() {
	try {
		Class A_class( nullptr , "A" );
		Class B_class( &A_class , "B" );
		Class C_class( nullptr , "C" );
		Object* c = C_class.newInstance();
		Object* b_does_not_know_x = B_class.newInstance(); // Defined before add
		A_class.addInstanceField( "x" , INT );
		Object* b = B_class.newInstance();

		Class::setAccessible( true );
		throwOnFalse( b->getInt( "x" ) == 0 , "b->getInt('x') == 0" );

		try {
			b->getObj( "x" );
			return false; //
		}
		catch ( TypeError& e ) {

		}
		catch ( std::exception& e ) {
			std::cout << e.what() << std::endl;
			return false;

		}
		try {
			c->getInt( "x" );
			return false; //
		}
		catch ( FieldNotFound& e ) {

		}
		catch ( std::exception& e ) {
			std::cout << e.what() << std::endl;
			return false;

		}
		try {
			b_does_not_know_x->getInt( "x" ); // Doesn't know even though inherits
											  // from A
											  // Joined party late :(
			return false; //
		}
		catch ( FieldNotFound& e ) {

		}
		catch ( std::exception& e ) {
			std::cout << e.what() << std::endl;
			return false;

		}

	}
	catch ( std::exception& e ) {
		std::cout << e.what() << std::endl;
		return false;
	}
	return true;
}
bool testObjectGetObj() {
	try {
		Class A_class( nullptr , "A" );
		Class B_class( &A_class , "B" );
		Class C_class( nullptr , "C" );
		Object* c = C_class.newInstance();
		Object* b_does_not_know_x = B_class.newInstance(); // Defined before add
		A_class.addInstanceField( "x" , OBJECT );
		Object* b = B_class.newInstance();

		Class::setAccessible( true );
		throwOnFalse( b->getObj( "x" ) == nullptr , "b->getObj('x') == nullptr" );

		try {
			b->getInt( "x" );
			return false; //
		}
		catch ( TypeError& e ) {

		}
		catch ( std::exception& e ) {
			std::cout << e.what() << std::endl;
			return false;

		}
		try {
			c->getObj( "x" );
			return false; //
		}
		catch ( FieldNotFound& e ) {

		}
		catch ( std::exception& e ) {
			std::cout << e.what() << std::endl;
			return false;

		}
		try {
			b_does_not_know_x->getObj( "x" ); // Doesn't know even though inherits
											  // from A
											  // Joined party late :(
			return false; //
		}
		catch ( FieldNotFound& e ) {

		}
		catch ( std::exception& e ) {
			std::cout << e.what() << std::endl;
			return false;

		}

	}
	catch ( std::exception& e ) {
		std::cout << e.what() << std::endl;
		return false;
	}
	return true;
}
bool testObjectSetInt() {
	try {
		Class A_class( nullptr , "A" );
		Class B_class( &A_class , "B" );
		Class C_class( nullptr , "C" );
		Object* c = C_class.newInstance();
		Object* b_does_not_know_x = B_class.newInstance(); // Defined before add
		A_class.addInstanceField( "x" , INT );
		Object* b = B_class.newInstance();

		Class::setAccessible( true );
		throwOnFalse( b->getInt( "x" ) == 0 , "b->getInt('x') == 0" );
		b->setInt( "x" , 42 );
		throwOnFalse( b->getInt( "x" ) == 42 , "b->getInt('x') == 42" );

		try {
			b->setObj( "x" , b );
			return false; //
		}
		catch ( TypeError& e ) {

		}
		catch ( std::exception& e ) {
			std::cout << e.what() << std::endl;
			return false;

		}
		try {
			c->setInt( "x" , -42 );
			return false; //
		}
		catch ( FieldNotFound& e ) {

		}
		catch ( std::exception& e ) {
			std::cout << e.what() << std::endl;
			return false;

		}
		try {
			b_does_not_know_x->setInt( "x" , -666 ); // Doesn't know even though inherits
													 // from A
													 // Joined party late :(
			return false; //
		}
		catch ( FieldNotFound& e ) {

		}
		catch ( std::exception& e ) {
			std::cout << e.what() << std::endl;
			return false;

		}

	}
	catch ( std::exception& e ) {
		std::cout << e.what() << std::endl;
		return false;
	}
	return true;
}
bool testObjectSetObj() {
	try {
		Class A_class( nullptr , "A" );
		Class B_class( &A_class , "B" );
		Class C_class( nullptr , "C" );
		Object* c = C_class.newInstance();
		Object* b_does_not_know_x = B_class.newInstance(); // Defined before add
		A_class.addInstanceField( "x" , OBJECT );
		Object* b = B_class.newInstance();

		Class::setAccessible( true );
		throwOnFalse( b->getObj( "x" ) == nullptr , "b->getObj('x') == nullptr" );
		b->setObj( "x" , b );
		throwOnFalse( b->getObj( "x" ) == b , "b->getObj('x') == b" );

		try {
			b->setInt( "x" , -42 );
			return false; //
		}
		catch ( TypeError& e ) {

		}
		catch ( std::exception& e ) {
			std::cout << e.what() << std::endl;
			return false;

		}
		try {
			c->setObj( "x" , b );
			return false; //
		}
		catch ( FieldNotFound& e ) {

		}
		catch ( std::exception& e ) {
			std::cout << e.what() << std::endl;
			return false;

		}
		try {
			b_does_not_know_x->setObj( "x" , b ); // Doesn't know even though inherits
												  // from A
												  // Joined party late :(
			return false; //
		}
		catch ( FieldNotFound& e ) {

		}
		catch ( std::exception& e ) {
			std::cout << e.what() << std::endl;
			return false;

		}

	}
	catch ( std::exception& e ) {
		std::cout << e.what() << std::endl;
		return false;
	}
	return true;
}
bool testObjectInvokeMethod() {
	try {
		Class A_class( nullptr , "A" );
		Class B_class( &A_class , "B" );
		Class C_class( nullptr , "C" );

		Object* b_does_not_know_x = B_class.newInstance();
		A_class.addInstanceField( "x" , INT );
		Object* b = B_class.newInstance();
		Object* c = C_class.newInstance();
		A_class.addMethod( "setThree" , setThree );
		Class::setAccessible( true );
		throwOnFalse( b->getInt( "x" ) == 0 , "b->getInt('x')==0" );
		try {
			b->invokeMethod( "setThree" );
		}
		catch ( MethodNotFound& e ) {
			std::cout << e.what() << std::endl;
			return false;
		}
		catch ( std::exception& e ) {
			std::cout << e.what() << std::endl;
			return false;

		}
		throwOnFalse( b->getInt( "x" ) == 3 , "b->getInt('x')==3" );

		try {
			b->invokeMethod( "setFree" ); // Free is not Three, GRAMMAR ALERT :(
			return false; //
		}
		catch ( MethodNotFound& e ) {

		}
		catch ( std::exception& e ) {
			std::cout << e.what() << std::endl;
			return false;

		}
		try {
			c->invokeMethod( "setThree" );
			return false; //
		}
		catch ( MethodNotFound& e ) {

		}
		catch ( std::exception& e ) {
			std::cout << e.what() << std::endl;
			return false;

		}
		try {
			b_does_not_know_x->invokeMethod( "setThree" );
			return false; //
		}
		catch ( FieldNotFound& e ) { // On purpose Field and not Method :)

		}
		catch ( std::exception& e ) {
			std::cout << e.what() << std::endl;
			return false;

		}

	}
	catch ( std::exception& e ) {
		std::cout << e.what() << std::endl;
		return false;
	}
	return true;
}
bool testObjectIsKindOf() {
	try {
		Class A_class( nullptr , "A" );
		Class B_class( &A_class , "B" );
		Class C_class( nullptr , "C" );
		Class D_class( nullptr , "D" );
		Class E_class( &A_class , "E" );
		Class F_class( &B_class , "F" );
		Class G_class( &F_class , "G" );

		Object* a = A_class.newInstance();
		Object* b = B_class.newInstance();
		Object* c = C_class.newInstance();
		Object* d = D_class.newInstance();
		Object* e = E_class.newInstance();
		Object* f = F_class.newInstance();
		Object* g = G_class.newInstance();

		throwOnFalse( a->isKindOf( "A" ) == true , "a->isKindOf('A')==true" );
		throwOnFalse( a->isKindOf( "B" ) == false , "a->isKindOf('B')==false" );
		throwOnFalse( a->isKindOf( "C" ) == false , "a->isKindOf('C')==false" );
		throwOnFalse( a->isKindOf( "D" ) == false , "a->isKindOf('D')==false" );
		throwOnFalse( a->isKindOf( "E" ) == false , "a->isKindOf('E')==false" );
		throwOnFalse( a->isKindOf( "F" ) == false , "a->isKindOf('F')==false" );
		throwOnFalse( a->isKindOf( "G" ) == false , "a->isKindOf('G')==false" );

		throwOnFalse( b->isKindOf( "A" ) == true , "b->isKindOf('A')==true" );
		throwOnFalse( b->isKindOf( "B" ) == true , "b->isKindOf('B')==true" );
		throwOnFalse( b->isKindOf( "C" ) == false , "b->isKindOf('C')==false" );
		throwOnFalse( b->isKindOf( "D" ) == false , "b->isKindOf('D')==false" );
		throwOnFalse( b->isKindOf( "E" ) == false , "b->isKindOf('E')==false" );
		throwOnFalse( b->isKindOf( "F" ) == false , "b->isKindOf('F')==false" );
		throwOnFalse( b->isKindOf( "G" ) == false , "b->isKindOf('G')==false" );

		throwOnFalse( c->isKindOf( "A" ) == false , "c->isKindOf('A')==false" );
		throwOnFalse( c->isKindOf( "B" ) == false , "c->isKindOf('B')==false" );
		throwOnFalse( c->isKindOf( "C" ) == true , "c->isKindOf('C')==true" );
		throwOnFalse( c->isKindOf( "D" ) == false , "c->isKindOf('D')==false" );
		throwOnFalse( c->isKindOf( "E" ) == false , "c->isKindOf('E')==false" );
		throwOnFalse( c->isKindOf( "F" ) == false , "c->isKindOf('F')==false" );
		throwOnFalse( c->isKindOf( "G" ) == false , "c->isKindOf('G')==false" );

		throwOnFalse( d->isKindOf( "A" ) == false , "d->isKindOf('A')==false" );
		throwOnFalse( d->isKindOf( "B" ) == false , "d->isKindOf('B')==false" );
		throwOnFalse( d->isKindOf( "C" ) == false , "d->isKindOf('C')==false" );
		throwOnFalse( d->isKindOf( "D" ) == true , "d->isKindOf('D')==true" );
		throwOnFalse( d->isKindOf( "E" ) == false , "d->isKindOf('E')==false" );
		throwOnFalse( d->isKindOf( "F" ) == false , "d->isKindOf('F')==false" );
		throwOnFalse( d->isKindOf( "G" ) == false , "d->isKindOf('G')==false" );

		throwOnFalse( e->isKindOf( "A" ) == true , "e->isKindOf('A')==true" );
		throwOnFalse( e->isKindOf( "B" ) == false , "e->isKindOf('B')==false" );
		throwOnFalse( e->isKindOf( "C" ) == false , "e->isKindOf('C')==false" );
		throwOnFalse( e->isKindOf( "D" ) == false , "e->isKindOf('D')==false" );
		throwOnFalse( e->isKindOf( "E" ) == true , "e->isKindOf('E')==true" );
		throwOnFalse( e->isKindOf( "F" ) == false , "e->isKindOf('F')==false" );
		throwOnFalse( e->isKindOf( "G" ) == false , "e->isKindOf('G')==false" );

		throwOnFalse( f->isKindOf( "A" ) == true , "f->isKindOf('A')==true" );
		throwOnFalse( f->isKindOf( "B" ) == true , "f->isKindOf('B')==true" );
		throwOnFalse( f->isKindOf( "C" ) == false , "f->isKindOf('C')==false" );
		throwOnFalse( f->isKindOf( "D" ) == false , "f->isKindOf('D')==false" );
		throwOnFalse( f->isKindOf( "E" ) == false , "f->isKindOf('E')==false" );
		throwOnFalse( f->isKindOf( "F" ) == true , "f->isKindOf('F')==true" );
		throwOnFalse( f->isKindOf( "G" ) == false , "f->isKindOf('G')==false" );

		throwOnFalse( g->isKindOf( "A" ) == true , "g->isKindOf('A')==true" );
		throwOnFalse( g->isKindOf( "B" ) == true , "g->isKindOf('B')==true" );
		throwOnFalse( g->isKindOf( "C" ) == false , "g->isKindOf('C')==false" );
		throwOnFalse( g->isKindOf( "D" ) == false , "g->isKindOf('D')==false" );
		throwOnFalse( g->isKindOf( "E" ) == false , "g->isKindOf('E')==false" );
		throwOnFalse( g->isKindOf( "F" ) == true , "g->isKindOf('F')==true" );
		throwOnFalse( g->isKindOf( "G" ) == true , "g->isKindOf('G')==true" );

		throwOnFalse( g->isKindOf( "H" ) == false , "g->isKindOf('H')==false" ); // No such class :)

	}
	catch ( std::exception& e ) {
		std::cout << e.what() << std::endl;
		return false;
	}
	return true;
}
bool testObjectIsInstanceOf() {
	try {
		Class A_class( nullptr , "A" );
		Class B_class( &A_class , "B" );
		Class C_class( nullptr , "C" );
		Class D_class( nullptr , "D" );
		Class E_class( &A_class , "E" );
		Class F_class( &B_class , "F" );
		Class G_class( &F_class , "G" );

		Object* a = A_class.newInstance();
		Object* b = B_class.newInstance();
		Object* c = C_class.newInstance();
		Object* d = D_class.newInstance();
		Object* e = E_class.newInstance();
		Object* f = F_class.newInstance();
		Object* g = G_class.newInstance();

		throwOnFalse( a->isInstanceOf( "A" ) == true ,
			"a->isInstanceOf('A')==true" );
		throwOnFalse( a->isInstanceOf( "B" ) == false ,
			"a->isInstanceOf('B')==false" );
		throwOnFalse( a->isInstanceOf( "C" ) == false ,
			"a->isInstanceOf('C')==false" );
		throwOnFalse( a->isInstanceOf( "D" ) == false ,
			"a->isInstanceOf('D')==false" );
		throwOnFalse( a->isInstanceOf( "E" ) == false ,
			"a->isInstanceOf('E')==false" );
		throwOnFalse( a->isInstanceOf( "F" ) == false ,
			"a->isInstanceOf('F')==false" );
		throwOnFalse( a->isInstanceOf( "G" ) == false ,
			"a->isInstanceOf('G')==false" );

		throwOnFalse( b->isInstanceOf( "A" ) == false ,
			"b->isInstanceOf('A')==false" );
		throwOnFalse( b->isInstanceOf( "B" ) == true ,
			"b->isInstanceOf('B')==true" );
		throwOnFalse( b->isInstanceOf( "C" ) == false ,
			"b->isInstanceOf('C')==false" );
		throwOnFalse( b->isInstanceOf( "D" ) == false ,
			"b->isInstanceOf('D')==false" );
		throwOnFalse( b->isInstanceOf( "E" ) == false ,
			"b->isInstanceOf('E')==false" );
		throwOnFalse( b->isInstanceOf( "F" ) == false ,
			"b->isInstanceOf('F')==false" );
		throwOnFalse( b->isInstanceOf( "G" ) == false ,
			"b->isInstanceOf('G')==false" );

		throwOnFalse( c->isInstanceOf( "A" ) == false ,
			"c->isInstanceOf('A')==false" );
		throwOnFalse( c->isInstanceOf( "B" ) == false ,
			"c->isInstanceOf('B')==false" );
		throwOnFalse( c->isInstanceOf( "C" ) == true ,
			"c->isInstanceOf('C')==true" );
		throwOnFalse( c->isInstanceOf( "D" ) == false ,
			"c->isInstanceOf('D')==false" );
		throwOnFalse( c->isInstanceOf( "E" ) == false ,
			"c->isInstanceOf('E')==false" );
		throwOnFalse( c->isInstanceOf( "F" ) == false ,
			"c->isInstanceOf('F')==false" );
		throwOnFalse( c->isInstanceOf( "G" ) == false ,
			"c->isInstanceOf('G')==false" );

		throwOnFalse( d->isInstanceOf( "A" ) == false ,
			"d->isInstanceOf('A')==false" );
		throwOnFalse( d->isInstanceOf( "B" ) == false ,
			"d->isInstanceOf('B')==false" );
		throwOnFalse( d->isInstanceOf( "C" ) == false ,
			"d->isInstanceOf('C')==false" );
		throwOnFalse( d->isInstanceOf( "D" ) == true ,
			"d->isInstanceOf('D')==true" );
		throwOnFalse( d->isInstanceOf( "E" ) == false ,
			"d->isInstanceOf('E')==false" );
		throwOnFalse( d->isInstanceOf( "F" ) == false ,
			"d->isInstanceOf('F')==false" );
		throwOnFalse( d->isInstanceOf( "G" ) == false ,
			"d->isInstanceOf('G')==false" );

		throwOnFalse( e->isInstanceOf( "A" ) == false ,
			"e->isInstanceOf('A')==false" );
		throwOnFalse( e->isInstanceOf( "B" ) == false ,
			"e->isInstanceOf('B')==false" );
		throwOnFalse( e->isInstanceOf( "C" ) == false ,
			"e->isInstanceOf('C')==false" );
		throwOnFalse( e->isInstanceOf( "D" ) == false ,
			"e->isInstanceOf('D')==false" );
		throwOnFalse( e->isInstanceOf( "E" ) == true ,
			"e->isInstanceOf('E')==true" );
		throwOnFalse( e->isInstanceOf( "F" ) == false ,
			"e->isInstanceOf('F')==false" );
		throwOnFalse( e->isInstanceOf( "G" ) == false ,
			"e->isInstanceOf('G')==false" );

		throwOnFalse( f->isInstanceOf( "A" ) == false ,
			"f->isInstanceOf('A')==false" );
		throwOnFalse( f->isInstanceOf( "B" ) == false ,
			"f->isInstanceOf('B')==false" );
		throwOnFalse( f->isInstanceOf( "C" ) == false ,
			"f->isInstanceOf('C')==false" );
		throwOnFalse( f->isInstanceOf( "D" ) == false ,
			"f->isInstanceOf('D')==false" );
		throwOnFalse( f->isInstanceOf( "E" ) == false ,
			"f->isInstanceOf('E')==false" );
		throwOnFalse( f->isInstanceOf( "F" ) == true ,
			"f->isInstanceOf('F')==true" );
		throwOnFalse( f->isInstanceOf( "G" ) == false ,
			"f->isInstanceOf('G')==false" );

		throwOnFalse( g->isInstanceOf( "A" ) == false ,
			"g->isInstanceOf('A')==false" );
		throwOnFalse( g->isInstanceOf( "B" ) == false ,
			"g->isInstanceOf('B')==false" );
		throwOnFalse( g->isInstanceOf( "C" ) == false ,
			"g->isInstanceOf('C')==false" );
		throwOnFalse( g->isInstanceOf( "D" ) == false ,
			"g->isInstanceOf('D')==false" );
		throwOnFalse( g->isInstanceOf( "E" ) == false ,
			"g->isInstanceOf('E')==false" );
		throwOnFalse( g->isInstanceOf( "F" ) == false ,
			"g->isInstanceOf('F')==true" );
		throwOnFalse( g->isInstanceOf( "G" ) == true ,
			"g->isInstanceOf('G')==true" );

		throwOnFalse( g->isInstanceOf( "H" ) == false ,
			"g->isInstanceOf('H')==false" ); // No such class :)

	}
	catch ( std::exception& e ) {
		std::cout << e.what() << std::endl;
		return false;
	}
	return true;
}

bool testObject() {
	return true

		&& printTestSuccessOrFail( testObjectConstructor() , "testObjectConstructor" )
		&& printTestSuccessOrFail( testObjectGetClass() ,
			"testObjectGetClass" )
		&& printTestSuccessOrFail( testObjectGetInt() , "testObjectGetInt" )
		&& printTestSuccessOrFail( testObjectGetObj() , "testObjectGetObj" )
		&& printTestSuccessOrFail( testObjectSetInt() , "testObjectSetInt" )
		&& printTestSuccessOrFail( testObjectSetObj() , "testObjectSetObj" )
		&& printTestSuccessOrFail( testObjectInvokeMethod() ,
			"testObjectInvokeMethod" )
		&& printTestSuccessOrFail( testObjectIsInstanceOf() ,
			"testObjectIsInstanceOf" )
		&& printTestSuccessOrFail( testObjectIsKindOf() ,
			"testObjectIsKindOf" );
}
/******************************************************************************/
/******************************************************************************/
/******************************Object section :)*******************************/

/******************************Class section :)********************************/
/******************************************************************************/
/******************************************************************************/

/******************************************************************************/
/******************************************************************************/
/******************************Class section :)********************************/
bool testClassConstructor() {
	try {
		Class A_class( nullptr , "A" );
		Class B_class( &A_class , "B" );
		Class C_class( nullptr , "C" );
		Class D_class( nullptr , "D" );
		Class E_class( &A_class , "E" );
		Class F_class( &B_class , "F" );
		Class G_class( &F_class , "G" );
		Class H_class( nullptr , "H" );
		Class I_class( &A_class , "I" );
		Class J_class( nullptr , "J" );
		Class K_class( nullptr , "K" );
		Class L_class( &A_class , "L" );
		Class M_class( &B_class , "M" );
		Class N_class( &F_class , "N" );
		Class O_class( &A_class , "O" );
		Class P_class( &N_class , "P" );
		Class Q_class( &P_class , "Q" );
		Class R_class( &Q_class , "R" );
		Class S_class( &R_class , "S" );
		Class T_class( &S_class , "T" );
		Class U_class( &T_class , "U" );
		Class V_class( &U_class , "V" );
		Class W_class( &V_class , "W" );
		Class X_class( &W_class , "X" );
		Class Y_class( &X_class , "Y" );
		Class Z_class( &Y_class , "Z" );

	}
	catch ( std::exception& e ) {
		std::cout << e.what() << std::endl;
		return false;
	}
	return true;
}
bool testClassName() {
	try {
		Class A_class( nullptr , "A" );
		Class B_class( &A_class , "B" );
		Class C_class( nullptr , "C" );
		Class D_class( nullptr , "D" );
		Class E_class( &A_class , "E" );
		Class F_class( &B_class , "F" );
		Class G_class( &F_class , "G" );
		Class H_class( nullptr , "H" );
		Class I_class( &A_class , "I" );
		Class J_class( nullptr , "J" );
		Class K_class( nullptr , "K" );
		Class L_class( &A_class , "L" );
		Class M_class( &B_class , "M" );
		Class N_class( &F_class , "N" );
		Class O_class( &A_class , "O" );
		Class P_class( &N_class , "P" );
		Class Q_class( &P_class , "Q" );
		Class R_class( &Q_class , "R" );
		Class S_class( &R_class , "S" );
		Class T_class( &S_class , "T" );
		Class U_class( &T_class , "U" );
		Class V_class( &U_class , "V" );
		Class W_class( &V_class , "W" );
		Class X_class( &W_class , "X" );
		Class Y_class( &X_class , "Y" );
		Class Z_class( &Y_class , "Z" );

		throwOnFalse( A_class.name().compare( "A" ) == 0 ,
			"A_class.name().compare('A')==0" );
		throwOnFalse( B_class.name().compare( "B" ) == 0 ,
			"B_class.name().compare('B')==0" );
		throwOnFalse( C_class.name().compare( "C" ) == 0 ,
			"C_class.name().compare('C')==0" );
		throwOnFalse( D_class.name().compare( "D" ) == 0 ,
			"D_class.name().compare('D')==0" );
		throwOnFalse( E_class.name().compare( "E" ) == 0 ,
			"E_class.name().compare('E')==0" );
		throwOnFalse( F_class.name().compare( "F" ) == 0 ,
			"F_class.name().compare('F')==0" );
		throwOnFalse( G_class.name().compare( "G" ) == 0 ,
			"G_class.name().compare('G')==0" );
		throwOnFalse( H_class.name().compare( "H" ) == 0 ,
			"H_class.name().compare('H')==0" );
		throwOnFalse( I_class.name().compare( "I" ) == 0 ,
			"I_class.name().compare('I')==0" );
		throwOnFalse( J_class.name().compare( "J" ) == 0 ,
			"J_class.name().compare('J')==0" );
		throwOnFalse( K_class.name().compare( "K" ) == 0 ,
			"K_class.name().compare('K')==0" );
		throwOnFalse( L_class.name().compare( "L" ) == 0 ,
			"L_class.name().compare('L')==0" );
		throwOnFalse( M_class.name().compare( "M" ) == 0 ,
			"M_class.name().compare('M')==0" );
		throwOnFalse( Q_class.name().compare( "Q" ) == 0 ,
			"N_class.name().compare('N')==0" );
		throwOnFalse( R_class.name().compare( "R" ) == 0 ,
			"O_class.name().compare('O')==0" );
		throwOnFalse( S_class.name().compare( "S" ) == 0 ,
			"P_class.name().compare('P')==0" );
		throwOnFalse( N_class.name().compare( "N" ) == 0 ,
			"Q_class.name().compare('Q')==0" );
		throwOnFalse( O_class.name().compare( "O" ) == 0 ,
			"R_class.name().compare('R')==0" );
		throwOnFalse( P_class.name().compare( "P" ) == 0 ,
			"S_class.name().compare('S')==0" );
		throwOnFalse( T_class.name().compare( "T" ) == 0 ,
			"T_class.name().compare('T')==0" );
		throwOnFalse( U_class.name().compare( "U" ) == 0 ,
			"U_class.name().compare('U')==0" );
		throwOnFalse( V_class.name().compare( "V" ) == 0 ,
			"V_class.name().compare('V')==0" );
		throwOnFalse( W_class.name().compare( "W" ) == 0 ,
			"W_class.name().compare('W')==0" );
		throwOnFalse( X_class.name().compare( "X" ) == 0 ,
			"X_class.name().compare('X')==0" );
		throwOnFalse( Y_class.name().compare( "Y" ) == 0 ,
			"Y_class.name().compare('Y')==0" );
		throwOnFalse( Z_class.name().compare( "Z" ) == 0 ,
			"Z_class.name().compare('Z')==0" );

	}
	catch ( std::exception& e ) {
		std::cout << e.what() << std::endl;
		return false;
	}
	return true;
}
bool testClassNewInstance() {
	try {
		Class A_class( nullptr , "A" );
		Class B_class( &A_class , "B" );
		Class C_class( nullptr , "C" );
		Class D_class( nullptr , "D" );
		Class E_class( &A_class , "E" );
		Class F_class( &B_class , "F" );
		Class G_class( &F_class , "G" );
		Class H_class( nullptr , "H" );
		Class I_class( &A_class , "I" );
		Class J_class( nullptr , "J" );
		Class K_class( nullptr , "K" );
		Class L_class( &A_class , "L" );
		Class M_class( &B_class , "M" );
		Class N_class( &F_class , "N" );
		Class O_class( &A_class , "O" );
		Class P_class( &N_class , "P" );
		Class Q_class( &P_class , "Q" );
		Class R_class( &Q_class , "R" );
		Class S_class( &R_class , "S" );
		Class T_class( &S_class , "T" );
		Class U_class( &T_class , "U" );
		Class V_class( &U_class , "V" );
		Class W_class( &V_class , "W" );
		Class X_class( &W_class , "X" );
		Class Y_class( &X_class , "Y" );
		Class Z_class( &Y_class , "Z" );

		Object* a = A_class.newInstance();
		Object* b = B_class.newInstance();
		Object* c = C_class.newInstance();
		Object* d = D_class.newInstance();
		Object* e = E_class.newInstance();
		Object* f = F_class.newInstance();
		Object* g = G_class.newInstance();
		Object* h = H_class.newInstance();
		Object* i = I_class.newInstance();
		Object* j = J_class.newInstance();
		Object* k = K_class.newInstance();
		Object* l = L_class.newInstance();
		Object* m = M_class.newInstance();
		Object* n = N_class.newInstance();
		Object* o = O_class.newInstance();
		Object* p = P_class.newInstance();
		Object* q = Q_class.newInstance();
		Object* r = R_class.newInstance();
		Object* s = S_class.newInstance();
		Object* t = T_class.newInstance();
		Object* u = U_class.newInstance();
		Object* v = V_class.newInstance();
		Object* w = W_class.newInstance();
		Object* x = X_class.newInstance();
		Object* y = Y_class.newInstance();
		Object* z = Z_class.newInstance();

		throwOnFalse( a->isInstanceOf( "A" ) , "a->isInstanceOf('A')" );
		throwOnFalse( b->isInstanceOf( "B" ) , "b->isInstanceOf('B')" );
		throwOnFalse( c->isInstanceOf( "C" ) , "c->isInstanceOf('C')" );
		throwOnFalse( d->isInstanceOf( "D" ) , "d->isInstanceOf('D')" );
		throwOnFalse( e->isInstanceOf( "E" ) , "e->isInstanceOf('E')" );
		throwOnFalse( f->isInstanceOf( "F" ) , "f->isInstanceOf('F')" );
		throwOnFalse( g->isInstanceOf( "G" ) , "g->isInstanceOf('G')" );
		throwOnFalse( h->isInstanceOf( "H" ) , "h->isInstanceOf('H')" );
		throwOnFalse( i->isInstanceOf( "I" ) , "i->isInstanceOf('I')" );
		throwOnFalse( j->isInstanceOf( "J" ) , "j->isInstanceOf('J')" );
		throwOnFalse( k->isInstanceOf( "K" ) , "k->isInstanceOf('K')" );
		throwOnFalse( l->isInstanceOf( "L" ) , "l->isInstanceOf('L')" );
		throwOnFalse( m->isInstanceOf( "M" ) , "m->isInstanceOf('M')" );
		throwOnFalse( n->isInstanceOf( "N" ) , "n->isInstanceOf('N')" );
		throwOnFalse( o->isInstanceOf( "O" ) , "o->isInstanceOf('O')" );
		throwOnFalse( p->isInstanceOf( "P" ) , "p->isInstanceOf('P')" );
		throwOnFalse( q->isInstanceOf( "Q" ) , "q->isInstanceOf('Q')" );
		throwOnFalse( r->isInstanceOf( "R" ) , "r->isInstanceOf('R')" );
		throwOnFalse( s->isInstanceOf( "S" ) , "s->isInstanceOf('S')" );
		throwOnFalse( t->isInstanceOf( "T" ) , "t->isInstanceOf('T')" );
		throwOnFalse( u->isInstanceOf( "U" ) , "u->isInstanceOf('U')" );
		throwOnFalse( v->isInstanceOf( "V" ) , "v->isInstanceOf('V')" );
		throwOnFalse( w->isInstanceOf( "W" ) , "w->isInstanceOf('W')" );
		throwOnFalse( x->isInstanceOf( "X" ) , "x->isInstanceOf('X')" );
		throwOnFalse( y->isInstanceOf( "Y" ) , "y->isInstanceOf('Y')" );
		throwOnFalse( z->isInstanceOf( "Z" ) , "z->isInstanceOf('Z')" );

		throwOnFalse( a->isKindOf( "B" ) == false , "a->isKindOf('B')==false" );
		throwOnFalse( b->isKindOf( "B" ) == true , "b->isKindOf('B')==true" );
		throwOnFalse( c->isKindOf( "B" ) == false , "c->isKindOf('B')==false" );
		throwOnFalse( d->isKindOf( "B" ) == false , "d->isKindOf('B')==false" );
		throwOnFalse( e->isKindOf( "B" ) == false , "e->isKindOf('B')==false" );
		throwOnFalse( f->isKindOf( "B" ) == true , "f->isKindOf('B')==true" );
		throwOnFalse( g->isKindOf( "B" ) == true , "g->isKindOf('B')==false" );
		throwOnFalse( h->isKindOf( "B" ) == false , "h->isKindOf('B')==false" );
		throwOnFalse( i->isKindOf( "B" ) == false , "i->isKindOf('B')==false" );
		throwOnFalse( j->isKindOf( "B" ) == false , "j->isKindOf('B')==false" );
		throwOnFalse( k->isKindOf( "B" ) == false , "k->isKindOf('B')==false" );
		throwOnFalse( l->isKindOf( "B" ) == false , "l->isKindOf('B')==false" );
		throwOnFalse( m->isKindOf( "B" ) == true , "m->isKindOf('B')==true" );
		throwOnFalse( n->isKindOf( "B" ) == true , "n->isKindOf('B')==true" );
		throwOnFalse( o->isKindOf( "B" ) == false , "o->isKindOf('B')==false" );
		throwOnFalse( p->isKindOf( "B" ) == true , "p->isKindOf('B')==true" );
		throwOnFalse( q->isKindOf( "B" ) == true , "q->isKindOf('B')==true" );
		throwOnFalse( r->isKindOf( "B" ) == true , "r->isKindOf('B')==true" );
		throwOnFalse( s->isKindOf( "B" ) == true , "s->isKindOf('B')==true" );
		throwOnFalse( t->isKindOf( "B" ) == true , "t->isKindOf('B')==true" );
		throwOnFalse( u->isKindOf( "B" ) == true , "u->isKindOf('B')==true" );
		throwOnFalse( v->isKindOf( "B" ) == true , "v->isKindOf('B')==true" );
		throwOnFalse( w->isKindOf( "B" ) == true , "w->isKindOf('B')==true" );
		throwOnFalse( x->isKindOf( "B" ) == true , "x->isKindOf('B')==true" );
		throwOnFalse( y->isKindOf( "B" ) == true , "y->isKindOf('B')==true" );
		throwOnFalse( z->isKindOf( "B" ) == true , "z->isKindOf('B')==true" );

	}
	catch ( std::exception& e ) {
		std::cout << e.what() << std::endl;
		return false;
	}
	return true;

}
void setNullptr( Object* object ) {
	object->getClass()->getMethod( "setNullptr" );
	object->setObj( "Lexus" , nullptr );

}
bool testClassAddMethod() {
	try {
		Class A_class( nullptr , "A" );
		A_class.addStaticField( "Lexus" , OBJECT );
		Class B_class( &A_class , "B" );
		Class C_class( nullptr , "C" );
		Class D_class( nullptr , "D" );
		Class E_class( &A_class , "E" );
		Class F_class( &B_class , "F" );
		Class G_class( &F_class , "G" );
		Class H_class( nullptr , "H" );
		Class I_class( &D_class , "I" );
		Class J_class( nullptr , "J" );
		Class K_class( nullptr , "K" );
		Class L_class( &A_class , "L" );
		Class M_class( &B_class , "M" );
		Class N_class( &F_class , "N" );
		Class O_class( &A_class , "O" );
		Class P_class( &N_class , "P" );
		Class Q_class( &P_class , "Q" );
		Class R_class( &Q_class , "R" );
		Class S_class( &R_class , "S" );
		Class T_class( &S_class , "T" );
		Class U_class( &T_class , "U" );
		Class V_class( &U_class , "V" );
		Class W_class( &V_class , "W" );
		Class X_class( &W_class , "X" );
		Class Y_class( &X_class , "Y" );
		Class Z_class( &Y_class , "Z" );

		Object* a = A_class.newInstance();
		Object* b = B_class.newInstance();
		Object* c = C_class.newInstance();
		Object* d = D_class.newInstance();
		Object* e = E_class.newInstance();
		Object* f = F_class.newInstance();
		Object* g = G_class.newInstance();
		Object* h = H_class.newInstance();
		Object* i = I_class.newInstance();
		Object* j = J_class.newInstance();
		Object* k = K_class.newInstance();
		Object* l = L_class.newInstance();
		Object* m = M_class.newInstance();
		Object* n = N_class.newInstance();
		Object* o = O_class.newInstance();
		Object* p = P_class.newInstance();
		Object* q = Q_class.newInstance();
		Object* r = R_class.newInstance();
		Object* s = S_class.newInstance();
		Object* t = T_class.newInstance();
		Object* u = U_class.newInstance();
		Object* v = V_class.newInstance();
		Object* w = W_class.newInstance();
		Object* x = X_class.newInstance();
		Object* y = Y_class.newInstance();
		Object* z = Z_class.newInstance();

		A_class.addMethod( "setNullptr" , setNullptr );

		throwOnFalse( A_class.getObj( "Lexus" ) == nullptr ,
			"A_class.getObj('Lexus') == nullptr" );
		throwOnFalse( Z_class.getObj( "Lexus" ) == nullptr ,
			"Z_class.getObj('Lexus') == nullptr" );

		N_class.setObj( "Lexus" , x );

		throwOnFalse( A_class.getObj( "Lexus" ) == x ,
			"A_class.getObj('Lexus') == x" );

		throwOnFalse( B_class.getObj( "Lexus" ) == x ,
			"B_class.getObj('Lexus') == x" );
		try {
			throwOnFalse( C_class.getObj( "Lexus" ) == x ,
				"C_class.getObj('Lexus') == x" );
			return false; //
		}
		catch ( FieldNotFound& e ) {

		}
		catch ( std::exception& e ) {
			std::cout << e.what() << std::endl;
			return false;

		}
		try {
			throwOnFalse( D_class.getObj( "Lexus" ) == x ,
				"D_class.getObj('Lexus') == x" );
			return false; //
		}
		catch ( FieldNotFound& e ) {

		}
		catch ( std::exception& e ) {
			std::cout << e.what() << std::endl;
			return false;

		}
		throwOnFalse( E_class.getObj( "Lexus" ) == x ,
			"E_class.getObj('Lexus') == x" );
		throwOnFalse( F_class.getObj( "Lexus" ) == x ,
			"F_class.getObj('Lexus') == x" );
		throwOnFalse( G_class.getObj( "Lexus" ) == x ,
			"G_class.getObj('Lexus') == x" );
		try {
			throwOnFalse( H_class.getObj( "Lexus" ) == x ,
				"H_class.getObj('Lexus') == x" );
			return false; //
		}
		catch ( FieldNotFound& e ) {

		}
		catch ( std::exception& e ) {
			std::cout << e.what() << std::endl;
			return false;

		}
		try {
			throwOnFalse( I_class.getObj( "Lexus" ) == x ,
				"I_class.getObj('Lexus') == x" );
			return false; //
		}
		catch ( FieldNotFound& e ) {

		}
		catch ( std::exception& e ) {
			std::cout << e.what() << std::endl;
			return false;

		}
		try {
			throwOnFalse( J_class.getObj( "Lexus" ) == x ,
				"J_class.getObj('Lexus') == x" );
			return false; //
		}
		catch ( FieldNotFound& e ) {

		}
		catch ( std::exception& e ) {
			std::cout << e.what() << std::endl;
			return false;

		}

		try {

			throwOnFalse( K_class.getObj( "Lexus" ) == x ,
				"K_class.getObj('Lexus') == x" );
			return false; //
		}
		catch ( FieldNotFound& e ) {

		}
		catch ( std::exception& e ) {
			std::cout << e.what() << std::endl;
			return false;

		}

		throwOnFalse( L_class.getObj( "Lexus" ) == x ,
			"L_class.getObj('Lexus') == x" );
		throwOnFalse( M_class.getObj( "Lexus" ) == x ,
			"M_class.getObj('Lexus') == x" );
		throwOnFalse( N_class.getObj( "Lexus" ) == x ,
			"N_class.getObj('Lexus') == x" );
		throwOnFalse( O_class.getObj( "Lexus" ) == x ,
			"O_class.getObj('Lexus') == x" );
		throwOnFalse( P_class.getObj( "Lexus" ) == x ,
			"P_class.getObj('Lexus') == x" );
		throwOnFalse( Q_class.getObj( "Lexus" ) == x ,
			"Q_class.getObj('Lexus') == x" );
		throwOnFalse( R_class.getObj( "Lexus" ) == x ,
			"R_class.getObj('Lexus') == x" );
		throwOnFalse( S_class.getObj( "Lexus" ) == x ,
			"S_class.getObj('Lexus') == x" );
		throwOnFalse( T_class.getObj( "Lexus" ) == x ,
			"T_class.getObj('Lexus') == x" );
		throwOnFalse( U_class.getObj( "Lexus" ) == x ,
			"U_class.getObj('Lexus') == x" );
		throwOnFalse( V_class.getObj( "Lexus" ) == x ,
			"V_class.getObj('Lexus') == x" );
		throwOnFalse( W_class.getObj( "Lexus" ) == x ,
			"W_class.getObj('Lexus') == x" );
		throwOnFalse( X_class.getObj( "Lexus" ) == x ,
			"X_class.getObj('Lexus') == x" );
		throwOnFalse( Y_class.getObj( "Lexus" ) == x ,
			"Y_class.getObj('Lexus') == x" );
		throwOnFalse( Z_class.getObj( "Lexus" ) == x ,
			"Z_class.getObj('Lexus') == x" );

		a->invokeMethod( "setNullptr" );
		throwOnFalse( a->getObj( "Lexus" ) == nullptr ,
			"a->getObj('Lexus') == nullptr" );
		N_class.setObj( "Lexus" , x );
		b->invokeMethod( "setNullptr" );
		throwOnFalse( b->getObj( "Lexus" ) == nullptr ,
			"b->getObj('Lexus') == nullptr" );
		N_class.setObj( "Lexus" , x );

		try {
			c->invokeMethod( "setNullptr" );
			throwOnFalse( c->getObj( "Lexus" ) == nullptr ,
				"c->getObj('Lexus') == nullptr" );
			return false; //
		}
		catch ( MethodNotFound& e ) {

		}
		catch ( std::exception& e ) {
			std::cout << e.what() << std::endl;
			return false;

		}
		try {
			d->invokeMethod( "setNullptr" );
			throwOnFalse( d->getObj( "Lexus" ) == nullptr ,
				"d->getObj('Lexus') == nullptr" );
			return false; //
		}
		catch ( MethodNotFound& e ) {

		}
		catch ( std::exception& e ) {
			std::cout << e.what() << std::endl;
			return false;

		}

		e->invokeMethod( "setNullptr" );
		throwOnFalse( e->getObj( "Lexus" ) == nullptr ,
			"e->getObj('Lexus') == nullptr" );
		N_class.setObj( "Lexus" , x );
		f->invokeMethod( "setNullptr" );
		throwOnFalse( f->getObj( "Lexus" ) == nullptr ,
			"f->getObj('Lexus') == nullptr" );
		N_class.setObj( "Lexus" , x );
		g->invokeMethod( "setNullptr" );
		throwOnFalse( g->getObj( "Lexus" ) == nullptr ,
			"g->getObj('Lexus') == nullptr" );
		try {

			h->invokeMethod( "setNullptr" );
			throwOnFalse( h->getObj( "Lexus" ) == nullptr ,
				"h->getObj('Lexus') == nullptr" );
			return false; //
		}
		catch ( MethodNotFound& e ) {

		}
		catch ( std::exception& e ) {
			std::cout << e.what() << std::endl;
			return false;

		}
		try {

			i->invokeMethod( "setNullptr" );
			throwOnFalse( i->getObj( "Lexus" ) == nullptr ,
				"i->getObj('Lexus') == nullptr" );
			return false; //
		}
		catch ( MethodNotFound& e ) {

		}
		catch ( std::exception& e ) {
			std::cout << e.what() << std::endl;
			return false;

		}
		try {

			j->invokeMethod( "setNullptr" );
			throwOnFalse( j->getObj( "Lexus" ) == nullptr ,
				"j->getObj('Lexus') == nullptr" );
			return false; //
		}
		catch ( MethodNotFound& e ) {

		}
		catch ( std::exception& e ) {
			std::cout << e.what() << std::endl;
			return false;

		}

		try {

			k->invokeMethod( "setNullptr" );
			throwOnFalse( k->getObj( "Lexus" ) == nullptr ,
				"k->getObj('Lexus') == nullptr" );
			return false; //
		}
		catch ( MethodNotFound& e ) {

		}
		catch ( std::exception& e ) {
			std::cout << e.what() << std::endl;
			return false;

		}

		N_class.setObj( "Lexus" , x );
		l->invokeMethod( "setNullptr" );
		throwOnFalse( l->getObj( "Lexus" ) == nullptr ,
			"l->getObj('Lexus') == nullptr" );
		N_class.setObj( "Lexus" , x );
		m->invokeMethod( "setNullptr" );
		throwOnFalse( m->getObj( "Lexus" ) == nullptr ,
			"m->getObj('Lexus') == nullptr" );
		N_class.setObj( "Lexus" , x );
		n->invokeMethod( "setNullptr" );
		throwOnFalse( n->getObj( "Lexus" ) == nullptr ,
			"n->getObj('Lexus') == nullptr" );
		N_class.setObj( "Lexus" , x );
		o->invokeMethod( "setNullptr" );
		throwOnFalse( o->getObj( "Lexus" ) == nullptr ,
			"o->getObj('Lexus') == nullptr" );
		N_class.setObj( "Lexus" , x );
		p->invokeMethod( "setNullptr" );
		throwOnFalse( p->getObj( "Lexus" ) == nullptr ,
			"p->getObj('Lexus') == nullptr" );
		N_class.setObj( "Lexus" , x );
		q->invokeMethod( "setNullptr" );
		throwOnFalse( q->getObj( "Lexus" ) == nullptr ,
			"q->getObj('Lexus') == nullptr" );
		N_class.setObj( "Lexus" , x );
		r->invokeMethod( "setNullptr" );
		throwOnFalse( r->getObj( "Lexus" ) == nullptr ,
			"r->getObj('Lexus') == nullptr" );
		N_class.setObj( "Lexus" , x );
		s->invokeMethod( "setNullptr" );
		throwOnFalse( s->getObj( "Lexus" ) == nullptr ,
			"s->getObj('Lexus') == nullptr" );
		N_class.setObj( "Lexus" , x );
		t->invokeMethod( "setNullptr" );
		throwOnFalse( t->getObj( "Lexus" ) == nullptr ,
			"t->getObj('Lexus') == nullptr" );
		N_class.setObj( "Lexus" , x );
		u->invokeMethod( "setNullptr" );
		throwOnFalse( u->getObj( "Lexus" ) == nullptr ,
			"u->getObj('Lexus') == nullptr" );
		N_class.setObj( "Lexus" , x );
		v->invokeMethod( "setNullptr" );
		throwOnFalse( v->getObj( "Lexus" ) == nullptr ,
			"v->getObj('Lexus') == nullptr" );
		N_class.setObj( "Lexus" , x );
		w->invokeMethod( "setNullptr" );
		throwOnFalse( w->getObj( "Lexus" ) == nullptr ,
			"w->getObj('Lexus') == nullptr" );
		N_class.setObj( "Lexus" , x );
		x->invokeMethod( "setNullptr" );
		throwOnFalse( x->getObj( "Lexus" ) == nullptr ,
			"x->getObj('Lexus') == nullptr" );
		N_class.setObj( "Lexus" , x );
		y->invokeMethod( "setNullptr" );
		throwOnFalse( y->getObj( "Lexus" ) == nullptr ,
			"y->getObj('Lexus') == nullptr" );
		N_class.setObj( "Lexus" , x );
		z->invokeMethod( "setNullptr" );
		throwOnFalse( z->getObj( "Lexus" ) == nullptr ,
			"z->getObj('Lexus') == nullptr" );

	}
	catch ( std::exception& e ) {
		std::cout << e.what() << std::endl;
		return false;
	}
	return true;

}
bool testClassAddInstanceField() {
	try {
		Class A_class( nullptr , "A" );
		A_class.addInstanceField( "Ferrari" , INT ); // Int
		Class B_class( &A_class , "B" );
		Class C_class( nullptr , "C" );
		Class D_class( nullptr , "D" );
		Class E_class( &A_class , "E" );
		Class F_class( &B_class , "F" );
		F_class.addInstanceField( "Ferrari" , OBJECT ); // Object
		Class G_class( &F_class , "G" );
		Class H_class( nullptr , "H" );
		Class I_class( &D_class , "I" );
		Class J_class( nullptr , "J" );
		Class K_class( nullptr , "K" );
		Class L_class( &A_class , "L" );
		Class M_class( &B_class , "M" );
		Class N_class( &F_class , "N" );
		Class O_class( &A_class , "O" );
		Class P_class( &N_class , "P" );
		Class Q_class( &P_class , "Q" );
		Class R_class( &Q_class , "R" );
		Class S_class( &R_class , "S" );
		Class T_class( &S_class , "T" );
		Class U_class( &T_class , "U" );
		Class V_class( &U_class , "V" );
		Class W_class( &V_class , "W" );
		Class X_class( &W_class , "X" );
		Class Y_class( &X_class , "Y" );
		Class Z_class( &Y_class , "Z" );

		Object* a = A_class.newInstance();
		Object* b = B_class.newInstance();
		Object* c = C_class.newInstance();
		Object* d = D_class.newInstance();
		Object* e = E_class.newInstance();
		Object* f = F_class.newInstance();
		Object* g = G_class.newInstance();
		Object* h = H_class.newInstance();
		Object* i = I_class.newInstance();
		Object* j = J_class.newInstance();
		Object* k = K_class.newInstance();
		Object* l = L_class.newInstance();
		Object* m = M_class.newInstance();
		Object* n = N_class.newInstance();
		Object* o = O_class.newInstance();
		Object* p = P_class.newInstance();
		Object* q = Q_class.newInstance();
		Object* r = R_class.newInstance();
		Object* s = S_class.newInstance();
		Object* t = T_class.newInstance();
		Object* u = U_class.newInstance();
		Object* v = V_class.newInstance();
		Object* w = W_class.newInstance();
		Object* x = X_class.newInstance();
		Object* y = Y_class.newInstance();
		Object* z = Z_class.newInstance();
		A_class.addInstanceField( "Lexus" , INT );

		try {
			a->getInt( "Lexus" );

		}
		catch ( FieldNotFound& e ) {

		}
		catch ( std::exception& e ) {
			std::cout << e.what() << std::endl;
			return false;

		}
		try {
			b->getInt( "Lexus" );
		}
		catch ( FieldNotFound& e ) {

		}
		catch ( std::exception& e ) {
			std::cout << e.what() << std::endl;
			return false;

		}
		try {
			c->getInt( "Lexus" );
		}
		catch ( FieldNotFound& e ) {

		}
		catch ( std::exception& e ) {
			std::cout << e.what() << std::endl;
			return false;

		}
		try {
			d->getInt( "Lexus" );
		}
		catch ( FieldNotFound& e ) {

		}
		catch ( std::exception& e ) {
			std::cout << e.what() << std::endl;
			return false;

		}
		try {
			e->getInt( "Lexus" );
		}
		catch ( FieldNotFound& e ) {

		}
		catch ( std::exception& e ) {
			std::cout << e.what() << std::endl;
			return false;

		}
		try {
			f->getInt( "Lexus" );
		}
		catch ( FieldNotFound& e ) {

		}
		catch ( std::exception& e ) {
			std::cout << e.what() << std::endl;
			return false;

		}
		try {
			g->getInt( "Lexus" );
		}
		catch ( FieldNotFound& e ) {

		}
		catch ( std::exception& e ) {
			std::cout << e.what() << std::endl;
			return false;

		}
		try {
			h->getInt( "Lexus" );
			return false; //
		}
		catch ( FieldNotFound& e ) {

		}
		catch ( std::exception& e ) {
			std::cout << e.what() << std::endl;
			return false;

		}
		try {
			i->getInt( "Lexus" );
		}
		catch ( FieldNotFound& e ) {

		}
		catch ( std::exception& e ) {
			std::cout << e.what() << std::endl;
			return false;

		}
		try {
			j->getInt( "Lexus" );
		}
		catch ( FieldNotFound& e ) {

		}
		catch ( std::exception& e ) {
			std::cout << e.what() << std::endl;
			return false;

		}
		try {
			k->getInt( "Lexus" );
		}
		catch ( FieldNotFound& e ) {

		}
		catch ( std::exception& e ) {
			std::cout << e.what() << std::endl;
			return false;

		}
		try {
			l->getInt( "Lexus" );
		}
		catch ( FieldNotFound& e ) {

		}
		catch ( std::exception& e ) {
			std::cout << e.what() << std::endl;
			return false;

		}
		try {
			m->getInt( "Lexus" );
		}
		catch ( FieldNotFound& e ) {

		}
		catch ( std::exception& e ) {
			std::cout << e.what() << std::endl;
			return false;

		}
		try {
			n->getInt( "Lexus" );
		}
		catch ( FieldNotFound& e ) {

		}
		catch ( std::exception& e ) {
			std::cout << e.what() << std::endl;
			return false;

		}
		try {
			o->getInt( "Lexus" );
		}
		catch ( FieldNotFound& e ) {

		}
		catch ( std::exception& e ) {
			std::cout << e.what() << std::endl;
			return false;

		}
		try {
			p->getInt( "Lexus" );

		}
		catch ( FieldNotFound& e ) {

		}
		catch ( std::exception& e ) {
			std::cout << e.what() << std::endl;
			return false;

		}
		try {
			q->getInt( "Lexus" );
		}
		catch ( FieldNotFound& e ) {

		}
		catch ( std::exception& e ) {
			std::cout << e.what() << std::endl;
			return false;

		}
		try {
			r->getInt( "Lexus" );
		}
		catch ( FieldNotFound& e ) {

		}
		catch ( std::exception& e ) {
			std::cout << e.what() << std::endl;
			return false;

		}
		try {
			s->getInt( "Lexus" );
		}
		catch ( FieldNotFound& e ) {

		}
		catch ( std::exception& e ) {
			std::cout << e.what() << std::endl;
			return false;

		}
		try {
			t->getInt( "Lexus" );
		}
		catch ( FieldNotFound& e ) {

		}
		catch ( std::exception& e ) {
			std::cout << e.what() << std::endl;
			return false;

		}
		try {
			u->getInt( "Lexus" );
		}
		catch ( FieldNotFound& e ) {

		}
		catch ( std::exception& e ) {
			std::cout << e.what() << std::endl;
			return false;

		}
		try {
			v->getInt( "Lexus" );
		}
		catch ( FieldNotFound& e ) {

		}
		catch ( std::exception& e ) {
			std::cout << e.what() << std::endl;
			return false;

		}
		try {
			w->getInt( "Lexus" );
		}
		catch ( FieldNotFound& e ) {

		}
		catch ( std::exception& e ) {
			std::cout << e.what() << std::endl;
			return false;

		}
		try {
			x->getInt( "Lexus" );
		}
		catch ( FieldNotFound& e ) {

		}
		catch ( std::exception& e ) {
			std::cout << e.what() << std::endl;
			return false;

		}
		try {
			y->getInt( "Lexus" );
		}
		catch ( FieldNotFound& e ) {

		}
		catch ( std::exception& e ) {
			std::cout << e.what() << std::endl;
			return false;

		}
		try {
			z->getInt( "Lexus" );
		}
		catch ( FieldNotFound& e ) {

		}
		catch ( std::exception& e ) {
			std::cout << e.what() << std::endl;
			return false;

		}

		throwOnFalse( a->getInt( "Ferrari" ) == 0 , "a->getInt('Ferrari')==0" );
		throwOnFalse( b->getInt( "Ferrari" ) == 0 , "b->getInt('Ferrari')==0" );
		try {
			throwOnFalse( c->getInt( "Ferrari" ) == 0 , "c->getInt('Ferrari')==0" );
		}
		catch ( FieldNotFound& e ) {

		}
		catch ( std::exception& e ) {
			std::cout << e.what() << std::endl;
			return false;

		}
		try {
			throwOnFalse( d->getInt( "Ferrari" ) == 0 , "d->getInt('Ferrari')==0" );
		}
		catch ( FieldNotFound& e ) {

		}
		catch ( std::exception& e ) {
			std::cout << e.what() << std::endl;
			return false;

		}
		throwOnFalse( e->getInt( "Ferrari" ) == 0 , "e->getInt('Ferrari')==0" );
		throwOnFalse( f->getObj( "Ferrari" ) == nullptr ,
			"f->getObj('Ferrari') == nullptr" );
		throwOnFalse( g->getObj( "Ferrari" ) == nullptr ,
			"g->getObj('Ferrari') == nullptr" );
		try {
			throwOnFalse( h->getInt( "Ferrari" ) == 0 , "h->getInt('Ferrari')==0" );
			return false; //
		}
		catch ( FieldNotFound& e ) {

		}
		catch ( std::exception& e ) {
			std::cout << e.what() << std::endl;
			return false;

		}

		try {
			throwOnFalse( i->getInt( "Ferrari" ) == 0 , "i->getInt('Ferrari')==0" );
			return false; //
		}
		catch ( FieldNotFound& e ) {

		}
		catch ( std::exception& e ) {
			std::cout << e.what() << std::endl;
			return false;

		}
		try {
			throwOnFalse( j->getInt( "Ferrari" ) == 0 , "j->getInt('Ferrari')==0" );
			return false; //
		}
		catch ( FieldNotFound& e ) {

		}
		catch ( std::exception& e ) {
			std::cout << e.what() << std::endl;
			return false;

		}

		try {
			throwOnFalse( k->getInt( "Ferrari" ) == 0 , "k->getInt('Ferrari')==0" );
			return false; //
		}
		catch ( FieldNotFound& e ) {

		}
		catch ( std::exception& e ) {
			std::cout << e.what() << std::endl;
			return false;

		}
		throwOnFalse( l->getInt( "Ferrari" ) == 0 , "l->getInt('Ferrari')==0" );
		throwOnFalse( m->getInt( "Ferrari" ) == 0 , "m->getInt('Ferrari')==0" );
		throwOnFalse( n->getObj( "Ferrari" ) == nullptr ,
			"n->getObj('Ferrari') == nullptr" );
		throwOnFalse( o->getInt( "Ferrari" ) == 0 , "o->getInt('Ferrari')==0" );
		throwOnFalse( p->getObj( "Ferrari" ) == nullptr ,
			"p->getObj('Ferrari') == nullptr" );
		throwOnFalse( q->getObj( "Ferrari" ) == nullptr ,
			"q->getObj('Ferrari') == nullptr" );
		throwOnFalse( r->getObj( "Ferrari" ) == nullptr ,
			"r->getObj('Ferrari') == nullptr" );
		throwOnFalse( s->getObj( "Ferrari" ) == nullptr ,
			"s->getObj('Ferrari') == nullptr" );
		throwOnFalse( t->getObj( "Ferrari" ) == nullptr ,
			"t->getObj('Ferrari') == nullptr" );
		throwOnFalse( u->getObj( "Ferrari" ) == nullptr ,
			"u->getObj('Ferrari') == nullptr" );
		throwOnFalse( v->getObj( "Ferrari" ) == nullptr ,
			"v->getObj('Ferrari') == nullptr" );
		throwOnFalse( w->getObj( "Ferrari" ) == nullptr ,
			"w->getObj('Ferrari') == nullptr" );
		throwOnFalse( x->getObj( "Ferrari" ) == nullptr ,
			"x->getObj('Ferrari') == nullptr" );
		throwOnFalse( y->getObj( "Ferrari" ) == nullptr ,
			"y->getObj('Ferrari') == nullptr" );
		throwOnFalse( z->getObj( "Ferrari" ) == nullptr ,
			"z->getObj('Ferrari') == nullptr" );

	}
	catch ( std::exception& e ) {
		std::cout << e.what() << std::endl;
		return false;
	}
	return true;

}
bool testClassAddStaticField() {
	try {
		Class A_class( nullptr , "A" );
		Class B_class( &A_class , "B" );
		Class C_class( nullptr , "C" );
		Class D_class( nullptr , "D" );
		Class E_class( &A_class , "E" );
		Class F_class( &B_class , "F" );
		F_class.addStaticField( "Ferrari" , INT );
		Class G_class( &F_class , "G" );
		Class H_class( nullptr , "H" );
		Class I_class( &D_class , "I" );
		Class J_class( nullptr , "J" );
		Class K_class( nullptr , "K" );
		Class L_class( &A_class , "L" );
		Class M_class( &B_class , "M" );
		Class N_class( &F_class , "N" );
		Class O_class( &A_class , "O" );
		Class P_class( &N_class , "P" );
		Class Q_class( &P_class , "Q" );
		Class R_class( &Q_class , "R" );
		Class S_class( &R_class , "S" );
		Class T_class( &S_class , "T" );
		Class U_class( &T_class , "U" );
		Class V_class( &U_class , "V" );
		Class W_class( &V_class , "W" );
		Class X_class( &W_class , "X" );
		Class Y_class( &X_class , "Y" );
		Class Z_class( &Y_class , "Z" );

		Object* a = A_class.newInstance();
		Object* b = B_class.newInstance();
		Object* c = C_class.newInstance();
		Object* d = D_class.newInstance();
		Object* e = E_class.newInstance();
		Object* f = F_class.newInstance();
		Object* g = G_class.newInstance();
		Object* h = H_class.newInstance();
		Object* i = I_class.newInstance();
		Object* j = J_class.newInstance();
		Object* k = K_class.newInstance();
		Object* l = L_class.newInstance();
		Object* m = M_class.newInstance();
		Object* n = N_class.newInstance();
		Object* o = O_class.newInstance();
		Object* p = P_class.newInstance();
		Object* q = Q_class.newInstance();
		Object* r = R_class.newInstance();
		Object* s = S_class.newInstance();
		Object* t = T_class.newInstance();
		Object* u = U_class.newInstance();
		Object* v = V_class.newInstance();
		Object* w = W_class.newInstance();
		Object* x = X_class.newInstance();
		Object* y = Y_class.newInstance();
		Object* z = Z_class.newInstance();

		try {
			A_class.setInt( "Ferrari" , 42 );
			return false; //
		}
		catch ( FieldNotFound& e ) {

		}
		catch ( std::exception& e ) {
			std::cout << e.what() << std::endl;
			return false;

		}

		F_class.setInt( "Ferrari" , 5555 );

		try {
			throwOnFalse( b->getInt( "Ferrari" ) == 42 ,
				"b->getInt('Ferrari')==42" );
			return false; //
		}
		catch ( FieldNotFound& e ) {

		}
		catch ( std::exception& e ) {
			std::cout << e.what() << std::endl;
			return false;

		}
		try {
			throwOnFalse( c->getInt( "Ferrari" ) == 42 ,
				"c->getInt('Ferrari')==42" );
			return false; //
		}
		catch ( FieldNotFound& e ) {

		}
		catch ( std::exception& e ) {
			std::cout << e.what() << std::endl;
			return false;

		}
		try {
			throwOnFalse( d->getInt( "Ferrari" ) == 42 ,
				"d->getInt('Ferrari')==42" );
			return false; //
		}
		catch ( FieldNotFound& e ) {

		}
		catch ( std::exception& e ) {
			std::cout << e.what() << std::endl;
			return false;

		}
		try {
			throwOnFalse( e->getInt( "Ferrari" ) == 42 ,
				"e->getInt('Ferrari')==42" );
			return false; //
		}
		catch ( FieldNotFound& e ) {

		}
		catch ( std::exception& e ) {
			std::cout << e.what() << std::endl;
			return false;

		}

		throwOnFalse( f->getInt( "Ferrari" ) == 5555 ,
			"f->getInt('Ferrari')==5555" );
		throwOnFalse( g->getInt( "Ferrari" ) == 5555 ,
			"g->getInt('Ferrari')==5555" );
		try {
			throwOnFalse( h->getInt( "Ferrari" ) == 42 ,
				"h->getInt('Ferrari')==42" );
			return false; //
		}
		catch ( FieldNotFound& e ) {

		}
		catch ( std::exception& e ) {
			std::cout << e.what() << std::endl;
			return false;

		}
		try {
			throwOnFalse( i->getInt( "Ferrari" ) == 42 ,
				"i->getInt('Ferrari')==42" );
			return false; //
		}
		catch ( FieldNotFound& e ) {

		}
		catch ( std::exception& e ) {
			std::cout << e.what() << std::endl;
			return false;

		}
		try {
			throwOnFalse( j->getInt( "Ferrari" ) == 42 ,
				"j->getInt('Ferrari')==42" );
			return false; //
		}
		catch ( FieldNotFound& e ) {

		}
		catch ( std::exception& e ) {
			std::cout << e.what() << std::endl;
			return false;

		}
		try {
			throwOnFalse( k->getInt( "Ferrari" ) == 42 ,
				"k->getInt('Ferrari')==42" );
			return false; //
		}
		catch ( FieldNotFound& e ) {

		}
		catch ( std::exception& e ) {
			std::cout << e.what() << std::endl;
			return false;

		}
		try {
			throwOnFalse( l->getInt( "Ferrari" ) == 42 ,
				"l->getInt('Ferrari')==42" );
			return false; //
		}
		catch ( FieldNotFound& e ) {

		}
		catch ( std::exception& e ) {
			std::cout << e.what() << std::endl;
			return false;

		}

		try {
			throwOnFalse( m->getInt( "Ferrari" ) == 42 ,
				"m->getInt('Ferrari')==42" );

		}
		catch ( FieldNotFound& e ) {

		}
		catch ( std::exception& e ) {
			std::cout << e.what() << std::endl;
			return false;

		}

		throwOnFalse( n->getInt( "Ferrari" ) == 5555 ,
			"n->getInt('Ferrari')==5555" );
		try {
			throwOnFalse( o->getInt( "Ferrari" ) == 42 ,
				"o->getInt('Ferrari')==42" );
			return false; //
		}
		catch ( FieldNotFound& e ) {

		}
		catch ( std::exception& e ) {
			std::cout << e.what() << std::endl;
			return false;

		}
		throwOnFalse( p->getInt( "Ferrari" ) == 5555 ,
			"p->getInt('Ferrari')==5555" );
		throwOnFalse( q->getInt( "Ferrari" ) == 5555 ,
			"q->getInt('Ferrari')==5555" );
		throwOnFalse( r->getInt( "Ferrari" ) == 5555 ,
			"r->getInt('Ferrari')==5555" );
		throwOnFalse( s->getInt( "Ferrari" ) == 5555 ,
			"s->getInt('Ferrari')==5555" );
		throwOnFalse( t->getInt( "Ferrari" ) == 5555 ,
			"t->getInt('Ferrari')==5555" );
		throwOnFalse( u->getInt( "Ferrari" ) == 5555 ,
			"u->getInt('Ferrari')==5555" );
		throwOnFalse( v->getInt( "Ferrari" ) == 5555 ,
			"v->getInt('Ferrari')==5555" );
		throwOnFalse( w->getInt( "Ferrari" ) == 5555 ,
			"w->getInt('Ferrari')==5555" );
		throwOnFalse( x->getInt( "Ferrari" ) == 5555 ,
			"x->getInt('Ferrari')==5555" );
		throwOnFalse( y->getInt( "Ferrari" ) == 5555 ,
			"y->getInt('Ferrari')==5555" );
		throwOnFalse( z->getInt( "Ferrari" ) == 5555 ,
			"z->getInt('Ferrari')==5555" );

	}
	catch ( std::exception& e ) {
		std::cout << e.what() << std::endl;
		return false;
	}
	return true;

}
bool testClassGetField() {
	try {
		Class A_class( nullptr , "A" );
		Class B_class( &A_class , "B" );
		Class C_class( nullptr , "C" );
		Class D_class( nullptr , "D" );
		Class E_class( &A_class , "E" );
		Class F_class( &B_class , "F" );
		F_class.addStaticField( "Ferrari" , INT );
		Class G_class( &F_class , "G" );
		Class H_class( nullptr , "H" );
		Class I_class( &D_class , "I" );
		Class J_class( nullptr , "J" );
		Class K_class( nullptr , "K" );
		Class L_class( &A_class , "L" );
		Class M_class( &B_class , "M" );
		Class N_class( &F_class , "N" );
		Class O_class( &A_class , "O" );
		Class P_class( &N_class , "P" );
		Class Q_class( &P_class , "Q" );
		Class R_class( &Q_class , "R" );
		Class S_class( &R_class , "S" );
		Class T_class( &S_class , "T" );
		Class U_class( &T_class , "U" );
		Class V_class( &U_class , "V" );
		Class W_class( &V_class , "W" );
		Class X_class( &W_class , "X" );
		Class Y_class( &X_class , "Y" );
		Class Z_class( &Y_class , "Z" );
		A_class.addStaticField( "Lexus" , INT );

		Object* a = A_class.newInstance();
		Object* b = B_class.newInstance();
		Object* c = C_class.newInstance();
		Object* d = D_class.newInstance();
		Object* e = E_class.newInstance();
		Object* f = F_class.newInstance();
		Object* g = G_class.newInstance();
		Object* h = H_class.newInstance();
		Object* i = I_class.newInstance();
		Object* j = J_class.newInstance();
		Object* k = K_class.newInstance();
		Object* l = L_class.newInstance();
		Object* m = M_class.newInstance();
		Object* n = N_class.newInstance();
		Object* o = O_class.newInstance();
		Object* p = P_class.newInstance();
		Object* q = Q_class.newInstance();
		Object* r = R_class.newInstance();
		Object* s = S_class.newInstance();
		Object* t = T_class.newInstance();
		Object* u = U_class.newInstance();
		Object* v = V_class.newInstance();
		Object* w = W_class.newInstance();
		Object* x = X_class.newInstance();
		Object* y = Y_class.newInstance();
		Object* z = Z_class.newInstance();
		Class::setAccessible( true );
		Field ferrari = X_class.getField( "Ferrari" );
		Field lexus = Z_class.getField( "Lexus" );

		ferrari.setInt( y , 777 );
		lexus.setInt( p , 50 );

		throwOnFalse( q->getInt( "Ferrari" ) == 777 , "q->getInt('Ferrari')==777" );
		throwOnFalse( s->getInt( "Lexus" ) == 50 , "s->getInt('Lexus')==50" );

	}
	catch ( std::exception& e ) {
		std::cout << e.what() << std::endl;
		return false;
	}
	return true;

}
bool testClassGetMethod() {
	try {
		Class A_class( nullptr , "A" );
		A_class.addStaticField( "Lexus" , OBJECT );
		Class B_class( &A_class , "B" );
		Class C_class( nullptr , "C" );
		Class D_class( nullptr , "D" );
		Class E_class( &A_class , "E" );
		Class F_class( &B_class , "F" );
		Class G_class( &F_class , "G" );
		Class H_class( nullptr , "H" );
		Class I_class( &D_class , "I" );
		Class J_class( nullptr , "J" );
		Class K_class( nullptr , "K" );
		Class L_class( &A_class , "L" );
		Class M_class( &B_class , "M" );
		Class N_class( &F_class , "N" );
		Class O_class( &A_class , "O" );
		Class P_class( &N_class , "P" );
		Class Q_class( &P_class , "Q" );
		Class R_class( &Q_class , "R" );
		Class S_class( &R_class , "S" );
		Class T_class( &S_class , "T" );
		Class U_class( &T_class , "U" );
		Class V_class( &U_class , "V" );
		Class W_class( &V_class , "W" );
		Class X_class( &W_class , "X" );
		Class Y_class( &X_class , "Y" );
		Class Z_class( &Y_class , "Z" );

		Object* a = A_class.newInstance();

		Object* b = B_class.newInstance();

		Object* c = C_class.newInstance();

		Object* d = D_class.newInstance();

		Object* e = E_class.newInstance();

		Object* f = F_class.newInstance();

		Object* g = G_class.newInstance();

		Object* h = H_class.newInstance();

		Object* i = I_class.newInstance();

		Object* j = J_class.newInstance();

		Object* k = K_class.newInstance();

		Object* l = L_class.newInstance();

		Object* m = M_class.newInstance();

		Object* n = N_class.newInstance();

		Object* o = O_class.newInstance();

		Object* p = P_class.newInstance();

		Object* q = Q_class.newInstance();

		Object* r = R_class.newInstance();

		Object* s = S_class.newInstance();

		Object* t = T_class.newInstance();

		Object* u = U_class.newInstance();

		Object* v = V_class.newInstance();

		Object* w = W_class.newInstance();

		Object* x = X_class.newInstance();

		Object* y = Y_class.newInstance();

		Object* z = Z_class.newInstance();

		A_class.addMethod( "setNullptr" , setNullptr );
		N_class.setObj( "Lexus" , x );

		try {
			c->getClass()->getMethod( "setNullptr" ).invoke( c );
			throwOnFalse( c->getObj( "Lexus" ) == nullptr ,
				"c->getObj('Lexus') == nullptr" );
			return false; //

		}
		catch ( MethodNotFound& e ) {

		}
		catch ( std::exception& e ) {
			std::cout << e.what() << std::endl;
			return false;

		}
		try {
			d->getClass()->getMethod( "setNullptr" ).invoke( d );
			throwOnFalse( d->getObj( "Lexus" ) == nullptr ,
				"d->getObj('Lexus') == nullptr" );
			return false; //

		}
		catch ( MethodNotFound& e ) {

		}
		catch ( std::exception& e ) {
			std::cout << e.what() << std::endl;
			return false;

		}

		e->getClass()->getMethod( "setNullptr" ).invoke( e );
		throwOnFalse( e->getObj( "Lexus" ) == nullptr ,
			"e->getObj('Lexus') == nullptr" );
		N_class.setObj( "Lexus" , x );
		f->getClass()->getMethod( "setNullptr" ).invoke( f );
		throwOnFalse( f->getObj( "Lexus" ) == nullptr ,
			"f->getObj('Lexus') == nullptr" );
		N_class.setObj( "Lexus" , x );
		g->getClass()->getMethod( "setNullptr" ).invoke( g );
		throwOnFalse( g->getObj( "Lexus" ) == nullptr ,
			"g->getObj('Lexus') == nullptr" );
		try {

			h->getClass()->getMethod( "setNullptr" ).invoke( h );
			throwOnFalse( h->getObj( "Lexus" ) == nullptr ,
				"h->getObj('Lexus') == nullptr" );
			return false; //

		}
		catch ( MethodNotFound& e ) {

		}
		catch ( std::exception& e ) {
			std::cout << e.what() << std::endl;
			return false;

		}
		try {

			i->getClass()->getMethod( "setNullptr" ).invoke( i );
			throwOnFalse( i->getObj( "Lexus" ) == nullptr ,
				"i->getObj('Lexus') == nullptr" );
			return false; //
		}
		catch ( MethodNotFound& e ) {

		}
		catch ( std::exception& e ) {
			std::cout << e.what() << std::endl;
			return false;

		}
		try {

			j->getClass()->getMethod( "setNullptr" ).invoke( j );
			throwOnFalse( j->getObj( "Lexus" ) == nullptr ,
				"j->getObj('Lexus') == nullptr" );
			return false; //
		}
		catch ( MethodNotFound& e ) {

		}
		catch ( std::exception& e ) {
			std::cout << e.what() << std::endl;
			return false;

		}

		try {

			k->getClass()->getMethod( "setNullptr" ).invoke( k );

			throwOnFalse( k->getObj( "Lexus" ) == nullptr ,
				"k->getObj('Lexus') == nullptr" );
			return false; //
		}
		catch ( MethodNotFound& e ) {

		}
		catch ( std::exception& e ) {
			std::cout << e.what() << std::endl;
			return false;

		}

		N_class.setObj( "Lexus" , x );
		l->getClass()->getMethod( "setNullptr" ).invoke( l );
		throwOnFalse( l->getObj( "Lexus" ) == nullptr ,
			"l->getObj('Lexus') == nullptr" );
		N_class.setObj( "Lexus" , x );
		m->getClass()->getMethod( "setNullptr" ).invoke( m );
		throwOnFalse( m->getObj( "Lexus" ) == nullptr ,
			"m->getObj('Lexus') == nullptr" );
		N_class.setObj( "Lexus" , x );
		n->getClass()->getMethod( "setNullptr" ).invoke( n );
		throwOnFalse( n->getObj( "Lexus" ) == nullptr ,
			"n->getObj('Lexus') == nullptr" );
		N_class.setObj( "Lexus" , x );
		o->getClass()->getMethod( "setNullptr" ).invoke( o );
		throwOnFalse( o->getObj( "Lexus" ) == nullptr ,
			"o->getObj('Lexus') == nullptr" );
		N_class.setObj( "Lexus" , x );
		p->getClass()->getMethod( "setNullptr" ).invoke( p );
		throwOnFalse( p->getObj( "Lexus" ) == nullptr ,
			"p->getObj('Lexus') == nullptr" );
		N_class.setObj( "Lexus" , x );
		q->getClass()->getMethod( "setNullptr" ).invoke( q );
		throwOnFalse( q->getObj( "Lexus" ) == nullptr ,
			"q->getObj('Lexus') == nullptr" );
		N_class.setObj( "Lexus" , x );
		r->getClass()->getMethod( "setNullptr" ).invoke( r );
		throwOnFalse( r->getObj( "Lexus" ) == nullptr ,
			"r->getObj('Lexus') == nullptr" );
		N_class.setObj( "Lexus" , x );
		s->getClass()->getMethod( "setNullptr" ).invoke( s );
		throwOnFalse( s->getObj( "Lexus" ) == nullptr ,
			"s->getObj('Lexus') == nullptr" );
		N_class.setObj( "Lexus" , x );
		t->getClass()->getMethod( "setNullptr" ).invoke( t );
		throwOnFalse( t->getObj( "Lexus" ) == nullptr ,
			"t->getObj('Lexus') == nullptr" );
		N_class.setObj( "Lexus" , x );
		u->getClass()->getMethod( "setNullptr" ).invoke( u );
		throwOnFalse( u->getObj( "Lexus" ) == nullptr ,
			"u->getObj('Lexus') == nullptr" );
		N_class.setObj( "Lexus" , x );
		v->getClass()->getMethod( "setNullptr" ).invoke( v );
		throwOnFalse( v->getObj( "Lexus" ) == nullptr ,
			"v->getObj('Lexus') == nullptr" );
		N_class.setObj( "Lexus" , x );
		w->getClass()->getMethod( "setNullptr" ).invoke( w );
		throwOnFalse( w->getObj( "Lexus" ) == nullptr ,
			"w->getObj('Lexus') == nullptr" );
		N_class.setObj( "Lexus" , x );
		x->getClass()->getMethod( "setNullptr" ).invoke( x );
		throwOnFalse( x->getObj( "Lexus" ) == nullptr ,
			"x->getObj('Lexus') == nullptr" );
		N_class.setObj( "Lexus" , x );
		y->getClass()->getMethod( "setNullptr" ).invoke( y );
		throwOnFalse( y->getObj( "Lexus" ) == nullptr ,
			"y->getObj('Lexus') == nullptr" );
		N_class.setObj( "Lexus" , x );
		z->getClass()->getMethod( "setNullptr" ).invoke( z );
		throwOnFalse( z->getObj( "Lexus" ) == nullptr ,
			"z->getObj('Lexus') == nullptr" );

	}
	catch ( std::exception& e ) {
		std::cout << e.what() << std::endl;
		return false;
	}
	return true;

}
bool testClassGetFields() {
	try {
		Class A_class( nullptr , "A" );
		A_class.addInstanceField( "Fun :)" , OBJECT ); // NOT STATIC :(,but fun! ^^
		Class B_class( &A_class , "B" );
		Class C_class( nullptr , "C" );
		Class D_class( nullptr , "D" );
		Class E_class( &A_class , "E" );
		Class F_class( &B_class , "F" );
		F_class.addStaticField( "Ferrari" , INT );
		Class G_class( &F_class , "G" );
		Class H_class( nullptr , "H" );
		Class I_class( &D_class , "I" );
		Class J_class( nullptr , "J" );
		Class K_class( nullptr , "K" );
		Class L_class( &A_class , "L" );
		Class M_class( &B_class , "M" );
		Class N_class( &F_class , "N" );
		Class O_class( &A_class , "O" );
		Class P_class( &N_class , "P" );
		Class Q_class( &P_class , "Q" );
		Class R_class( &Q_class , "R" );
		Class S_class( &R_class , "S" );
		Class T_class( &S_class , "T" );
		Class U_class( &T_class , "U" );
		Class V_class( &U_class , "V" );
		Class W_class( &V_class , "W" );
		Class X_class( &W_class , "X" );
		Class Y_class( &X_class , "Y" );
		Class Z_class( &Y_class , "Z" );
		A_class.addStaticField( "Lexus" , INT );

		Object* a = A_class.newInstance();

		Object* b = B_class.newInstance();

		Object* c = C_class.newInstance();

		Object* d = D_class.newInstance();

		Object* e = E_class.newInstance();

		Object* f = F_class.newInstance();

		Object* g = G_class.newInstance();

		Object* h = H_class.newInstance();

		Object* i = I_class.newInstance();

		Object* j = J_class.newInstance();

		Object* k = K_class.newInstance();

		Object* l = L_class.newInstance();

		Object* m = M_class.newInstance();

		Object* n = N_class.newInstance();

		Object* o = O_class.newInstance();

		Object* p = P_class.newInstance();

		Object* q = Q_class.newInstance();

		Object* r = R_class.newInstance();

		Object* s = S_class.newInstance();

		Object* t = T_class.newInstance();

		Object* u = U_class.newInstance();

		Object* v = V_class.newInstance();

		Object* w = W_class.newInstance();

		Object* x = X_class.newInstance();

		Object* y = Y_class.newInstance();

		Object* z = Z_class.newInstance();

		Class::setAccessible( true );
		Field ferrari = X_class.getField( "Ferrari" );
		Field lexus = Z_class.getField( "Lexus" );

		ferrari.setInt( y , 777 );
		throwOnFalse( X_class.getField( "Ferrari" ).getInt( x ) == 777 , "" );
		lexus.setInt( p , 50 );
		std::list<Field> a_list = A_class.getFields();
		std::list<Field> c_list = C_class.getFields();
		std::list<Field> q_list = Q_class.getFields();
		std::list<Field> s_list = S_class.getFields();

		q_list.front().setInt( y , 550 );
		throwOnFalse( ferrari.getInt( x ) == 550 , "" );

		throwOnFalse( a_list.size() == 2 , "a_list.size()==2" );
		throwOnFalse( c_list.size() == 0 , "c_list.size()==0" );
		throwOnFalse( q_list.size() == 3 , "q_list.size()==3" );
		throwOnFalse( s_list.size() == 3 , "s_list.size()==3" );

		bool found;

		found = false;
		for ( Field field : a_list ) {
			if ( field.name().compare( "Lexus" ) == 0 )
				found = true;
		}
		throwOnFalse( found , "a_list:found" );

		found = false;
		for ( Field field : c_list ) {
			if ( field.name().compare( "Lexus" ) == 0 )
				found = true; // SHOULDN'T FIND LEXUS, TOO expensive :(
		}
		throwOnFalse( !found , "c_list:!found" ); // On purpose ^^

		found = false;
		for ( Field field : q_list ) {
			if ( field.name().compare( "Lexus" ) == 0 )
				found = true;
		}
		throwOnFalse( found , "q_list:found" );

		found = false;
		for ( Field field : q_list ) {
			if ( field.name().compare( "Ferrari" ) == 0 )
				found = true;
		}
		throwOnFalse( found , "q_list:found" );

		found = false;
		for ( Field field : s_list ) {
			if ( field.name().compare( "Lexus" ) == 0 )
				found = true;
		}
		throwOnFalse( found , "s_list:found" );

		found = false;
		for ( Field field : s_list ) {
			if ( field.name().compare( "Ferrari" ) == 0 )
				found = true;
		}
		throwOnFalse( found , "s_list:found" );

	}
	catch ( std::exception& e ) {
		std::cout << e.what() << std::endl;
		return false;
	}
	return true;
}
bool testClassGetMethods() {
	try {
		Class A_class( nullptr , "A" );
		A_class.addMethod( "setThree" , setThree );
		Class B_class( &A_class , "B" );
		Class C_class( nullptr , "C" );
		Class D_class( nullptr , "D" );
		Class E_class( &A_class , "E" );
		Class F_class( &B_class , "F" );
		F_class.addMethod( "setNullptr" , setNullptr );
		Class G_class( &F_class , "G" );
		Class H_class( nullptr , "H" );
		Class I_class( &D_class , "I" );
		Class J_class( nullptr , "J" );
		Class K_class( nullptr , "K" );
		Class L_class( &A_class , "L" );
		Class M_class( &B_class , "M" );
		Class N_class( &F_class , "N" );
		Class O_class( &A_class , "O" );
		Class P_class( &N_class , "P" );
		Class Q_class( &P_class , "Q" );
		Class R_class( &Q_class , "R" );
		Class S_class( &R_class , "S" );
		Class T_class( &S_class , "T" );
		Class U_class( &T_class , "U" );
		Class V_class( &U_class , "V" );
		Class W_class( &V_class , "W" );
		Class X_class( &W_class , "X" );
		Class Y_class( &X_class , "Y" );
		Class Z_class( &Y_class , "Z" );

		Object* a = A_class.newInstance();
		Object* b = B_class.newInstance();
		Object* c = C_class.newInstance();
		Object* d = D_class.newInstance();
		Object* e = E_class.newInstance();
		Object* f = F_class.newInstance();
		Object* g = G_class.newInstance();
		Object* h = H_class.newInstance();
		Object* i = I_class.newInstance();
		Object* j = J_class.newInstance();
		Object* k = K_class.newInstance();
		Object* l = L_class.newInstance();
		Object* m = M_class.newInstance();
		Object* n = N_class.newInstance();
		Object* o = O_class.newInstance();
		Object* p = P_class.newInstance();
		Object* q = Q_class.newInstance();
		Object* r = R_class.newInstance();
		Object* s = S_class.newInstance();
		Object* t = T_class.newInstance();
		Object* u = U_class.newInstance();
		Object* v = V_class.newInstance();
		Object* w = W_class.newInstance();
		Object* x = X_class.newInstance();
		Object* y = Y_class.newInstance();
		Object* z = Z_class.newInstance();
		Class::setAccessible( true );
		Method three = X_class.getMethod( "setThree" );
		Method null = Z_class.getMethod( "setNullptr" );

		std::list<Method> a_list = A_class.getMethods();
		std::list<Method> c_list = C_class.getMethods();
		std::list<Method> q_list = Q_class.getMethods();
		std::list<Method> s_list = S_class.getMethods();

		throwOnFalse( a_list.size() == 1 , "a_list.size()==1" );
		throwOnFalse( c_list.size() == 0 , "c_list.size()==0" );
		throwOnFalse( q_list.size() == 2 , "q_list.size()==2" );
		throwOnFalse( s_list.size() == 2 , "s_list.size()==2" );

		bool found;

		found = false;
		for ( Method method : a_list ) {
			if ( method.name().compare( "setThree" ) == 0 )
				found = true;
		}
		throwOnFalse( found , "a_list:found" );

		found = false;
		for ( Method method : c_list ) {
			if ( method.name().compare( "setThree" ) == 0 )
				found = true; // SHOULDN'T FIND LEXUS, TOO expensive :(
		}
		throwOnFalse( !found , "c_list:!found" ); // On purpose ^^

		found = false;
		for ( Method method : q_list ) {
			if ( method.name().compare( "setThree" ) == 0 )
				found = true;
		}
		throwOnFalse( found , "q_list:found" );

		found = false;
		for ( Method method : q_list ) {
			if ( method.name().compare( "setNullptr" ) == 0 )
				found = true;
		}
		throwOnFalse( found , "q_list:found" );

		found = false;
		for ( Method method : s_list ) {
			if ( method.name().compare( "setThree" ) == 0 )
				found = true;
		}
		throwOnFalse( found , "s_list:found" );

		found = false;
		for ( Method method : s_list ) {
			if ( method.name().compare( "setNullptr" ) == 0 )
				found = true;
		}
		throwOnFalse( found , "s_list:found" );

	}
	catch ( std::exception& e ) {
		std::cout << e.what() << std::endl;
		return false;
	}
	return true;

}
bool testClassGetInt() {
	try {
		Class A_class( nullptr , "A" );
		A_class.addStaticField( "ABC" , INT );
		Class B_class( &A_class , "B" );
		Class C_class( nullptr , "C" );
		Class D_class( nullptr , "D" );
		Class E_class( &A_class , "E" );
		Class F_class( &B_class , "F" );
		Class G_class( &F_class , "G" );
		Class H_class( nullptr , "H" );
		Class I_class( &D_class , "I" );
		Class J_class( nullptr , "J" );
		Class K_class( nullptr , "K" );
		Class L_class( &A_class , "L" );
		Class M_class( &B_class , "M" );
		Class N_class( &F_class , "N" );
		Class O_class( &A_class , "O" );
		O_class.addStaticField( "OM_OBJECT" , OBJECT );
		Class P_class( &O_class , "P" );
		Class Q_class( &P_class , "Q" );
		Class R_class( &Q_class , "R" );
		Class S_class( &R_class , "S" );
		Class T_class( &S_class , "T" );
		Class U_class( &T_class , "U" );
		Class V_class( &U_class , "V" );
		Class W_class( &V_class , "W" );
		Class X_class( &W_class , "X" );
		Class Y_class( &X_class , "Y" );
		Class Z_class( &Y_class , "Z" );

		Object* a = A_class.newInstance();
		Object* b = B_class.newInstance();
		Object* c = C_class.newInstance();
		Object* d = D_class.newInstance();
		Object* e = E_class.newInstance();
		Object* f = F_class.newInstance();
		Object* g = G_class.newInstance();
		Object* h = H_class.newInstance();
		Object* i = I_class.newInstance();
		Object* j = J_class.newInstance();
		Object* k = K_class.newInstance();
		Object* l = L_class.newInstance();
		Object* m = M_class.newInstance();
		Object* n = N_class.newInstance();
		Object* o = O_class.newInstance();
		Object* p = P_class.newInstance();
		Object* q = Q_class.newInstance();
		Object* r = R_class.newInstance();
		Object* s = S_class.newInstance();
		Object* t = T_class.newInstance();
		Object* u = U_class.newInstance();
		Object* v = V_class.newInstance();
		Object* w = W_class.newInstance();
		Object* x = X_class.newInstance();
		Object* y = Y_class.newInstance();
		Object* z = Z_class.newInstance();

		try {

			k->getClass()->getInt( "abra-kadbra" );
			return false; //
		}
		catch ( FieldNotFound& e ) {

		}
		catch ( std::exception& e ) {
			std::cout << e.what() << std::endl;
			return false;

		}

		try {

			i->getClass()->getInt( "ABC" );
			return false; //
		}
		catch ( FieldNotFound& e ) {

		}
		catch ( std::exception& e ) {
			std::cout << e.what() << std::endl;
			return false;

		}

		try {

			c->getClass()->getInt( "ABC" );
			return false; //
		}
		catch ( FieldNotFound& e ) {

		}
		catch ( std::exception& e ) {
			std::cout << e.what() << std::endl;
			return false;

		}

		try {

			o->getClass()->getInt( "OM_OBJECT" );
			return false; //
		}
		catch ( TypeError& e ) {

		}
		catch ( std::exception& e ) {
			std::cout << e.what() << std::endl;
			return false;

		}

		try {

			w->getClass()->getInt( "OM_OBJECT" );
			return false; //
		}
		catch ( TypeError& e ) {

		}
		catch ( std::exception& e ) {
			std::cout << e.what() << std::endl;
			return false;

		}

		try {

			x->getClass()->getInt( "OM_OBJECT" );
			return false; //
		}
		catch ( TypeError& e ) {

		}
		catch ( std::exception& e ) {
			std::cout << e.what() << std::endl;
			return false;

		}

		try {

			y->getClass()->getInt( "OM_OBJECT" );
			return false; //
		}
		catch ( TypeError& e ) {

		}
		catch ( std::exception& e ) {
			std::cout << e.what() << std::endl;
			return false;

		}

		try {

			z->getClass()->getInt( "OM_OBJECT" );
			return false; //
		}
		catch ( TypeError& e ) {

		}
		catch ( std::exception& e ) {
			std::cout << e.what() << std::endl;
			return false;

		}

		try {

			throwOnFalse( f->getClass()->getInt( "ABC" ) == 0 ,
				"f->getClass()->getInt('ABC')==0" );

		}
		catch ( FieldNotFound& e ) {
			std::cout << e.what() << std::endl;
			return false;

		}
		catch ( std::exception& e ) {
			std::cout << e.what() << std::endl;
			return false;

		}
	}
	catch ( std::exception& e ) {
		std::cout << e.what() << std::endl;
		return false;
	}
	return true;

}
bool testClassGetObj() {
	try {
		Class A_class( nullptr , "A" );
		A_class.addStaticField( "ABC" , OBJECT );
		Class B_class( &A_class , "B" );
		Class C_class( nullptr , "C" );
		Class D_class( nullptr , "D" );
		Class E_class( &A_class , "E" );
		Class F_class( &B_class , "F" );
		Class G_class( &F_class , "G" );
		Class H_class( nullptr , "H" );
		Class I_class( &D_class , "I" );
		Class J_class( nullptr , "J" );
		Class K_class( nullptr , "K" );
		Class L_class( &A_class , "L" );
		Class M_class( &B_class , "M" );
		Class N_class( &F_class , "N" );
		Class O_class( &A_class , "O" );
		O_class.addStaticField( "OM_INT" , INT );
		Class P_class( &O_class , "P" );
		Class Q_class( &P_class , "Q" );
		Class R_class( &Q_class , "R" );
		Class S_class( &R_class , "S" );
		Class T_class( &S_class , "T" );
		Class U_class( &T_class , "U" );
		Class V_class( &U_class , "V" );
		Class W_class( &V_class , "W" );
		Class X_class( &W_class , "X" );
		Class Y_class( &X_class , "Y" );
		Class Z_class( &Y_class , "Z" );

		Object* a = A_class.newInstance();
		Object* b = B_class.newInstance();
		Object* c = C_class.newInstance();
		Object* d = D_class.newInstance();
		Object* e = E_class.newInstance();
		Object* f = F_class.newInstance();
		Object* g = G_class.newInstance();
		Object* h = H_class.newInstance();
		Object* i = I_class.newInstance();
		Object* j = J_class.newInstance();
		Object* k = K_class.newInstance();
		Object* l = L_class.newInstance();
		Object* m = M_class.newInstance();
		Object* n = N_class.newInstance();
		Object* o = O_class.newInstance();
		Object* p = P_class.newInstance();
		Object* q = Q_class.newInstance();
		Object* r = R_class.newInstance();
		Object* s = S_class.newInstance();
		Object* t = T_class.newInstance();
		Object* u = U_class.newInstance();
		Object* v = V_class.newInstance();
		Object* w = W_class.newInstance();
		Object* x = X_class.newInstance();
		Object* y = Y_class.newInstance();
		Object* z = Z_class.newInstance();

		try {

			k->getClass()->getObj( "abra-kadbra" );
			return false; //
		}
		catch ( FieldNotFound& e ) {

		}
		catch ( std::exception& e ) {
			std::cout << e.what() << std::endl;
			return false;

		}

		try {

			i->getClass()->getObj( "ABC" );
			return false; //
		}
		catch ( FieldNotFound& e ) {

		}
		catch ( std::exception& e ) {
			std::cout << e.what() << std::endl;
			return false;

		}

		try {

			c->getClass()->getObj( "ABC" );
			return false; //
		}
		catch ( FieldNotFound& e ) {

		}
		catch ( std::exception& e ) {
			std::cout << e.what() << std::endl;
			return false;

		}

		try {

			o->getClass()->getObj( "OM_INT" );
			return false; //
		}
		catch ( TypeError& e ) {

		}
		catch ( std::exception& e ) {
			std::cout << e.what() << std::endl;
			return false;

		}

		try {

			w->getClass()->getObj( "OM_INT" );
			return false; //
		}
		catch ( TypeError& e ) {

		}
		catch ( std::exception& e ) {
			std::cout << e.what() << std::endl;
			return false;

		}

		try {

			x->getClass()->getObj( "OM_INT" );
			return false; //
		}
		catch ( TypeError& e ) {

		}
		catch ( std::exception& e ) {
			std::cout << e.what() << std::endl;
			return false;

		}

		try {

			y->getClass()->getObj( "OM_INT" );
			return false; //
		}
		catch ( TypeError& e ) {

		}
		catch ( std::exception& e ) {
			std::cout << e.what() << std::endl;
			return false;

		}

		try {

			z->getClass()->getObj( "OM_INT" );
			return false; //
		}
		catch ( TypeError& e ) {

		}
		catch ( std::exception& e ) {
			std::cout << e.what() << std::endl;
			return false;

		}

		try {

			throwOnFalse( f->getClass()->getObj( "ABC" ) == nullptr ,
				"f->getClass()->getObj('ABC')==nullptr" );

		}
		catch ( FieldNotFound& e ) {
			std::cout << e.what() << std::endl;
			return false;

		}
		catch ( std::exception& e ) {
			std::cout << e.what() << std::endl;
			return false;

		}
	}
	catch ( std::exception& e ) {
		std::cout << e.what() << std::endl;
		return false;
	}
	return true;

}
bool testClassSetInt() {
	try {
		Class A_class( nullptr , "A" );
		A_class.addStaticField( "ABC" , INT );
		Class B_class( &A_class , "B" );
		Class C_class( nullptr , "C" );
		Class D_class( nullptr , "D" );
		Class E_class( &A_class , "E" );
		Class F_class( &B_class , "F" );
		Class G_class( &F_class , "G" );
		Class H_class( nullptr , "H" );
		Class I_class( &D_class , "I" );
		Class J_class( nullptr , "J" );
		Class K_class( nullptr , "K" );
		Class L_class( &A_class , "L" );
		Class M_class( &B_class , "M" );
		Class N_class( &F_class , "N" );
		Class O_class( &A_class , "O" );
		O_class.addStaticField( "OM_OBJECT" , OBJECT );
		Class P_class( &O_class , "P" );
		Class Q_class( &P_class , "Q" );
		Class R_class( &Q_class , "R" );
		Class S_class( &R_class , "S" );
		Class T_class( &S_class , "T" );
		Class U_class( &T_class , "U" );
		Class V_class( &U_class , "V" );
		Class W_class( &V_class , "W" );
		Class X_class( &W_class , "X" );
		Class Y_class( &X_class , "Y" );
		Class Z_class( &Y_class , "Z" );

		Object* a = A_class.newInstance();

		Object* b = B_class.newInstance();

		Object* c = C_class.newInstance();

		Object* d = D_class.newInstance();

		Object* e = E_class.newInstance();

		Object* f = F_class.newInstance();

		Object* g = G_class.newInstance();

		Object* h = H_class.newInstance();

		Object* i = I_class.newInstance();

		Object* j = J_class.newInstance();

		Object* k = K_class.newInstance();

		Object* l = L_class.newInstance();

		Object* m = M_class.newInstance();

		Object* n = N_class.newInstance();

		Object* o = O_class.newInstance();

		Object* p = P_class.newInstance();

		Object* q = Q_class.newInstance();

		Object* r = R_class.newInstance();

		Object* s = S_class.newInstance();

		Object* t = T_class.newInstance();

		Object* u = U_class.newInstance();

		Object* v = V_class.newInstance();

		Object* w = W_class.newInstance();

		Object* x = X_class.newInstance();

		Object* y = Y_class.newInstance();

		Object* z = Z_class.newInstance();

		try {

			k->getClass()->setInt( "abra-kadbra" , 1 );
			return false; //
		}
		catch ( FieldNotFound& e ) {

		}
		catch ( std::exception& e ) {
			std::cout << e.what() << std::endl;
			return false;

		}

		try {

			i->getClass()->setInt( "ABC" , 2 );
			return false; //
		}
		catch ( FieldNotFound& e ) {

		}
		catch ( std::exception& e ) {
			std::cout << e.what() << std::endl;
			return false;

		}

		try {

			c->getClass()->setInt( "ABC" , 3 );
			return false; //
		}
		catch ( FieldNotFound& e ) {

		}
		catch ( std::exception& e ) {
			std::cout << e.what() << std::endl;
			return false;

		}

		try {

			o->getClass()->setInt( "OM_OBJECT" , 4 );
			return false; //
		}
		catch ( TypeError& e ) {

		}
		catch ( std::exception& e ) {
			std::cout << e.what() << std::endl;
			return false;

		}

		try {

			w->getClass()->setInt( "OM_OBJECT" , 5 );
			return false; //
		}
		catch ( TypeError& e ) {

		}
		catch ( std::exception& e ) {
			std::cout << e.what() << std::endl;
			return false;

		}

		try {

			x->getClass()->setInt( "OM_OBJECT" , 6 );
			return false; //
		}
		catch ( TypeError& e ) {

		}
		catch ( std::exception& e ) {
			std::cout << e.what() << std::endl;
			return false;

		}

		try {

			y->getClass()->setInt( "OM_OBJECT" , 7 );
			return false; //
		}
		catch ( TypeError& e ) {

		}
		catch ( std::exception& e ) {
			std::cout << e.what() << std::endl;
			return false;

		}

		try {

			z->getClass()->setInt( "OM_OBJECT" , 8 );
			return false; //
		}
		catch ( TypeError& e ) {

		}
		catch ( std::exception& e ) {
			std::cout << e.what() << std::endl;
			return false;

		}

		try {
			f->getClass()->setInt( "ABC" , 9 );
			throwOnFalse( v->getClass()->getInt( "ABC" ) == 9 ,
				"v->getClass()->getInt('ABC')==9" );

		}
		catch ( FieldNotFound& e ) {
			std::cout << e.what() << std::endl;
			return false;

		}
		catch ( std::exception& e ) {
			std::cout << e.what() << std::endl;
			return false;

		}
	}
	catch ( std::exception& e ) {
		std::cout << e.what() << std::endl;
		return false;
	}
	return true;
}
bool testClassSetObj() {
	try {
		Class A_class( nullptr , "A" );
		A_class.addStaticField( "ABC" , OBJECT );
		Class B_class( &A_class , "B" );
		Class C_class( nullptr , "C" );
		Class D_class( nullptr , "D" );
		Class E_class( &A_class , "E" );
		Class F_class( &B_class , "F" );
		Class G_class( &F_class , "G" );
		Class H_class( nullptr , "H" );
		Class I_class( &D_class , "I" );
		Class J_class( nullptr , "J" );
		Class K_class( nullptr , "K" );
		Class L_class( &A_class , "L" );
		Class M_class( &B_class , "M" );
		Class N_class( &F_class , "N" );
		Class O_class( &A_class , "O" );
		O_class.addStaticField( "OM_INT" , INT );
		Class P_class( &O_class , "P" );
		Class Q_class( &P_class , "Q" );
		Class R_class( &Q_class , "R" );
		Class S_class( &R_class , "S" );
		Class T_class( &S_class , "T" );
		Class U_class( &T_class , "U" );
		Class V_class( &U_class , "V" );
		Class W_class( &V_class , "W" );
		Class X_class( &W_class , "X" );
		Class Y_class( &X_class , "Y" );
		Class Z_class( &Y_class , "Z" );

		Object* a = A_class.newInstance();

		Object* b = B_class.newInstance();

		Object* c = C_class.newInstance();

		Object* d = D_class.newInstance();

		Object* e = E_class.newInstance();

		Object* f = F_class.newInstance();

		Object* g = G_class.newInstance();

		Object* h = H_class.newInstance();

		Object* i = I_class.newInstance();

		Object* j = J_class.newInstance();

		Object* k = K_class.newInstance();

		Object* l = L_class.newInstance();

		Object* m = M_class.newInstance();

		Object* n = N_class.newInstance();

		Object* o = O_class.newInstance();

		Object* p = P_class.newInstance();

		Object* q = Q_class.newInstance();

		Object* r = R_class.newInstance();

		Object* s = S_class.newInstance();

		Object* t = T_class.newInstance();

		Object* u = U_class.newInstance();

		Object* v = V_class.newInstance();

		Object* w = W_class.newInstance();

		Object* x = X_class.newInstance();

		Object* y = Y_class.newInstance();

		Object* z = Z_class.newInstance();

		try {

			k->getClass()->setObj( "abra-kadbra" , a );
			return false; //
		}
		catch ( FieldNotFound& e ) {

		}
		catch ( std::exception& e ) {
			std::cout << e.what() << std::endl;
			return false;

		}

		try {

			i->getClass()->setObj( "ABC" , b );
			return false; //
		}
		catch ( FieldNotFound& e ) {

		}
		catch ( std::exception& e ) {
			std::cout << e.what() << std::endl;
			return false;

		}

		try {

			c->getClass()->setObj( "ABC" , c );
			return false; //
		}
		catch ( FieldNotFound& e ) {

		}
		catch ( std::exception& e ) {
			std::cout << e.what() << std::endl;
			return false;

		}

		try {

			o->getClass()->setObj( "OM_INT" , d );
			return false; //
		}
		catch ( TypeError& e ) {

		}
		catch ( std::exception& e ) {
			std::cout << e.what() << std::endl;
			return false;

		}

		try {

			w->getClass()->setObj( "OM_INT" , e );
			return false; //
		}
		catch ( TypeError& e ) {

		}
		catch ( std::exception& e ) {
			std::cout << e.what() << std::endl;
			return false;

		}

		try {

			x->getClass()->setObj( "OM_INT" , f );
			return false; //
		}
		catch ( TypeError& e ) {

		}
		catch ( std::exception& e ) {
			std::cout << e.what() << std::endl;
			return false;

		}

		try {

			y->getClass()->setObj( "OM_INT" , g );
			return false; //
		}
		catch ( TypeError& e ) {

		}
		catch ( std::exception& e ) {
			std::cout << e.what() << std::endl;
			return false;

		}

		try {

			z->getClass()->setObj( "OM_INT" , h );
			return false; //
		}
		catch ( TypeError& e ) {

		}
		catch ( std::exception& e ) {
			std::cout << e.what() << std::endl;
			return false;

		}

		try {

			w->setObj( "ABC" , i );
			throwOnFalse( x->getClass()->getObj( "ABC" ) == i ,
				"x->getClass()->getObj('ABC')==i" );

		}
		catch ( FieldNotFound& e ) {
			std::cout << e.what() << std::endl;
			return false;

		}
		catch ( std::exception& e ) {
			std::cout << e.what() << std::endl;
			return false;

		}
	}
	catch ( std::exception& e ) {
		std::cout << e.what() << std::endl;
		return false;
	}
	return true;

}
bool testClassGetSuperClass() {
	try {
		Class A_class( nullptr , "A" );
		Class B_class( &A_class , "B" );
		Class C_class( nullptr , "C" );
		Class D_class( nullptr , "D" );
		Class E_class( &A_class , "E" );
		Class F_class( &B_class , "F" );
		Class G_class( &F_class , "G" );
		Class H_class( nullptr , "H" );
		Class I_class( &D_class , "I" );
		Class J_class( nullptr , "J" );
		Class K_class( nullptr , "K" );
		Class L_class( &A_class , "L" );
		Class M_class( &B_class , "M" );
		Class N_class( &F_class , "N" );
		Class O_class( &A_class , "O" );
		Class P_class( &N_class , "P" );
		Class Q_class( &P_class , "Q" );
		Class R_class( &Q_class , "R" );
		Class S_class( &R_class , "S" );
		Class T_class( &S_class , "T" );
		Class U_class( &T_class , "U" );
		Class V_class( &U_class , "V" );
		Class W_class( &V_class , "W" );
		Class X_class( &W_class , "X" );
		Class Y_class( &X_class , "Y" );
		Class Z_class( &Y_class , "Z" );

		Object* a = A_class.newInstance();
		Object* b = B_class.newInstance();
		Object* c = C_class.newInstance();
		Object* d = D_class.newInstance();
		Object* e = E_class.newInstance();
		Object* f = F_class.newInstance();
		Object* g = G_class.newInstance();
		Object* h = H_class.newInstance();
		Object* i = I_class.newInstance();
		Object* j = J_class.newInstance();
		Object* k = K_class.newInstance();
		Object* l = L_class.newInstance();
		Object* m = M_class.newInstance();
		Object* n = N_class.newInstance();
		Object* o = O_class.newInstance();
		Object* p = P_class.newInstance();
		Object* q = Q_class.newInstance();
		Object* r = R_class.newInstance();
		Object* s = S_class.newInstance();
		Object* t = T_class.newInstance();
		Object* u = U_class.newInstance();
		Object* v = V_class.newInstance();
		Object* w = W_class.newInstance();
		Object* x = X_class.newInstance();
		Object* y = Y_class.newInstance();
		Object* z = Z_class.newInstance();

		throwOnFalse( a->getClass()->getSuperClass() == nullptr ,
			"a->getClass()->getSuperClass()==nullptr" );
		throwOnFalse( b->getClass()->getSuperClass()->name().compare( "A" ) == 0 ,
			"b->getClass()->getSuperClass()->name().compare('A')==0" );
		throwOnFalse( c->getClass()->getSuperClass() == nullptr ,
			"c->getClass()->getSuperClass()==nullptr" );
		throwOnFalse( d->getClass()->getSuperClass() == nullptr ,
			"d->getClass()->getSuperClass()==nullptr" );
		throwOnFalse( e->getClass()->getSuperClass()->name().compare( "A" ) == 0 ,
			"e->getClass()->getSuperClass()->name().compare('A')==0" );
		throwOnFalse( f->getClass()->getSuperClass()->name().compare( "B" ) == 0 ,
			"f->getClass()->getSuperClass()->name().compare('B')==0" );
		throwOnFalse( g->getClass()->getSuperClass()->name().compare( "F" ) == 0 ,
			"g->getClass()->getSuperClass()->name().compare('F')==0" );
		throwOnFalse( h->getClass()->getSuperClass() == nullptr ,
			"h->getClass()->getSuperClass()==nullptr" );
		throwOnFalse( i->getClass()->getSuperClass()->name().compare( "D" ) == 0 ,
			"i->getClass()->getSuperClass()->name().compare('D')==0" );
		throwOnFalse( j->getClass()->getSuperClass() == nullptr ,
			"j->getClass()->getSuperClass()==nullptr" );
		throwOnFalse( k->getClass()->getSuperClass() == nullptr ,
			"k->getClass()->getSuperClass()==nullptr" );
		throwOnFalse( l->getClass()->getSuperClass()->name().compare( "A" ) == 0 ,
			"l->getClass()->getSuperClass()->name().compare('A')==0" );
		throwOnFalse( m->getClass()->getSuperClass()->name().compare( "B" ) == 0 ,
			"m->getClass()->getSuperClass()->name().compare('B')==0" );
		throwOnFalse( n->getClass()->getSuperClass()->name().compare( "F" ) == 0 ,
			"n->getClass()->getSuperClass()->name().compare('F')==0" );
		throwOnFalse( o->getClass()->getSuperClass()->name().compare( "A" ) == 0 ,
			"o->getClass()->getSuperClass()->name().compare('A')==0" );
		throwOnFalse( p->getClass()->getSuperClass()->name().compare( "N" ) == 0 ,
			"p->getClass()->getSuperClass()->name().compare('N')==0" );
		throwOnFalse( q->getClass()->getSuperClass()->name().compare( "P" ) == 0 ,
			"q->getClass()->getSuperClass()->name().compare('P')==0" );
		throwOnFalse( r->getClass()->getSuperClass()->name().compare( "Q" ) == 0 ,
			"r->getClass()->getSuperClass()->name().compare('Q')==0" );
		throwOnFalse( s->getClass()->getSuperClass()->name().compare( "R" ) == 0 ,
			"s->getClass()->getSuperClass()->name().compare('R')==0" );
		throwOnFalse( t->getClass()->getSuperClass()->name().compare( "S" ) == 0 ,
			"t->getClass()->getSuperClass()->name().compare('S')==0" );
		throwOnFalse( u->getClass()->getSuperClass()->name().compare( "T" ) == 0 ,
			"u->getClass()->getSuperClass()->name().compare('T')==0" );
		throwOnFalse( v->getClass()->getSuperClass()->name().compare( "U" ) == 0 ,
			"v->getClass()->getSuperClass()->name().compare('U')==0" );
		throwOnFalse( w->getClass()->getSuperClass()->name().compare( "V" ) == 0 ,
			"w->getClass()->getSuperClass()->name().compare('V')==0" );
		throwOnFalse( x->getClass()->getSuperClass()->name().compare( "W" ) == 0 ,
			"x->getClass()->getSuperClass()->name().compare('W')==0" );
		throwOnFalse( y->getClass()->getSuperClass()->name().compare( "X" ) == 0 ,
			"y->getClass()->getSuperClass()->name().compare('X')==0" );
		throwOnFalse( z->getClass()->getSuperClass()->name().compare( "Y" ) == 0 ,
			"z->getClass()->getSuperClass()->name().compare('Y')==0" );
	}
	catch ( std::exception& e ) {
		std::cout << e.what() << std::endl;
		return false;
	}
	return true;

}

bool testClassSetAccessibleTrueGetInt() {
	try {
		Class::setAccessible( true );
		Class A_class( nullptr , "A" );
		A_class.addStaticField( "Lexus" , OBJECT );
		A_class.addStaticField( "Buggati" , INT );
		A_class.addInstanceField( "Audi" , INT );
		A_class.addInstanceField( "BMW" , OBJECT );

		Class B_class( &A_class , "B" );
		Class C_class( nullptr , "C" );
		Class D_class( nullptr , "D" );
		D_class.addStaticField( "Suzuki" , INT );
		D_class.addStaticField( "PORSCHE" , OBJECT );
		D_class.addInstanceField( "Honda" , INT );
		D_class.addInstanceField( "Mercedes" , OBJECT );

		Class E_class( &A_class , "E" );
		Class F_class( &B_class , "F" );
		Class G_class( &F_class , "G" );
		Class H_class( nullptr , "H" );
		Class I_class( &D_class , "I" );
		Class J_class( nullptr , "J" );
		Class K_class( nullptr , "K" );
		Class L_class( &A_class , "L" );
		Class M_class( &B_class , "M" );
		Class N_class( &F_class , "N" );
		Class O_class( &A_class , "O" );
		Class P_class( &N_class , "P" );
		Class Q_class( &P_class , "Q" );
		Class R_class( &Q_class , "R" );
		Class S_class( &R_class , "S" );
		Class T_class( &S_class , "T" );
		Class U_class( &T_class , "U" );
		Class V_class( &U_class , "V" );
		Class W_class( &V_class , "W" );
		Class X_class( &W_class , "X" );
		Class Y_class( &X_class , "Y" );
		Class Z_class( &Y_class , "Z" );

		Object* a = A_class.newInstance();
		Object* b = B_class.newInstance();
		Object* c = C_class.newInstance();
		Object* d = D_class.newInstance();
		Object* e = E_class.newInstance();
		Object* f = F_class.newInstance();
		Object* g = G_class.newInstance();
		Object* h = H_class.newInstance();
		Object* i = I_class.newInstance();
		Object* j = J_class.newInstance();
		Object* k = K_class.newInstance();
		Object* l = L_class.newInstance();
		Object* m = M_class.newInstance();
		Object* n = N_class.newInstance();
		Object* o = O_class.newInstance();
		Object* p = P_class.newInstance();
		Object* q = Q_class.newInstance();
		Object* r = R_class.newInstance();
		Object* s = S_class.newInstance();
		Object* t = T_class.newInstance();
		Object* u = U_class.newInstance();
		Object* v = V_class.newInstance();
		Object* w = W_class.newInstance();
		Object* x = X_class.newInstance();
		Object* y = Y_class.newInstance();
		Object* z = Z_class.newInstance();

		Class::setAccessible( false );
		Class::setAccessible( true );

		try {
			throwOnFalse( x->getInt( "Buggati" ) == 0 , "x->getInt('Buggati')==0" );
		}
		catch ( TypeError& ex ) {
			std::cout << ex.what() << std::endl;
			return false;
		}
		catch ( FieldNotFound& ex ) {
			std::cout << ex.what() << std::endl;
			return false;
		}
		catch ( FieldNotAccessible& ex ) {
			std::cout << ex.what() << std::endl;
			return false;
		}

		try {
			throwOnFalse( x->getInt( "Lexus" ) == 0 , "x->getInt('Lexus')==0" );
			return false;
		}
		catch ( TypeError& ex ) {

		}
		catch ( FieldNotFound& ex ) {
			std::cout << ex.what() << std::endl;
			return false;
		}
		catch ( FieldNotAccessible& ex ) {
			std::cout << ex.what() << std::endl;
			return false;
		}

		try {
			throwOnFalse( x->getInt( "Audi" ) == 0 , "x->getInt('Audi')==0" );
		}
		catch ( TypeError& ex ) {
			std::cout << ex.what() << std::endl;
			return false;
		}
		catch ( FieldNotFound& ex ) {
			std::cout << ex.what() << std::endl;
			return false;
		}
		catch ( FieldNotAccessible& ex ) {
			std::cout << ex.what() << std::endl;
			return false;
		}

		try {
			throwOnFalse( x->getInt( "BMW" ) == 0 , "x->getInt('BMW')==0" );
			return false;
		}
		catch ( TypeError& ex ) {

		}
		catch ( FieldNotFound& ex ) {
			std::cout << ex.what() << std::endl;
			return false;
		}
		catch ( FieldNotAccessible& ex ) {
			std::cout << ex.what() << std::endl;
			return false;
		}

		try {
			throwOnFalse( x->getInt( "Suzuki" ) == 0 , "x->getInt('Suzuki')==0" );
			return false;
		}
		catch ( TypeError& ex ) {
			std::cout << ex.what() << std::endl;
			return false;
		}
		catch ( FieldNotFound& ex ) {

		}
		catch ( FieldNotAccessible& ex ) {
			std::cout << ex.what() << std::endl;
			return false;
		}

		try {
			throwOnFalse( x->getInt( "PORSCHE" ) == 0 , "x->getInt('PORSCHE')==0" );
			return false;
		}
		catch ( TypeError& ex ) {
			std::cout << ex.what() << std::endl;
			return false;
		}
		catch ( FieldNotFound& ex ) {

		}
		catch ( FieldNotAccessible& ex ) {
			std::cout << ex.what() << std::endl;
			return false;
		}

		try {
			throwOnFalse( x->getInt( "Honda" ) == 0 , "x->getInt('Honda')==0" );
			return false;
		}
		catch ( TypeError& ex ) {
			std::cout << ex.what() << std::endl;
			return false;
		}
		catch ( FieldNotFound& ex ) {
		}
		catch ( FieldNotAccessible& ex ) {
			std::cout << ex.what() << std::endl;
			return false;
		}

		try {
			throwOnFalse( x->getInt( "Mercedes" ) == 0 ,
				"x->getInt('Mercedes')==0" );
			return false;
		}
		catch ( TypeError& ex ) {
			std::cout << ex.what() << std::endl;
			return false;
		}
		catch ( FieldNotFound& ex ) {

		}
		catch ( FieldNotAccessible& ex ) {
			std::cout << ex.what() << std::endl;
			return false;
		}

	}
	catch ( std::exception& e ) {
		std::cout << e.what() << std::endl;
		return false;
	}
	return true;

}

bool testClassSetAccessibleTrueGetObj() {
	try {
		Class::setAccessible( true );
		Class A_class( nullptr , "A" );
		A_class.addStaticField( "Lexus" , OBJECT );
		A_class.addStaticField( "Buggati" , INT );
		A_class.addInstanceField( "Audi" , INT );
		A_class.addInstanceField( "BMW" , OBJECT );

		Class B_class( &A_class , "B" );
		Class C_class( nullptr , "C" );
		Class D_class( nullptr , "D" );
		D_class.addStaticField( "Suzuki" , INT );
		D_class.addStaticField( "PORSCHE" , OBJECT );
		D_class.addInstanceField( "Honda" , INT );
		D_class.addInstanceField( "Mercedes" , OBJECT );

		Class E_class( &A_class , "E" );
		Class F_class( &B_class , "F" );
		Class G_class( &F_class , "G" );
		Class H_class( nullptr , "H" );
		Class I_class( &D_class , "I" );
		Class J_class( nullptr , "J" );
		Class K_class( nullptr , "K" );
		Class L_class( &A_class , "L" );
		Class M_class( &B_class , "M" );
		Class N_class( &F_class , "N" );
		Class O_class( &A_class , "O" );
		Class P_class( &N_class , "P" );
		Class Q_class( &P_class , "Q" );
		Class R_class( &Q_class , "R" );
		Class S_class( &R_class , "S" );
		Class T_class( &S_class , "T" );
		Class U_class( &T_class , "U" );
		Class V_class( &U_class , "V" );
		Class W_class( &V_class , "W" );
		Class X_class( &W_class , "X" );
		Class Y_class( &X_class , "Y" );
		Class Z_class( &Y_class , "Z" );

		Object* a = A_class.newInstance();
		Object* b = B_class.newInstance();
		Object* c = C_class.newInstance();
		Object* d = D_class.newInstance();
		Object* e = E_class.newInstance();
		Object* f = F_class.newInstance();
		Object* g = G_class.newInstance();
		Object* h = H_class.newInstance();
		Object* i = I_class.newInstance();
		Object* j = J_class.newInstance();
		Object* k = K_class.newInstance();
		Object* l = L_class.newInstance();
		Object* m = M_class.newInstance();
		Object* n = N_class.newInstance();
		Object* o = O_class.newInstance();
		Object* p = P_class.newInstance();
		Object* q = Q_class.newInstance();
		Object* r = R_class.newInstance();
		Object* s = S_class.newInstance();
		Object* t = T_class.newInstance();
		Object* u = U_class.newInstance();
		Object* v = V_class.newInstance();
		Object* w = W_class.newInstance();
		Object* x = X_class.newInstance();
		Object* y = Y_class.newInstance();
		Object* z = Z_class.newInstance();

		Class::setAccessible( false );
		Class::setAccessible( true );

		try {
			throwOnFalse( x->getObj( "Buggati" ) == nullptr ,
				"x->getObj('Buggati')==nullptr" );
			return false;
		}
		catch ( TypeError& ex ) {

		}
		catch ( FieldNotFound& ex ) {
			std::cout << ex.what() << std::endl;
			return false;
		}
		catch ( FieldNotAccessible& ex ) {
			std::cout << ex.what() << std::endl;
			return false;
		}

		try {
			throwOnFalse( x->getObj( "Lexus" ) == nullptr ,
				"x->getObj('Lexus')==nullptr" );
		}
		catch ( TypeError& ex ) {
			std::cout << ex.what() << std::endl;
			return false;

		}
		catch ( FieldNotFound& ex ) {
			std::cout << ex.what() << std::endl;
			return false;
		}
		catch ( FieldNotAccessible& ex ) {
			std::cout << ex.what() << std::endl;
			return false;
		}

		try {
			throwOnFalse( x->getObj( "Audi" ) == nullptr ,
				"x->getObj('Audi')==nullptr" );
			return false;
		}
		catch ( TypeError& ex ) {
		}
		catch ( FieldNotFound& ex ) {
			std::cout << ex.what() << std::endl;
			return false;
		}
		catch ( FieldNotAccessible& ex ) {
			std::cout << ex.what() << std::endl;
			return false;
		}

		try {
			throwOnFalse( x->getObj( "BMW" ) == nullptr ,
				"x->getObj('BMW')==nullptr" );
		}
		catch ( TypeError& ex ) {
			std::cout << ex.what() << std::endl;
			return false;

		}
		catch ( FieldNotFound& ex ) {
			std::cout << ex.what() << std::endl;
			return false;
		}
		catch ( FieldNotAccessible& ex ) {
			std::cout << ex.what() << std::endl;
			return false;
		}

		try {
			throwOnFalse( x->getObj( "Suzuki" ) == nullptr ,
				"x->getObj('Suzuki')==nullptr" );
			return false;
		}
		catch ( TypeError& ex ) {
			std::cout << ex.what() << std::endl;
			return false;

		}
		catch ( FieldNotFound& ex ) {

		}
		catch ( FieldNotAccessible& ex ) {
			std::cout << ex.what() << std::endl;
			return false;
		}

		try {
			throwOnFalse( x->getObj( "PORSCHE" ) == nullptr ,
				"x->getObj('PORSCHE')==nullptr" );
			return false;
		}
		catch ( TypeError& ex ) {
			std::cout << ex.what() << std::endl;
			return false;

		}
		catch ( FieldNotFound& ex ) {
		}
		catch ( FieldNotAccessible& ex ) {
			std::cout << ex.what() << std::endl;
			return false;
		}

		try {
			throwOnFalse( x->getObj( "Honda" ) == nullptr ,
				"x->getObj('Honda')==nullptr" );
			return false;
		}
		catch ( TypeError& ex ) {
			std::cout << ex.what() << std::endl;
			return false;

		}
		catch ( FieldNotFound& ex ) {
		}
		catch ( FieldNotAccessible& ex ) {
			std::cout << ex.what() << std::endl;
			return false;
		}

		try {
			throwOnFalse( x->getObj( "Mercedes" ) == nullptr ,
				"x->getObj('Mercedes')==nullptr" );
			return false;
		}
		catch ( TypeError& ex ) {
			std::cout << ex.what() << std::endl;
			return false;

		}
		catch ( FieldNotFound& ex ) {
		}
		catch ( FieldNotAccessible& ex ) {
			std::cout << ex.what() << std::endl;
			return false;
		}

	}
	catch ( std::exception& e ) {
		std::cout << e.what() << std::endl;
		return false;
	}
	return true;

}

bool testClassSetAccessibleTrueSetInt() {
	try {
		Class::setAccessible( true );
		Class A_class( nullptr , "A" );
		A_class.addStaticField( "Lexus" , OBJECT );
		A_class.addStaticField( "Buggati" , INT );
		A_class.addInstanceField( "Audi" , INT );
		A_class.addInstanceField( "BMW" , OBJECT );

		Class B_class( &A_class , "B" );
		Class C_class( nullptr , "C" );
		Class D_class( nullptr , "D" );
		D_class.addStaticField( "Suzuki" , INT );
		D_class.addStaticField( "PORSCHE" , OBJECT );
		D_class.addInstanceField( "Honda" , INT );
		D_class.addInstanceField( "Mercedes" , OBJECT );

		Class E_class( &A_class , "E" );
		Class F_class( &B_class , "F" );
		Class G_class( &F_class , "G" );
		Class H_class( nullptr , "H" );
		Class I_class( &D_class , "I" );
		Class J_class( nullptr , "J" );
		Class K_class( nullptr , "K" );
		Class L_class( &A_class , "L" );
		Class M_class( &B_class , "M" );
		Class N_class( &F_class , "N" );
		Class O_class( &A_class , "O" );
		Class P_class( &N_class , "P" );
		Class Q_class( &P_class , "Q" );
		Class R_class( &Q_class , "R" );
		Class S_class( &R_class , "S" );
		Class T_class( &S_class , "T" );
		Class U_class( &T_class , "U" );
		Class V_class( &U_class , "V" );
		Class W_class( &V_class , "W" );
		Class X_class( &W_class , "X" );
		Class Y_class( &X_class , "Y" );
		Class Z_class( &Y_class , "Z" );

		Object* a = A_class.newInstance();
		Object* b = B_class.newInstance();
		Object* c = C_class.newInstance();
		Object* d = D_class.newInstance();
		Object* e = E_class.newInstance();
		Object* f = F_class.newInstance();
		Object* g = G_class.newInstance();
		Object* h = H_class.newInstance();
		Object* i = I_class.newInstance();
		Object* j = J_class.newInstance();
		Object* k = K_class.newInstance();
		Object* l = L_class.newInstance();
		Object* m = M_class.newInstance();
		Object* n = N_class.newInstance();
		Object* o = O_class.newInstance();
		Object* p = P_class.newInstance();
		Object* q = Q_class.newInstance();
		Object* r = R_class.newInstance();
		Object* s = S_class.newInstance();
		Object* t = T_class.newInstance();
		Object* u = U_class.newInstance();
		Object* v = V_class.newInstance();
		Object* w = W_class.newInstance();
		Object* x = X_class.newInstance();
		Object* y = Y_class.newInstance();
		Object* z = Z_class.newInstance();

		Class::setAccessible( false );
		Class::setAccessible( true );

		try {
			x->setInt( "Buggati" , 1 );
			throwOnFalse( x->getInt( "Buggati" ) == 1 , "x->getInt('Buggati')==1" );
		}
		catch ( TypeError& ex ) {
			std::cout << ex.what() << std::endl;
			return false;
		}
		catch ( FieldNotFound& ex ) {
			std::cout << ex.what() << std::endl;
			return false;
		}
		catch ( FieldNotAccessible& ex ) {
			std::cout << ex.what() << std::endl;
			return false;
		}

		try {
			x->setInt( "Lexus" , 2 );
			//	throwOnFalse(x->getInt("Lexus") == 0, "x->getInt('Lexus')==0");
			return false;
		}
		catch ( TypeError& ex ) {

		}
		catch ( FieldNotFound& ex ) {
			std::cout << ex.what() << std::endl;
			return false;
		}
		catch ( FieldNotAccessible& ex ) {
			std::cout << ex.what() << std::endl;
			return false;
		}

		try {
			x->setInt( "Audi" , 3 );
			throwOnFalse( x->getInt( "Audi" ) == 3 , "x->getInt('Audi')==3" );
		}
		catch ( TypeError& ex ) {
			std::cout << ex.what() << std::endl;
			return false;
		}
		catch ( FieldNotFound& ex ) {
			std::cout << ex.what() << std::endl;
			return false;
		}
		catch ( FieldNotAccessible& ex ) {
			std::cout << ex.what() << std::endl;
			return false;
		}

		try {
			x->setInt( "BMW" , 4 );
			//	throwOnFalse(x->getInt("BMW") == 0, "x->getInt('BMW')==0");
			return false;
		}
		catch ( TypeError& ex ) {

		}
		catch ( FieldNotFound& ex ) {
			std::cout << ex.what() << std::endl;
			return false;
		}
		catch ( FieldNotAccessible& ex ) {
			std::cout << ex.what() << std::endl;
			return false;
		}

		try {
			x->setInt( "Suzuki" , 5 );
			//	throwOnFalse(x->getInt("Suzuki") == 0, "x->getInt('Suzuki')==0");
			return false;
		}
		catch ( TypeError& ex ) {
			std::cout << ex.what() << std::endl;
			return false;
		}
		catch ( FieldNotFound& ex ) {

		}
		catch ( FieldNotAccessible& ex ) {
			std::cout << ex.what() << std::endl;
			return false;
		}

		try {
			x->setInt( "PORSCHE" , 6 );
			//	throwOnFalse(x->getInt("PORSCHE") == 0, "x->getInt('PORSCHE')==0");
			return false;
		}
		catch ( TypeError& ex ) {
			std::cout << ex.what() << std::endl;
			return false;
		}
		catch ( FieldNotFound& ex ) {

		}
		catch ( FieldNotAccessible& ex ) {
			std::cout << ex.what() << std::endl;
			return false;
		}

		try {
			x->setInt( "Honda" , 7 );
			//	throwOnFalse(x->getInt("Honda") == 0, "x->getInt('Honda')==0");
			return false;
		}
		catch ( TypeError& ex ) {
			std::cout << ex.what() << std::endl;
			return false;
		}
		catch ( FieldNotFound& ex ) {
		}
		catch ( FieldNotAccessible& ex ) {
			std::cout << ex.what() << std::endl;
			return false;
		}

		try {
			x->setInt( "Mercedes" , 8 );
			//	throwOnFalse(x->getInt("Mercedes") == 0,
			//			"x->getInt('Mercedes')==0");
			return false;
		}
		catch ( TypeError& ex ) {
			std::cout << ex.what() << std::endl;
			return false;
		}
		catch ( FieldNotFound& ex ) {

		}
		catch ( FieldNotAccessible& ex ) {
			std::cout << ex.what() << std::endl;
			return false;
		}

	}
	catch ( std::exception& e ) {
		std::cout << e.what() << std::endl;
		return false;
	}
	return true;

}

bool testClassSetAccessibleTrueSetObj() {
	try {
		Class::setAccessible( true );
		Class A_class( nullptr , "A" );
		A_class.addStaticField( "Lexus" , OBJECT );
		A_class.addStaticField( "Buggati" , INT );
		A_class.addInstanceField( "Audi" , INT );
		A_class.addInstanceField( "BMW" , OBJECT );

		Class B_class( &A_class , "B" );
		Class C_class( nullptr , "C" );
		Class D_class( nullptr , "D" );
		D_class.addStaticField( "Suzuki" , INT );
		D_class.addStaticField( "PORSCHE" , OBJECT );
		D_class.addInstanceField( "Honda" , INT );
		D_class.addInstanceField( "Mercedes" , OBJECT );

		Class E_class( &A_class , "E" );
		Class F_class( &B_class , "F" );
		Class G_class( &F_class , "G" );
		Class H_class( nullptr , "H" );
		Class I_class( &D_class , "I" );
		Class J_class( nullptr , "J" );
		Class K_class( nullptr , "K" );
		Class L_class( &A_class , "L" );
		Class M_class( &B_class , "M" );
		Class N_class( &F_class , "N" );
		Class O_class( &A_class , "O" );
		Class P_class( &N_class , "P" );
		Class Q_class( &P_class , "Q" );
		Class R_class( &Q_class , "R" );
		Class S_class( &R_class , "S" );
		Class T_class( &S_class , "T" );
		Class U_class( &T_class , "U" );
		Class V_class( &U_class , "V" );
		Class W_class( &V_class , "W" );
		Class X_class( &W_class , "X" );
		Class Y_class( &X_class , "Y" );
		Class Z_class( &Y_class , "Z" );

		Object* a = A_class.newInstance();
		Object* b = B_class.newInstance();
		Object* c = C_class.newInstance();
		Object* d = D_class.newInstance();
		Object* e = E_class.newInstance();
		Object* f = F_class.newInstance();
		Object* g = G_class.newInstance();
		Object* h = H_class.newInstance();
		Object* i = I_class.newInstance();
		Object* j = J_class.newInstance();
		Object* k = K_class.newInstance();
		Object* l = L_class.newInstance();
		Object* m = M_class.newInstance();
		Object* n = N_class.newInstance();
		Object* o = O_class.newInstance();
		Object* p = P_class.newInstance();
		Object* q = Q_class.newInstance();
		Object* r = R_class.newInstance();
		Object* s = S_class.newInstance();
		Object* t = T_class.newInstance();
		Object* u = U_class.newInstance();
		Object* v = V_class.newInstance();
		Object* w = W_class.newInstance();
		Object* x = X_class.newInstance();
		Object* y = Y_class.newInstance();
		Object* z = Z_class.newInstance();

		Class::setAccessible( false );
		Class::setAccessible( true );

		try {
			x->setObj( "Buggati" , a );
			//	throwOnFalse(x->getObj("Buggati") == nullptr, "x->getObj('Buggati')==nullptr");
			return false;
		}
		catch ( TypeError& ex ) {

		}
		catch ( FieldNotFound& ex ) {
			std::cout << ex.what() << std::endl;
			return false;
		}
		catch ( FieldNotAccessible& ex ) {
			std::cout << ex.what() << std::endl;
			return false;
		}

		try {
			x->setObj( "Lexus" , b );
			throwOnFalse( x->getObj( "Lexus" ) == b , "x->getObj('Lexus')==b" );
		}
		catch ( TypeError& ex ) {
			std::cout << ex.what() << std::endl;
			return false;

		}
		catch ( FieldNotFound& ex ) {
			std::cout << ex.what() << std::endl;
			return false;
		}
		catch ( FieldNotAccessible& ex ) {
			std::cout << ex.what() << std::endl;
			return false;
		}

		try {
			x->setObj( "Audi" , c );
			//	throwOnFalse(x->getObj("Audi") == nullptr, "x->getObj('Audi')==nullptr");
			return false;
		}
		catch ( TypeError& ex ) {
		}
		catch ( FieldNotFound& ex ) {
			std::cout << ex.what() << std::endl;
			return false;
		}
		catch ( FieldNotAccessible& ex ) {
			std::cout << ex.what() << std::endl;
			return false;
		}

		try {
			x->setObj( "BMW" , d );
			throwOnFalse( x->getObj( "BMW" ) == d , "x->getObj('BMW')==d" );
		}
		catch ( TypeError& ex ) {
			std::cout << ex.what() << std::endl;
			return false;

		}
		catch ( FieldNotFound& ex ) {
			std::cout << ex.what() << std::endl;
			return false;
		}
		catch ( FieldNotAccessible& ex ) {
			std::cout << ex.what() << std::endl;
			return false;
		}

		try {
			x->setObj( "Suzuki" , e );
			//	throwOnFalse(x->getObj("Suzuki") == nullptr, "x->getObj('Suzuki')==nullptr");
			return false;
		}
		catch ( TypeError& ex ) {
			std::cout << ex.what() << std::endl;
			return false;

		}
		catch ( FieldNotFound& ex ) {

		}
		catch ( FieldNotAccessible& ex ) {
			std::cout << ex.what() << std::endl;
			return false;
		}

		try {
			x->setObj( "PORSCHE" , f );
			//	throwOnFalse(x->getObj("PORSCHE") == nullptr, "x->getObj('PORSCHE')==nullptr");
			return false;
		}
		catch ( TypeError& ex ) {
			std::cout << ex.what() << std::endl;
			return false;

		}
		catch ( FieldNotFound& ex ) {
		}
		catch ( FieldNotAccessible& ex ) {
			std::cout << ex.what() << std::endl;
			return false;
		}

		try {
			x->setObj( "Honda" , g );
			//	throwOnFalse(x->getObj("Honda") == nullptr, "x->getObj('Honda')==nullptr");
			return false;
		}
		catch ( TypeError& ex ) {
			std::cout << ex.what() << std::endl;
			return false;

		}
		catch ( FieldNotFound& ex ) {
		}
		catch ( FieldNotAccessible& ex ) {
			std::cout << ex.what() << std::endl;
			return false;
		}

		try {
			x->setObj( "Mercedes" , h );
			//		throwOnFalse(x->getObj("Mercedes") == nullptr,
			//				"x->getObj('Mercedes')==nullptr");
			return false;
		}
		catch ( TypeError& ex ) {
			std::cout << ex.what() << std::endl;
			return false;

		}
		catch ( FieldNotFound& ex ) {
		}
		catch ( FieldNotAccessible& ex ) {
			std::cout << ex.what() << std::endl;
			return false;
		}

	}
	catch ( std::exception& e ) {
		std::cout << e.what() << std::endl;
		return false;
	}
	return true;

}

bool testClassSetAccessibleFalseGetInt() {
	try {
		Class::setAccessible( false );
		Class A_class( nullptr , "A" );
		A_class.addStaticField( "Lexus" , OBJECT );
		A_class.addStaticField( "Buggati" , INT );
		A_class.addInstanceField( "Audi" , INT );
		A_class.addInstanceField( "BMW" , OBJECT );

		Class B_class( &A_class , "B" );
		Class C_class( nullptr , "C" );
		Class D_class( nullptr , "D" );
		D_class.addStaticField( "Suzuki" , INT );
		D_class.addStaticField( "PORSCHE" , OBJECT );
		D_class.addInstanceField( "Honda" , INT );
		D_class.addInstanceField( "Mercedes" , OBJECT );

		Class E_class( &A_class , "E" );
		Class F_class( &B_class , "F" );
		Class G_class( &F_class , "G" );
		Class H_class( nullptr , "H" );
		Class I_class( &D_class , "I" );
		Class J_class( nullptr , "J" );
		Class K_class( nullptr , "K" );
		Class L_class( &A_class , "L" );
		Class M_class( &B_class , "M" );
		Class N_class( &F_class , "N" );
		Class O_class( &A_class , "O" );
		Class P_class( &N_class , "P" );
		Class Q_class( &P_class , "Q" );
		Class R_class( &Q_class , "R" );
		Class S_class( &R_class , "S" );
		Class T_class( &S_class , "T" );
		Class U_class( &T_class , "U" );
		Class V_class( &U_class , "V" );
		Class W_class( &V_class , "W" );
		Class X_class( &W_class , "X" );
		Class Y_class( &X_class , "Y" );
		Class Z_class( &Y_class , "Z" );

		Object* a = A_class.newInstance();
		Object* b = B_class.newInstance();
		Object* c = C_class.newInstance();
		Object* d = D_class.newInstance();
		Object* e = E_class.newInstance();
		Object* f = F_class.newInstance();
		Object* g = G_class.newInstance();
		Object* h = H_class.newInstance();
		Object* i = I_class.newInstance();
		Object* j = J_class.newInstance();
		Object* k = K_class.newInstance();
		Object* l = L_class.newInstance();
		Object* m = M_class.newInstance();
		Object* n = N_class.newInstance();
		Object* o = O_class.newInstance();
		Object* p = P_class.newInstance();
		Object* q = Q_class.newInstance();
		Object* r = R_class.newInstance();
		Object* s = S_class.newInstance();
		Object* t = T_class.newInstance();
		Object* u = U_class.newInstance();
		Object* v = V_class.newInstance();
		Object* w = W_class.newInstance();
		Object* x = X_class.newInstance();
		Object* y = Y_class.newInstance();
		Object* z = Z_class.newInstance();

		Class::setAccessible( true );
		Class::setAccessible( false );

		try {
			throwOnFalse( x->getInt( "Buggati" ) == 0 , "x->getInt('Buggati')==0" );
		}
		catch ( TypeError& ex ) {
			std::cout << ex.what() << std::endl;
			return false;
		}
		catch ( FieldNotFound& ex ) {
			std::cout << ex.what() << std::endl;
			return false;
		}
		catch ( FieldNotAccessible& ex ) {
			std::cout << ex.what() << std::endl;
			return false;
		}

		try {
			throwOnFalse( x->getInt( "Lexus" ) == 0 , "x->getInt('Lexus')==0" );
			return false;
		}
		catch ( TypeError& ex ) {

		}
		catch ( FieldNotFound& ex ) {
			std::cout << ex.what() << std::endl;
			return false;
		}
		catch ( FieldNotAccessible& ex ) {
			std::cout << ex.what() << std::endl;
			return false;
		}

		try {
			throwOnFalse( x->getInt( "Audi" ) == 0 , "x->getInt('Audi')==0" );
			return false; // Instance setAccessible=false :(
		}
		catch ( TypeError& ex ) {
			std::cout << ex.what() << std::endl;
			return false;
		}
		catch ( FieldNotFound& ex ) {
			std::cout << ex.what() << std::endl;
			return false;
		}
		catch ( FieldNotAccessible& ex ) {

		}

		try {
			throwOnFalse( x->getInt( "BMW" ) == 0 , "x->getInt('BMW')==0" );
			return false;
		}
		catch ( TypeError& ex ) {

		}
		catch ( FieldNotFound& ex ) {
			std::cout << ex.what() << std::endl;
			return false;
		}
		catch ( FieldNotAccessible& ex ) {
			std::cout << ex.what() << std::endl;
			return false;
		}

		try {
			throwOnFalse( x->getInt( "Suzuki" ) == 0 , "x->getInt('Suzuki')==0" );
			return false;
		}
		catch ( TypeError& ex ) {
			std::cout << ex.what() << std::endl;
			return false;
		}
		catch ( FieldNotFound& ex ) {

		}
		catch ( FieldNotAccessible& ex ) {
			std::cout << ex.what() << std::endl;
			return false;
		}

		try {
			throwOnFalse( x->getInt( "PORSCHE" ) == 0 , "x->getInt('PORSCHE')==0" );
			return false;
		}
		catch ( TypeError& ex ) {
			std::cout << ex.what() << std::endl;
			return false;
		}
		catch ( FieldNotFound& ex ) {

		}
		catch ( FieldNotAccessible& ex ) {
			std::cout << ex.what() << std::endl;
			return false;
		}

		try {
			throwOnFalse( x->getInt( "Honda" ) == 0 , "x->getInt('Honda')==0" );
			return false;
		}
		catch ( TypeError& ex ) {
			std::cout << ex.what() << std::endl;
			return false;
		}
		catch ( FieldNotFound& ex ) {
		}
		catch ( FieldNotAccessible& ex ) {
			std::cout << ex.what() << std::endl;
			return false;
		}

		try {
			throwOnFalse( x->getInt( "Mercedes" ) == 0 ,
				"x->getInt('Mercedes')==0" );
			return false;
		}
		catch ( TypeError& ex ) {
			std::cout << ex.what() << std::endl;
			return false;
		}
		catch ( FieldNotFound& ex ) {

		}
		catch ( FieldNotAccessible& ex ) {
			std::cout << ex.what() << std::endl;
			return false;
		}

	}
	catch ( std::exception& e ) {
		std::cout << e.what() << std::endl;
		return false;
	}
	return true;

}
bool testClassSetAccessibleFalseGetObj() {
	try {
		Class::setAccessible( false );
		Class A_class( nullptr , "A" );
		A_class.addStaticField( "Lexus" , OBJECT );
		A_class.addStaticField( "Buggati" , INT );
		A_class.addInstanceField( "Audi" , INT );
		A_class.addInstanceField( "BMW" , OBJECT );

		Class B_class( &A_class , "B" );
		Class C_class( nullptr , "C" );
		Class D_class( nullptr , "D" );
		D_class.addStaticField( "Suzuki" , INT );
		D_class.addStaticField( "PORSCHE" , OBJECT );
		D_class.addInstanceField( "Honda" , INT );
		D_class.addInstanceField( "Mercedes" , OBJECT );

		Class E_class( &A_class , "E" );
		Class F_class( &B_class , "F" );
		Class G_class( &F_class , "G" );
		Class H_class( nullptr , "H" );
		Class I_class( &D_class , "I" );
		Class J_class( nullptr , "J" );
		Class K_class( nullptr , "K" );
		Class L_class( &A_class , "L" );
		Class M_class( &B_class , "M" );
		Class N_class( &F_class , "N" );
		Class O_class( &A_class , "O" );
		Class P_class( &N_class , "P" );
		Class Q_class( &P_class , "Q" );
		Class R_class( &Q_class , "R" );
		Class S_class( &R_class , "S" );
		Class T_class( &S_class , "T" );
		Class U_class( &T_class , "U" );
		Class V_class( &U_class , "V" );
		Class W_class( &V_class , "W" );
		Class X_class( &W_class , "X" );
		Class Y_class( &X_class , "Y" );
		Class Z_class( &Y_class , "Z" );

		Object* a = A_class.newInstance();
		Object* b = B_class.newInstance();
		Object* c = C_class.newInstance();
		Object* d = D_class.newInstance();
		Object* e = E_class.newInstance();
		Object* f = F_class.newInstance();
		Object* g = G_class.newInstance();
		Object* h = H_class.newInstance();
		Object* i = I_class.newInstance();
		Object* j = J_class.newInstance();
		Object* k = K_class.newInstance();
		Object* l = L_class.newInstance();
		Object* m = M_class.newInstance();
		Object* n = N_class.newInstance();
		Object* o = O_class.newInstance();
		Object* p = P_class.newInstance();
		Object* q = Q_class.newInstance();
		Object* r = R_class.newInstance();
		Object* s = S_class.newInstance();
		Object* t = T_class.newInstance();
		Object* u = U_class.newInstance();
		Object* v = V_class.newInstance();
		Object* w = W_class.newInstance();
		Object* x = X_class.newInstance();
		Object* y = Y_class.newInstance();
		Object* z = Z_class.newInstance();

		Class::setAccessible( true );
		Class::setAccessible( false );

		try {
			throwOnFalse( x->getObj( "Buggati" ) == nullptr ,
				"x->getObj('Buggati')==nullptr" );
			return false;
		}
		catch ( TypeError& ex ) {

		}
		catch ( FieldNotFound& ex ) {
			std::cout << ex.what() << std::endl;
			return false;
		}
		catch ( FieldNotAccessible& ex ) {
			std::cout << ex.what() << std::endl;
			return false;
		}

		try {
			throwOnFalse( x->getObj( "Lexus" ) == nullptr ,
				"x->getObj('Lexus')==nullptr" );
		}
		catch ( TypeError& ex ) {
			std::cout << ex.what() << std::endl;
			return false;

		}
		catch ( FieldNotFound& ex ) {
			std::cout << ex.what() << std::endl;
			return false;
		}
		catch ( FieldNotAccessible& ex ) {
			std::cout << ex.what() << std::endl;
			return false;
		}

		try {
			throwOnFalse( x->getObj( "Audi" ) == nullptr ,
				"x->getObj('Audi')==nullptr" );
			return false;
		}
		catch ( TypeError& ex ) {
		}
		catch ( FieldNotFound& ex ) {
			std::cout << ex.what() << std::endl;
			return false;
		}
		catch ( FieldNotAccessible& ex ) {
			std::cout << ex.what() << std::endl;
			return false;
		}

		try {
			throwOnFalse( x->getObj( "BMW" ) == nullptr ,
				"x->getObj('BMW')==nullptr" );
			return false; // Instance setAccessible=false :(
		}
		catch ( TypeError& ex ) {
			std::cout << ex.what() << std::endl;
			return false;

		}
		catch ( FieldNotFound& ex ) {
			std::cout << ex.what() << std::endl;
			return false;
		}
		catch ( FieldNotAccessible& ex ) {

		}

		try {
			throwOnFalse( x->getObj( "Suzuki" ) == nullptr ,
				"x->getObj('Suzuki')==nullptr" );
			return false;
		}
		catch ( TypeError& ex ) {
			std::cout << ex.what() << std::endl;
			return false;

		}
		catch ( FieldNotFound& ex ) {

		}
		catch ( FieldNotAccessible& ex ) {
			std::cout << ex.what() << std::endl;
			return false;
		}

		try {
			throwOnFalse( x->getObj( "PORSCHE" ) == nullptr ,
				"x->getObj('PORSCHE')==nullptr" );
			return false;
		}
		catch ( TypeError& ex ) {
			std::cout << ex.what() << std::endl;
			return false;

		}
		catch ( FieldNotFound& ex ) {
		}
		catch ( FieldNotAccessible& ex ) {
			std::cout << ex.what() << std::endl;
			return false;
		}

		try {
			throwOnFalse( x->getObj( "Honda" ) == nullptr ,
				"x->getObj('Honda')==nullptr" );
			return false;
		}
		catch ( TypeError& ex ) {
			std::cout << ex.what() << std::endl;
			return false;

		}
		catch ( FieldNotFound& ex ) {
		}
		catch ( FieldNotAccessible& ex ) {
			std::cout << ex.what() << std::endl;
			return false;
		}

		try {
			throwOnFalse( x->getObj( "Mercedes" ) == nullptr ,
				"x->getObj('Mercedes')==nullptr" );
			return false;
		}
		catch ( TypeError& ex ) {
			std::cout << ex.what() << std::endl;
			return false;

		}
		catch ( FieldNotFound& ex ) {
		}
		catch ( FieldNotAccessible& ex ) {
			std::cout << ex.what() << std::endl;
			return false;
		}

	}
	catch ( std::exception& e ) {
		std::cout << e.what() << std::endl;
		return false;
	}
	return true;

}
bool testClassSetAccessibleFalseSetInt() {
	try {
		Class::setAccessible( false );
		Class A_class( nullptr , "A" );
		A_class.addStaticField( "Lexus" , OBJECT );
		A_class.addStaticField( "Buggati" , INT );
		A_class.addInstanceField( "Audi" , INT );
		A_class.addInstanceField( "BMW" , OBJECT );

		Class B_class( &A_class , "B" );
		Class C_class( nullptr , "C" );
		Class D_class( nullptr , "D" );
		D_class.addStaticField( "Suzuki" , INT );
		D_class.addStaticField( "PORSCHE" , OBJECT );
		D_class.addInstanceField( "Honda" , INT );
		D_class.addInstanceField( "Mercedes" , OBJECT );

		Class E_class( &A_class , "E" );
		Class F_class( &B_class , "F" );
		Class G_class( &F_class , "G" );
		Class H_class( nullptr , "H" );
		Class I_class( &D_class , "I" );
		Class J_class( nullptr , "J" );
		Class K_class( nullptr , "K" );
		Class L_class( &A_class , "L" );
		Class M_class( &B_class , "M" );
		Class N_class( &F_class , "N" );
		Class O_class( &A_class , "O" );
		Class P_class( &N_class , "P" );
		Class Q_class( &P_class , "Q" );
		Class R_class( &Q_class , "R" );
		Class S_class( &R_class , "S" );
		Class T_class( &S_class , "T" );
		Class U_class( &T_class , "U" );
		Class V_class( &U_class , "V" );
		Class W_class( &V_class , "W" );
		Class X_class( &W_class , "X" );
		Class Y_class( &X_class , "Y" );
		Class Z_class( &Y_class , "Z" );

		Object* a = A_class.newInstance();
		Object* b = B_class.newInstance();
		Object* c = C_class.newInstance();
		Object* d = D_class.newInstance();
		Object* e = E_class.newInstance();
		Object* f = F_class.newInstance();
		Object* g = G_class.newInstance();
		Object* h = H_class.newInstance();
		Object* i = I_class.newInstance();
		Object* j = J_class.newInstance();
		Object* k = K_class.newInstance();
		Object* l = L_class.newInstance();
		Object* m = M_class.newInstance();
		Object* n = N_class.newInstance();
		Object* o = O_class.newInstance();
		Object* p = P_class.newInstance();
		Object* q = Q_class.newInstance();
		Object* r = R_class.newInstance();
		Object* s = S_class.newInstance();
		Object* t = T_class.newInstance();
		Object* u = U_class.newInstance();
		Object* v = V_class.newInstance();
		Object* w = W_class.newInstance();
		Object* x = X_class.newInstance();
		Object* y = Y_class.newInstance();
		Object* z = Z_class.newInstance();

		Class::setAccessible( true );
		Class::setAccessible( false );

		try {
			x->setInt( "Buggati" , 1 );
			throwOnFalse( x->getInt( "Buggati" ) == 1 , "x->getInt('Buggati')==1" );
		}
		catch ( TypeError& ex ) {
			std::cout << ex.what() << std::endl;
			return false;
		}
		catch ( FieldNotFound& ex ) {
			std::cout << ex.what() << std::endl;
			return false;
		}
		catch ( FieldNotAccessible& ex ) {
			std::cout << ex.what() << std::endl;
			return false;
		}

		try {
			x->setInt( "Lexus" , 2 );
			//	throwOnFalse(x->getInt("Lexus") == 0, "x->getInt('Lexus')==0");
			return false;
		}
		catch ( TypeError& ex ) {

		}
		catch ( FieldNotFound& ex ) {
			std::cout << ex.what() << std::endl;
			return false;
		}
		catch ( FieldNotAccessible& ex ) {
			std::cout << ex.what() << std::endl;
			return false;
		}

		try {
			x->setInt( "Audi" , 3 );
			return false; // Instance setAccessible=false :(
						  //	throwOnFalse(x->getInt("Audi") == 3, "x->getInt('Audi')==3");
		}
		catch ( TypeError& ex ) {
			std::cout << ex.what() << std::endl;
			return false;
		}
		catch ( FieldNotFound& ex ) {
			std::cout << ex.what() << std::endl;
			return false;
		}
		catch ( FieldNotAccessible& ex ) {
		}

		try {
			x->setInt( "BMW" , 4 );
			//	throwOnFalse(x->getInt("BMW") == 0, "x->getInt('BMW')==0");
			return false;
		}
		catch ( TypeError& ex ) {

		}
		catch ( FieldNotFound& ex ) {
			std::cout << ex.what() << std::endl;
			return false;
		}
		catch ( FieldNotAccessible& ex ) {
			std::cout << ex.what() << std::endl;
			return false;
		}

		try {
			x->setInt( "Suzuki" , 5 );
			//	throwOnFalse(x->getInt("Suzuki") == 0, "x->getInt('Suzuki')==0");
			return false;
		}
		catch ( TypeError& ex ) {
			std::cout << ex.what() << std::endl;
			return false;
		}
		catch ( FieldNotFound& ex ) {

		}
		catch ( FieldNotAccessible& ex ) {
			std::cout << ex.what() << std::endl;
			return false;
		}

		try {
			x->setInt( "PORSCHE" , 6 );
			//	throwOnFalse(x->getInt("PORSCHE") == 0, "x->getInt('PORSCHE')==0");
			return false;
		}
		catch ( TypeError& ex ) {
			std::cout << ex.what() << std::endl;
			return false;
		}
		catch ( FieldNotFound& ex ) {

		}
		catch ( FieldNotAccessible& ex ) {
			std::cout << ex.what() << std::endl;
			return false;
		}

		try {
			x->setInt( "Honda" , 7 );
			//	throwOnFalse(x->getInt("Honda") == 0, "x->getInt('Honda')==0");
			return false;
		}
		catch ( TypeError& ex ) {
			std::cout << ex.what() << std::endl;
			return false;
		}
		catch ( FieldNotFound& ex ) {
		}
		catch ( FieldNotAccessible& ex ) {
			std::cout << ex.what() << std::endl;
			return false;
		}

		try {
			x->setInt( "Mercedes" , 8 );
			//	throwOnFalse(x->getInt("Mercedes") == 0,
			//			"x->getInt('Mercedes')==0");
			return false;
		}
		catch ( TypeError& ex ) {
			std::cout << ex.what() << std::endl;
			return false;
		}
		catch ( FieldNotFound& ex ) {

		}
		catch ( FieldNotAccessible& ex ) {
			std::cout << ex.what() << std::endl;
			return false;
		}

	}
	catch ( std::exception& e ) {
		std::cout << e.what() << std::endl;
		return false;
	}
	return true;

}
bool testClassSetAccessibleFalseSetObj() {
	try {
		Class::setAccessible( false );
		Class A_class( nullptr , "A" );
		A_class.addStaticField( "Lexus" , OBJECT );
		A_class.addStaticField( "Buggati" , INT );
		A_class.addInstanceField( "Audi" , INT );
		A_class.addInstanceField( "BMW" , OBJECT );

		Class B_class( &A_class , "B" );
		Class C_class( nullptr , "C" );
		Class D_class( nullptr , "D" );
		D_class.addStaticField( "Suzuki" , INT );
		D_class.addStaticField( "PORSCHE" , OBJECT );
		D_class.addInstanceField( "Honda" , INT );
		D_class.addInstanceField( "Mercedes" , OBJECT );

		Class E_class( &A_class , "E" );
		Class F_class( &B_class , "F" );
		Class G_class( &F_class , "G" );
		Class H_class( nullptr , "H" );
		Class I_class( &D_class , "I" );
		Class J_class( nullptr , "J" );
		Class K_class( nullptr , "K" );
		Class L_class( &A_class , "L" );
		Class M_class( &B_class , "M" );
		Class N_class( &F_class , "N" );
		Class O_class( &A_class , "O" );
		Class P_class( &N_class , "P" );
		Class Q_class( &P_class , "Q" );
		Class R_class( &Q_class , "R" );
		Class S_class( &R_class , "S" );
		Class T_class( &S_class , "T" );
		Class U_class( &T_class , "U" );
		Class V_class( &U_class , "V" );
		Class W_class( &V_class , "W" );
		Class X_class( &W_class , "X" );
		Class Y_class( &X_class , "Y" );
		Class Z_class( &Y_class , "Z" );

		Object* a = A_class.newInstance();
		Object* b = B_class.newInstance();
		Object* c = C_class.newInstance();
		Object* d = D_class.newInstance();
		Object* e = E_class.newInstance();
		Object* f = F_class.newInstance();
		Object* g = G_class.newInstance();
		Object* h = H_class.newInstance();
		Object* i = I_class.newInstance();
		Object* j = J_class.newInstance();
		Object* k = K_class.newInstance();
		Object* l = L_class.newInstance();
		Object* m = M_class.newInstance();
		Object* n = N_class.newInstance();
		Object* o = O_class.newInstance();
		Object* p = P_class.newInstance();
		Object* q = Q_class.newInstance();
		Object* r = R_class.newInstance();
		Object* s = S_class.newInstance();
		Object* t = T_class.newInstance();
		Object* u = U_class.newInstance();
		Object* v = V_class.newInstance();
		Object* w = W_class.newInstance();
		Object* x = X_class.newInstance();
		Object* y = Y_class.newInstance();
		Object* z = Z_class.newInstance();

		Class::setAccessible( true );
		Class::setAccessible( false );

		try {
			x->setObj( "Buggati" , a );
			//	throwOnFalse(x->getObj("Buggati") == nullptr, "x->getObj('Buggati')==nullptr");
			return false;
		}
		catch ( TypeError& ex ) {

		}
		catch ( FieldNotFound& ex ) {
			std::cout << ex.what() << std::endl;
			return false;
		}
		catch ( FieldNotAccessible& ex ) {
			std::cout << ex.what() << std::endl;
			return false;
		}

		try {
			x->setObj( "Lexus" , b );
			throwOnFalse( x->getObj( "Lexus" ) == b , "x->getObj('Lexus')==b" );
		}
		catch ( TypeError& ex ) {
			std::cout << ex.what() << std::endl;
			return false;

		}
		catch ( FieldNotFound& ex ) {
			std::cout << ex.what() << std::endl;
			return false;
		}
		catch ( FieldNotAccessible& ex ) {
			std::cout << ex.what() << std::endl;
			return false;
		}

		try {
			x->setObj( "Audi" , c );
			//	throwOnFalse(x->getObj("Audi") == nullptr, "x->getObj('Audi')==nullptr");
			return false;
		}
		catch ( TypeError& ex ) {
		}
		catch ( FieldNotFound& ex ) {
			std::cout << ex.what() << std::endl;
			return false;
		}
		catch ( FieldNotAccessible& ex ) {
			std::cout << ex.what() << std::endl;
			return false;
		}

		try {
			x->setObj( "BMW" , d );
			// throwOnFalse(x->getObj("BMW") == d, "x->getObj('BMW')==d");
			return false; // Instance setAccessible=false :(
		}
		catch ( TypeError& ex ) {
			std::cout << ex.what() << std::endl;
			return false;

		}
		catch ( FieldNotFound& ex ) {
			std::cout << ex.what() << std::endl;
			return false;
		}
		catch ( FieldNotAccessible& ex ) {

		}

		try {
			x->setObj( "Suzuki" , e );
			//	throwOnFalse(x->getObj("Suzuki") == nullptr, "x->getObj('Suzuki')==nullptr");
			return false;
		}
		catch ( TypeError& ex ) {
			std::cout << ex.what() << std::endl;
			return false;

		}
		catch ( FieldNotFound& ex ) {

		}
		catch ( FieldNotAccessible& ex ) {
			std::cout << ex.what() << std::endl;
			return false;
		}

		try {
			x->setObj( "PORSCHE" , f );
			//	throwOnFalse(x->getObj("PORSCHE") == nullptr, "x->getObj('PORSCHE')==nullptr");
			return false;
		}
		catch ( TypeError& ex ) {
			std::cout << ex.what() << std::endl;
			return false;

		}
		catch ( FieldNotFound& ex ) {
		}
		catch ( FieldNotAccessible& ex ) {
			std::cout << ex.what() << std::endl;
			return false;
		}

		try {
			x->setObj( "Honda" , g );
			//	throwOnFalse(x->getObj("Honda") == nullptr, "x->getObj('Honda')==nullptr");
			return false;
		}
		catch ( TypeError& ex ) {
			std::cout << ex.what() << std::endl;
			return false;

		}
		catch ( FieldNotFound& ex ) {
		}
		catch ( FieldNotAccessible& ex ) {
			std::cout << ex.what() << std::endl;
			return false;
		}

		try {
			x->setObj( "Mercedes" , h );
			//		throwOnFalse(x->getObj("Mercedes") == nullptr,
			//				"x->getObj('Mercedes')==nullptr");
			return false;
		}
		catch ( TypeError& ex ) {
			std::cout << ex.what() << std::endl;
			return false;

		}
		catch ( FieldNotFound& ex ) {
		}
		catch ( FieldNotAccessible& ex ) {
			std::cout << ex.what() << std::endl;
			return false;
		}

	}
	catch ( std::exception& e ) {
		std::cout << e.what() << std::endl;
		return false;
	}
	return true;
}

bool testClassFAQMethodSetAccessibleGetInt() {
	Class::setAccessible( false );
	ZZZGetInt_class.addInstanceField( "m_x" , INT );
	ZZZGetInt_class.addStaticField( "s_x" , INT );
	Object* a = ZZZGetInt_class.newInstance();
	try {
		a->setInt( "m_x" , 21 ); // FieldNotAccessible since it is like a->m_x
	}
	catch ( FieldNotAccessible& e ) {
	}
	try {
		//Field f = a->getClass()->getField("m_x");
		a->getInt( "m_x" ); // FieldNotAccessible since it is like a->m_x
	}
	catch ( FieldNotAccessible& e ) {
	}
	ZZZGetInt_class.addMethod( "foo1GetInt" , foo1GetInt );
	try {
		a->invokeMethod( "foo1GetInt" );
	}
	catch ( FieldNotAccessible& e ) {
	}
	ZZZGetInt_class.addMethod( "foo2GetInt" , foo2GetInt );
	a->invokeMethod( "foo2GetInt" );
	ZZZGetInt_class.addMethod( "foo3GetInt" , foo3GetInt );
	a->invokeMethod( "foo3GetInt" );
	return true;
}

bool testClassFAQMethodSetAccessibleGetObj() {
	Class::setAccessible( false );
	ZZZGetObj_class.addInstanceField( "m_x" , OBJECT );
	ZZZGetObj_class.addStaticField( "s_x" , OBJECT );
	Object* a = ZZZGetObj_class.newInstance();
	try {
		a->setObj( "m_x" , a ); // FieldNotAccessible since it is like a->m_x
	}
	catch ( FieldNotAccessible& e ) {
	}
	try {
		//Field f = a->getClass()->getField("m_x");
		a->getObj( "m_x" ); // FieldNotAccessible since it is like a->m_x
	}
	catch ( FieldNotAccessible& e ) {
	}
	ZZZGetObj_class.addMethod( "foo1GetObj" , foo1GetObj );
	try {
		a->invokeMethod( "foo1GetObj" );
	}
	catch ( FieldNotAccessible& e ) {
	}
	ZZZGetObj_class.addMethod( "foo2GetObj" , foo2GetObj );
	a->invokeMethod( "foo2GetObj" );
	ZZZGetObj_class.addMethod( "foo3GetObj" , foo3GetObj );
	a->invokeMethod( "foo3GetObj" );
	return true;
}

bool testClassFAQMethodSetAccessibleSetInt() {
	Class::setAccessible( false );
	ZZZSetInt_class.addInstanceField( "m_x" , INT );
	ZZZSetInt_class.addStaticField( "s_x" , INT );
	Object* a = ZZZSetInt_class.newInstance();
	try {
		a->setInt( "m_x" , 21 ); // FieldNotAccessible since it is like a->m_x
	}
	catch ( FieldNotAccessible& e ) {
	}
	try {
		//Field f = a->getClass()->getField("m_x");
		a->getInt( "m_x" ); // FieldNotAccessible since it is like a->m_x
	}
	catch ( FieldNotAccessible& e ) {
	}
	ZZZSetInt_class.addMethod( "foo1SetInt" , foo1SetInt );
	try {
		a->invokeMethod( "foo1SetInt" );
	}
	catch ( FieldNotAccessible& e ) {
	}
	ZZZSetInt_class.addMethod( "foo2SetInt" , foo2SetInt );
	a->invokeMethod( "foo2SetInt" );
	ZZZSetInt_class.addMethod( "foo3SetInt" , foo3SetInt );
	a->invokeMethod( "foo3SetInt" );
	return true;
}

bool testClassFAQMethodSetAccessibleSetObj() {
	Class::setAccessible( false );
	ZZZSetObj_class.addInstanceField( "m_x" , OBJECT );
	ZZZSetObj_class.addStaticField( "s_x" , OBJECT );
	Object* a = ZZZSetObj_class.newInstance();
	try {
		a->setObj( "m_x" , a ); // FieldNotAccessible since it is like a->m_x
	}
	catch ( FieldNotAccessible& e ) {
	}
	try {
		//Field f = a->getClass()->getField("m_x");
		a->getObj( "m_x" ); // FieldNotAccessible since it is like a->m_x
	}
	catch ( FieldNotAccessible& e ) {
	}
	ZZZSetObj_class.addMethod( "foo1SetObj" , foo1SetObj );
	try {
		a->invokeMethod( "foo1SetObj" );
	}
	catch ( FieldNotAccessible& e ) {
	}
	ZZZSetObj_class.addMethod( "foo2SetObj" , foo2SetObj );
	a->invokeMethod( "foo2SetObj" );
	ZZZSetObj_class.addMethod( "foo3SetObj" , foo3SetObj );
	a->invokeMethod( "foo3SetObj" );
	return true;
}

bool testClassFAQMethodSetAccessible() {
	return true
		&& printTestSuccessOrFail( testClassFAQMethodSetAccessibleGetInt() ,
			"testClassFAQMethodSetAccessibleGetInt" )
		&& printTestSuccessOrFail( testClassFAQMethodSetAccessibleGetObj() ,
			"testClassFAQMethodSetAccessibleGetObj" )
		&& printTestSuccessOrFail( testClassFAQMethodSetAccessibleSetInt() ,
			"testClassFAQMethodSetAccessibleSetInt" )
		&& printTestSuccessOrFail( testClassFAQMethodSetAccessibleSetObj() ,
			"testClassFAQMethodSetAccessibleSetObj" );
}

bool testClassSetAccessibleTrue() {
	return true
		&& printTestSuccessOrFail( testClassSetAccessibleTrueGetInt() ,
			"testClassSetAccessibleTrueGetInt" )
		&& printTestSuccessOrFail( testClassSetAccessibleTrueGetObj() ,
			"testClassSetAccessibleTrueGetObj" )
		&& printTestSuccessOrFail( testClassSetAccessibleTrueSetInt() ,
			"testClassSetAccessibleTrueSetInt" )
		&& printTestSuccessOrFail( testClassSetAccessibleTrueSetObj() ,
			"testClassSetAccessibleTruesetObj" );

}
bool testClassSetAccessibleFalse() {
	return true
		&& printTestSuccessOrFail( testClassSetAccessibleFalseGetInt() ,
			"testClassSetAccessibleFalseGetInt" )
		&& printTestSuccessOrFail( testClassSetAccessibleFalseGetObj() ,
			"testClassSetAccessibleFalseGetObj" )
		&& printTestSuccessOrFail( testClassSetAccessibleFalseSetInt() ,
			"testClassSetAccessibleFalseSetInt" )
		&& printTestSuccessOrFail( testClassSetAccessibleFalseSetObj() ,
			"testClassSetAccessibleFalseSetObj" );
}
bool testClassSetAccessible() {
	return true
		&& printTestSuccessOrFail( testClassSetAccessibleTrue() ,
			"testClassSetAccessibleTrue" )
		&& printTestSuccessOrFail( testClassSetAccessibleFalse() ,
			"testClassSetAccessibleFalse" );
}

bool testClass() {
	return true

		&& printTestSuccessOrFail( testClassConstructor() , "testClassConstructor" )
		&& printTestSuccessOrFail( testClassName() , "testClassName" )
		&& printTestSuccessOrFail( testClassNewInstance() ,
			"testClassNewInstance" )
		&& printTestSuccessOrFail( testClassAddMethod() ,
			"testClassAddMethod" )
		&& printTestSuccessOrFail( testClassAddInstanceField() ,
			"testClassAddInstanceField" )
		&& printTestSuccessOrFail( testClassAddStaticField() ,
			"testClassAddStaticField" )
		&& printTestSuccessOrFail( testClassGetField() , "testClassGetField" )
		&& printTestSuccessOrFail( testClassGetMethod() ,
			"testClassGetMethod" )
		&& printTestSuccessOrFail( testClassGetMethods() ,
			"testClassGetMethods" )
		&& printTestSuccessOrFail( testClassGetFields() ,
			"testClassGetFields" )
		&& printTestSuccessOrFail( testClassGetInt() , "testClassGetInt" )
		&& printTestSuccessOrFail( testClassGetObj() , "testClassGetObj" )
		&& printTestSuccessOrFail( testClassSetInt() , "testClassSetInt" )
		&& printTestSuccessOrFail( testClassSetObj() , "testClassSetObj" )

		&& printTestSuccessOrFail( testClassGetSuperClass() ,
			"testClassGetSuperClass" )
		&& printTestSuccessOrFail( testClassSetAccessible() ,
			"testClassSetAccessible" )
		&& printTestSuccessOrFail( testClassFAQMethodSetAccessible() ,
			"testClassFAQMethodSetAccessible" );
}

bool testSameFieldName() {
	try {
		Class A_class( nullptr , "A" );
		Class B_class( &A_class , "B" );
		A_class.addStaticField( "x" , INT );
		B_class.addInstanceField( "x" , INT );

		Object* a = A_class.newInstance();

		Object* b = B_class.newInstance();

		Class::setAccessible( true );
		B_class.setInt( "x" , 3 ); // We set the static in A, since we don't know of x in B

		throwOnFalse( b->getInt( "x" ) == 0 , "'b->getInt('x')==0'" ); // B is closer than A
		throwOnFalse( a->getInt( "x" ) == 3 , "'a->getInt('x')==3'" ); // It's static, remember? :)
		throwOnFalse( A_class.getInt( "x" ) == 3 , "'A_class.getInt('x')==3'" ); // It's static, remember? :)
		throwOnFalse( B_class.getInt( "x" ) == 3 , "'B_class.getInt('x')==3'" ); // Only static counts here :)

		throwOnFalse( B_class.getFields().size() == 2 ,
			"B_class.getFields().size()==2" ); // Ensure we don't disregard an element just because it has same name

		Class C_class( &B_class , "C" );

		C_class.addInstanceField( "x" , OBJECT ); // Object or int ^^ , cool :D (Yea hence we override, so we care for last)

		Object* c = C_class.newInstance();

		throwOnFalse( C_class.getInt( "x" ) == 3 , "'B_class.getInt('x')==3'" ); // Only static counts here :)
		try {
			throwOnFalse( c->getInt( "x" ) == 3 , "'c->getInt('x')==3'" ); // We hide previous definition of x
		}
		catch ( TypeError& e ) {
			// It is a type error, we should hide it (x is an object, not int)
		}
		catch ( std::exception &e ) {
			std::cout << e.what() << std::endl;
			return false;
		}

		throwOnFalse( c->getObj( "x" ) == nullptr , "'c->getObj('x')==nullptr'" ); // The new definition is obj :)

		throwOnFalse( C_class.getFields().size() == 3 ,
			"C_class.getFields().size()==3" ); // Ensure we don't disregard an element just because it has same name

	}
	catch ( std::exception& e ) {
		std::cout << e.what() << std::endl;
		return false;
	}
	return true;

}

/******************************************************************************/
/******************************************************************************/
/*******************************Tests Invoke :)********************************/

Class Husband_class( nullptr , "Husband" );

Class Wife_class( nullptr , "Wife" );

Class Family_class( nullptr , "Family" );

void propose( Object* husband ) {
	husband->getObj( "Ring :)" ); // Takes out the ring, and proposes, romantically ^^

	husband->setInt( "WaitTime :)" , 7 );

	husband->invokeMethod( "Hope she says yes :)" );

	throwOnFalse( husband->getInt( "Heart :)" ) == 0 ,
		"husband->getInt('Heart :)')==0" );

	husband->setInt( "Heart :)" , 1 ); // Sets in her heart that he is HAPPY :), 1 stands for TRUE

	throwOnFalse( husband->getInt( "Heart :)" ) == 1 ,
		"husband->getInt('Heart :)')==1" );

	husband->setInt( "Relatives :)" , 40 );

	husband->invokeMethod( "Informs relatives :)" );
}

void hopeSheSaysYes( Object* husband ) {
	if ( husband->getInt( "WaitTime :)" ) > 0 ) {

		husband->setInt( "WaitTime :)" , husband->getInt( "WaitTime :)" ) - 1 ); // Time is decreasing

		husband->invokeMethod( "Hope she says yes :)" );
	}
	else { // Time's up, the result is.... drums... :)

		Object* wife = Wife_class.newInstance();

		try {
			wife->setInt( "Heart :)" , 1 ); // Sets in her heart that he is HAPPY :), 1 stands for TRUE
			throwOnFalse( false , "false" );
		}
		catch ( FieldNotAccessible& ex ) {

		}
		wife->invokeMethod( "Informs relatives :)" );
	}
}

void sheSaysYes( Object* wife ) {

	throwOnFalse( wife->getInt( "Heart :)" ) == 0 , "wife->getInt('Heart :)')==0" );

	wife->setInt( "Heart :)" , 1 ); // Sets in her heart that he is HAPPY :), 1 stands for TRUE

	throwOnFalse( wife->getInt( "Heart :)" ) == 1 , "wife->getInt('Heart :)')==1" );

	wife->setInt( "Relatives :)" , 70 );

}
void husbandInformsRelatives( Object* husband ) {
	if ( husband->getInt( "Relatives :)" ) > 0 ) {
		Object* relative_family = Husband_class.newInstance();

		relative_family->invokeMethod( "fifteen_members_set :)" );
		relative_family->invokeMethod( "Congratulations :)" );

		husband->invokeMethod( "Thanks :)" );

		husband->setInt( "Relatives :)" , husband->getInt( "Relatives :)" ) - 1 );

		husband->invokeMethod( "Informs relatives :)" );
	}
}
void wifeInformsRelatives( Object* wife ) {
	if ( wife->getInt( "Relatives :)" ) > 0 ) {
		Object* relative_family = Wife_class.newInstance();

		relative_family->invokeMethod( "fifteen_members_set :)" );
		relative_family->invokeMethod( "Congratulations :)" );

		wife->invokeMethod( "Thanks :)" );

		wife->setInt( "Relatives :)" , wife->getInt( "Relatives :)" ) - 1 );

		wife->invokeMethod( "Informs relatives :)" );

	}
}

void familySaysCongratulations( Object* family ) {
	if ( family->getInt( "Members :)" ) > 0 ) {

		Object* member_family = Family_class.newInstance();

		try {
			member_family->getInt( "Buys a gift for wedding :)" );
			throwOnFalse( false , "false" );
		}
		catch ( FieldNotAccessible& ex ) {

		}
		member_family->invokeMethod( "MemberSaysThanks :)" );

		family->setInt( "Members :)" , family->getInt( "Relatives :)" ) - 1 );

		family->invokeMethod( "Congratulations :)" );
	}
}
void memberSaysThanks( Object* member_family ) {
	member_family->getInt( "Buys a gift for wedding :)" );

}
void thanks( Object* spouse ) {
	spouse->getInt( "Heart :)" );
}

void fiften_members_set( Object* spouse ) {
	spouse->setInt( "Members :)" , 15 );
}
bool testMethodInvokesMethod() {
	try {
		Class::setAccessible( false ); // On purpose, because the interesting part
									   // Is when we check who is the current self
									   // Of a method, like in squeak

		Husband_class.addInstanceField( "Ring :)" , OBJECT );
		Husband_class.addInstanceField( "Heart :)" , INT );
		Husband_class.addInstanceField( "WaitTime :)" , INT );
		Husband_class.addInstanceField( "Relatives :)" , INT );
		Husband_class.addInstanceField( "Members :)" , INT );

		Wife_class.addInstanceField( "Heart :)" , INT );
		Wife_class.addInstanceField( "Relatives :)" , INT );
		Wife_class.addInstanceField( "Members :)" , INT );

		Family_class.addInstanceField( "Buys a gift for wedding :)" , INT );

		Husband_class.addMethod( "Propose :)" , propose );
		Husband_class.addMethod( "Thanks :)" , thanks );
		Husband_class.addMethod( "Hope she says yes :)" , hopeSheSaysYes );
		Husband_class.addMethod( "Informs relatives :)" ,
			husbandInformsRelatives );
		Husband_class.addMethod( "Congratulations :)" ,
			familySaysCongratulations );
		Husband_class.addMethod( "fifteen_members_set :)" , fiften_members_set );

		Wife_class.addMethod( "She smiles and says yes :)" , sheSaysYes );
		Wife_class.addMethod( "Informs relatives :)" , wifeInformsRelatives );
		Wife_class.addMethod( "Congratulations :)" , familySaysCongratulations );
		Wife_class.addMethod( "Thanks :)" , thanks );
		Wife_class.addMethod( "fifteen_members_set :)" , fiften_members_set );

		Family_class.addMethod( "Congratulations :)" , familySaysCongratulations );
		Family_class.addMethod( "MemberSaysThanks :)" , memberSaysThanks );

		int happy_husbands_and_wifes = 100;

		for ( int i = 0; i < happy_husbands_and_wifes; i++ ) {

			Object* husband = Husband_class.newInstance();

			husband->invokeMethod( "Propose :)" );
		}

	}
	catch ( std::exception& e ) {
		std::cout << e.what() << std::endl;
		return false;
	}
	return true;

}

/*******************************Tests Invoke :)********************************/
/******************************************************************************/
/******************************************************************************/

Class RunTime_class( nullptr , "RunTime" );
Class ExceptionInRunTime_class( nullptr , "ExceptionInRunTime" );

void runTime( Object* runTime ) {
	if ( runTime->getInt( "Time :)" ) > 0 ) {

		runTime->setInt( "Time :)" , runTime->getInt( "Time :)" ) - 1 );
		runTime->invokeMethod( "runTime :)" );
	}
	else {
		try {
			ExceptionInRunTime_class.newInstance()->invokeMethod(
				"exceptionInRunTime :)" );
		}
		catch ( FieldNotAccessible& ex ) {
			throw ex;
		}
		throwOnFalse( false , "false" ); // Should never get here :)
		runTime->getInt( "Time :)" ); // Should never get here :)
	}
}

void exceptionInRunTime( Object* exceptionInRunTime ) {
	Husband_class.newInstance()->getInt( "Heart :)" );

}
/******************************************************************************/
/******************************************************************************/
/*******************************Tests Exception :)*****************************/
bool testMethodCallsExceptionValgrind() {
	try {
		Class::setAccessible( false ); // On purpose, because the interesting part
									   // Is when we check who is the current self
									   // Of a method, like in squeak

		RunTime_class.addInstanceField( "Time :)" , INT );
		RunTime_class.addMethod( "runTime :)" , runTime );
		ExceptionInRunTime_class.addMethod( "exceptionInRunTime :)" ,
			exceptionInRunTime );
		Object* run = RunTime_class.newInstance();
		try {
			run->invokeMethod( "runTime :)" );
		}
		catch ( FieldNotAccessible& ex ) {

		}

		try {
			run->getInt( "Time :)" );  // Not accessible ^^, remember?
			throwOnFalse( false , "false" ); // The reason I built this test,
											 // Is to deal with exception thrown in method
											 // And how we remember who is the last who has
											 // permission to access his own members :)
		}
		catch ( FieldNotAccessible& ex ) {

		}
	}
	catch ( std::exception& e ) {
		std::cout << e.what() << std::endl;
		return false;
	}
	return true;
}
/*******************************Tests Exception :)*****************************/
/******************************************************************************/
/******************************************************************************/

bool testWin() {
	return true && printTestSuccessOrFail( testExample() , "testExample" )
		&& printTestSuccessOrFail( testField() , "testField" )
		&& printTestSuccessOrFail( testMethod() , "testMethod" )
		&& printTestSuccessOrFail( testObject() , "testObject" )
		&& printTestSuccessOrFail( testClass() , "testClass" )
		&& printTestSuccessOrFail( testSameFieldName() , "testSameFieldName" )
		&& printTestSuccessOrFail( testMethodInvokesMethod() ,
			"testMethodInvokesMethod" )
		&& printTestSuccessOrFail( testMethodCallsExceptionValgrind() ,
			"testMethodCallsExceptionValgrind" );

}

/******************************************************************************/
/******************************************************************************/
/*******************************Tests section :)*******************************/

int main() {

	printTestSuccessOrFail( testWin() , "testWin" );

	return 0;

}
