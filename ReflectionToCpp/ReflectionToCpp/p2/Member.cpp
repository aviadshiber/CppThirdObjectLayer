#include "Member.h"



Member::Member( const string & member_name , const string & class_name , Privacy p ):privacy( p ) ,
memberName( member_name ) ,
className( class_name )
{

}

Member::~Member() {}

string Member::getDeclaringClass() const {
	return this->className;
}

string Member::name() const
{
	return memberName;
}
