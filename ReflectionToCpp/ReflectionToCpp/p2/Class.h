#ifndef CLASS_H_
#define CLASS_H_
#include <unordered_map>
#include <list>
#include <vector>

class Class;



#include <string>
#include "Object.h"
#include "Method.h"
#include "Field.h"
using namespace std;

typedef unordered_map< string , Member* > MemberMap;
typedef unordered_map< string , Class* > ClassMap;
typedef pair< string , Member* > ClassMemberPair;
typedef pair< string , Class* > ClassMapPair;

class ClassNotFound : public exception {};


class Class {

public:
	/**
	 * \brief creates a new class with a name.
	 * \param c the super class of that class.
	 * \param name the name of the class.
	 */
	Class(Class* c, const string name);

	/**
	 * \brief get the super class.
	 * \return the super class.
	 */
	Class* getSuperClass() const;

	/**
	 * \brief create a new instance of that class.
	 * \return the new object that was created.
	 */
	Object* newInstance();

	/**
	 * \brief adds a new method to the class.
	 * \param name the name of the new method. 
	 * \param func a function pointer to the function.
	 */
	void addMethod(string name, Func func);

	/**
	 * \brief add a field to the class (instance field).
	 * \param name the name of the field
	 * \param t the type of the field.
	 */
	void addInstanceField(string name, Type t);


	/**
	 * \brief add a static field to the class (class instance).
	 * \param name the name of the static field.
	 * \param t the type of the field.
	 */
	void addStaticField(string name, Type t);

	/**
	 * \brief get the field with the name.
	 * \param name the name of the field.
	 * \return a copy of the field . if no field was found FieldNotFound exception will be thrown.
	 */
	Field getField(string name);

	/**
	 * \brief get the field with the name.
	 * \param name the name of the field.
	 * \return the original field that was found. if no field was found FieldNotFound exception will be thrown.
	 */
	Field* getOriginalField(string name, bool searchAll, bool isStatic);

	/**
	 * \brief the all the fields of the class (and all the fields from inherited classes)
	 * \return a list of all the fields of the class.
	 */
	list<Field> getFields();

	/**
	 * \brief all the static fields of the class (and all the static fields from inherited classes).
	 * \return a list of all the static fields of the class.
	 */
	list<Field> getStaticFields();

	Method getMethod(string name);

	list<Method> getMethods();


	/**
	 * \brief the the int value of a static field.
	 * \param name the name of the field.
	 * \return the integer value of the field. if no such field exist FieldNotFound exception will be thrown.
	 */
	int getInt(string name);

	/**
	 * \brief set the int value of a static field.
	 * \param name the name of the field.
	 * \param value the integer value of the field. if no such field exist FieldNotFound exception will be thrown.
	 */
	void setInt(string name, int value);

	/**
	 * \brief get the object value of field with name.
	 * \param name the name of the field.
	 * \return the object value.
	 */
	Object* getObj(string name);

	/**
	 * \brief set the field with object value.
	 * \param name the name of the field.
	 * \param value the value to set.
	 */
	void setObj(string name, Object* value);


	/**
	 * \brief the name of the class.
	 * \return the name of the class
	 */
	string name() const;

	~Class();

	/**
	 * \brief setting the class to be accessible to private fields.
	 * \param flag true/false value.
	 */
	static void setAccessible(bool flag);

	/**
	 * \brief 
	 * \return 
	 */
	static bool isAccessible();


	static Class* forName(string name);
private:
	Class* parent;
	string className;
	//map of name->member
	MemberMap members;
	vector<Object*> classInstances;
	static bool isAccessibleClass;
	//static ClassMap classMap;

	static ClassMap&  getClassMapInstance();

	void addMember(string name, Member* member);


	template<typename DYNAMIC_TYPE , typename STATIC_TYPE>
	static bool instanceof( const STATIC_TYPE *ptr ) {
		return dynamic_cast<const DYNAMIC_TYPE*>( ptr ) != nullptr;
	}


	//generic lookups for all members
	template <typename MEMBER>
	list<MEMBER> getMembersOfType() {
		Class* currentClass = this;
		list<MEMBER> list;
		while (nullptr != currentClass){
			if ( currentClass->members.size() > 0 ) {
				for ( auto it = currentClass->members.begin(); it != currentClass->members.end(); ++it ) {
					Member* member = it->second;
					if ( instanceof<MEMBER>( member ) ) {
						MEMBER* castedMember = static_cast< MEMBER* >( member );
						list.push_back( *castedMember );
					}
				}
			}
			currentClass = currentClass->getSuperClass();
		}
		return list;
	}

	template <class MEMBER, class MEMBER_NOT_FOUND_EXCEPTION>
	MEMBER* getMember(string name,bool searchAll,bool staticMember) {
		Member* member = nullptr;

		Class* currentClass = this;
		while (currentClass != nullptr)
		{
			MemberMap::iterator iterator_result = currentClass->members.find(name);
			if (iterator_result == currentClass->members.end()) { currentClass = currentClass->getSuperClass(); }
			else{
				member = iterator_result->second;
				if ( !searchAll ) { // do we need to search all, or just instance field/static fields?
					if ( member->isStatic() != staticMember ) { //we did'nt really found the member so we keep looking
						currentClass = currentClass->getSuperClass();
						continue;
					}
				}
				break;
			}
		}

		if (currentClass != nullptr && instanceof<MEMBER>(member))
		{
			MEMBER* castedMember = static_cast<MEMBER*>(member);
			return castedMember;
		}

		throw MEMBER_NOT_FOUND_EXCEPTION();
	}

	Field* fetchClassField(const string& fieldName);

	void updateInstancesAccess(bool flag);
};

#endif /* CLASS_H_ */
