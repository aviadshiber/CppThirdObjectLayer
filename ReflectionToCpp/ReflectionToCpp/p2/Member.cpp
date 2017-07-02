#include "Member.h"



Member::Member( const string & member_name , const string & class_name , Privacy p , bool isStatic ) :privacy( p ) ,
memberName( member_name ) ,
className( class_name ),staticMember(isStatic)
{
	if ( staticMember ) { privacy = PUBLIC; }
}

Member::~Member() {}

string Member::getDeclaringClass() const {
	return this->className;
}

bool Member::isStatic() const {
	return this->staticMember;
}

string Member::name() const
{
	return memberName;
}
