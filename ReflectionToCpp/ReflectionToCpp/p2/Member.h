#ifndef MEMBER_H
#define MEMBER_H
#include <string>


/**
 * An abstract class that describe the members of a class.
 */
class Member {
public:
	enum Privacy { PUBLIC , PRIVATE , PROTECTED };

	Member( const std::string & member_name , const std::string & class_name , Privacy p=PRIVATE );
	//Member is an abstract Class so we make the destractor pure virtual
	virtual ~Member() = 0;

	virtual std::string name() const;
	virtual std::string getDeclaringClass() const;


protected:
	Privacy privacy;
private:
	std::string memberName;
	std::string className;


};

#endif
