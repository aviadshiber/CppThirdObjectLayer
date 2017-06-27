#include "Member.h"
#include "Class.h"


Member::Member(const std::string& member_name, const std::string& class_name,Privacy p=PRIVATE):
	privacy(p),
	memberName(member_name),
	className(class_name) {}

Member::~Member() {}

std::string Member::getDeclaringClass() const {
	return this->className;
}

std::string Member::name() const
{
	return memberName;
}
