
#ifndef EXCPETIONS_H_
#define EXCPETIONS_H_
#include <exception>



enum Type{ INT , OBJECT};

class FieldNotFound: public std::exception {
};
class FieldNotAccessible: public std::exception {
};

class MethodNotFound : public std::exception{};

class TypeError : public std::exception{};

class ClassNotFound : public std::exception{};



#endif /* EXCPETIONS_H_ */
