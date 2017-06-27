#ifndef MEMBER_H
#define MEMBER_H
#include <string>



class Member {
public:
	enum Privacy { PUBLIC , PRIVATE , PROTECTED };

	Member( const std::string & member_name , const std::string & class_name , Privacy p=PRIVATE );

	virtual ~Member();

	virtual std::string name() const;
	virtual std::string getDeclaringClass() const;

private:
	Privacy privacy;
	std::string memberName;
	std::string className;


};

#endif
