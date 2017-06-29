
#ifndef EXCPETIONS_H_
#define EXCPETIONS_H_
#include <exception>


enum Type{ INT , OBJECT};

class FieldNotFound: public std::exception {
public:
	virtual const char* what() const throw () {
			return "FIELD NOT FOUND WAS THROWN!!! :(";
		}
};
class FieldNotAccessible: public std::exception {
public:
	virtual const char* what() const throw () {
				return "FIELD NOT ACCESSIBLE WAS THROWN!!!:(";
			}
};

class MethodNotFound : public std::exception{
public:
	virtual const char* what() const throw () {
					return "METHOD NOT FOUND WAS THROWN!!!:(";
				}
};

class TypeError : public std::exception{
public:
	virtual const char* what() const throw () {
					return "TYPE ERROR WAS THROWN!!!:(";
				}

};




#endif /* EXCPETIONS_H_ */
