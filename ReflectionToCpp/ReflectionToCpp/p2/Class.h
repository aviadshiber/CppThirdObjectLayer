#ifndef CLASS_H_
#define CLASS_H_
#include "Object.h"
#include "Field.h"
#include <list>
#include "Method.h"
#include "ClassDS.h"
#include <regex>


class Class{

public:
	Class(Class* c, const std::string& name);

	Class* getSuperClass();
	
	Object* newInstance();

	void addMethod(std::string name, Func func);
	
	void addInstanceField(std::string name, Type t);

	void addStaticField(std::string name, Type t);

	Field getField(std::string name);

	std::list<Field> getFields();

	Method getMethod(std::string name);

	std::list<Method> getMethods();

	int getInt(std::string name);

	void setInt(std::string name, int value);

	Object* getObj(std::string name);

	void setObj(std::string name, Object* value);
	
	std::string name() const;

	static void setAccessible(bool flag);

	static Class* forName( std::string name );
private:
	static bool isAccessibleClass = false;
	static ClassMap classMap=ClassMap();
	Class* parent;
	std::string className;
	//map of name->member
	MemberMap members;
	//map of name->static fields
	FieldMap staticFields;
	std::vector<Object*> classInstances;
public:
	//generic lookups 
	template<typename MEMBER>
	std::list<MEMBER> getMembersOfType() {
		std::list<MEMBER> list;
		for ( auto it = members.begin(); it != members.end(); ++it ) {
			Member* member = it->second;
			if ( instanceof<MEMBER>( member ) ) {
				MEMBER * method = static_cast<MEMBER*>( member );
				list.push_back( *method );
			}
		}
		return list;
	}
	template<class MEMBER,class MEMBER_NOT_FOUND_EXCEPTION>
	MEMBER* getMember( std::string name ) {
		Member* member = nullptr;

		Class* currentClass = this;
		while ( currentClass != nullptr )
		{
			MemberMap::iterator iterator_result = currentClass->members.find( name );
			if ( iterator_result == members.end() ) { currentClass = currentClass->getSuperClass(); }
			else {
				member = iterator_result->second;
				break;
			}
		}

		if ( currentClass != nullptr && instanceof<MEMBER>( member ) )
		{
			MEMBER* castedMember = static_cast<MEMBER*>( member );
			return castedMember;
		}

		throw MEMBER_NOT_FOUND_EXCEPTION();
	}

};

#endif /* CLASS_H_ */
