#ifndef MEMBER_H
#define MEMBER_H
#include <string>
using namespace std;
enum Privacy { PUBLIC , PRIVATE , PROTECTED };
/**
 * An abstract class that describe the members of a class.
 */
class Member {
public:
	

	Member( const string & member_name , const string & class_name , Privacy p=PRIVATE );
	//Member is an abstract Class so we make the destractor pure virtual
	virtual ~Member() = 0;

	virtual string name() const;
	virtual string getDeclaringClass() const;


protected:
	Privacy privacy;
private:
	string memberName;
	string className;


};

#endif
