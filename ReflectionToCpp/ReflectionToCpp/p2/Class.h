#ifndef CLASS_H_
#define CLASS_H_
#include <unordered_map>


class Class;


#include <string>
#include "Object.h"
#include "Method.h"
#include "Field.h"


typedef std::unordered_map< std::string , Member* > MemberMap;
typedef std::unordered_map< std::string , Class* > ClassMap;
typedef std::pair< std::string , Member* > ClassMemberPair;
typedef std::pair< std::string , Class* > ClassMapPair;

class ClassNotFound : public std::exception {};


class Class {

public:
	/**
	 * \brief creates a new class with a name.
	 * \param c the super class of that class.
	 * \param name the name of the class.
	 */
	Class(Class* c, const std::string& name);

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
	void addMethod(std::string name, Func func);

	/**
	 * \brief add a field to the class (instance field).
	 * \param name the name of the field
	 * \param t the type of the field.
	 */
	void addInstanceField(std::string name, Type t);


	/**
	 * \brief add a static field to the class (class instance).
	 * \param name the name of the static field.
	 * \param t the type of the field.
	 */
	void addStaticField(std::string name, Type t);

	/**
	 * \brief get the field with the name.
	 * \param name the name of the field.
	 * \return a copy of the field . if no field was found FieldNotFound exception will be thrown.
	 */
	Field getField(std::string name);

	/**
	 * \brief get the field with the name.
	 * \param name the name of the field.
	 * \return the original field that was found. if no field was found FieldNotFound exception will be thrown.
	 */
	Field* getOriginalField(std::string name);

	/**
	 * \brief the all the fields of the class (and all the fields from inherited classes)
	 * \return a list of all the fields of the class.
	 */
	std::list<Field> getFields();

	/**
	 * \brief all the static fields of the class (and all the static fields from inherited classes).
	 * \return a list of all the static fields of the class.
	 */
	std::list<Field> getStaticFields();

	Method getMethod(std::string name);

	std::list<Method> getMethods();


	/**
	 * \brief the the int value of a static field.
	 * \param name the name of the field.
	 * \return the integer value of the field. if no such field exist FieldNotFound exception will be thrown.
	 */
	int getInt(std::string name);

	/**
	 * \brief set the int value of a static field.
	 * \param name the name of the field.
	 * \param value the integer value of the field. if no such field exist FieldNotFound exception will be thrown.
	 */
	void setInt(std::string name, int value);

	/**
	 * \brief get the object value of field with name.
	 * \param name the name of the field.
	 * \return the object value.
	 */
	Object* getObj(std::string name);

	/**
	 * \brief set the field with object value.
	 * \param name the name of the field.
	 * \param value the value to set.
	 */
	void setObj(std::string name, Object* value);


	/**
	 * \brief the name of the class.
	 * \return the name of the class
	 */
	std::string name() const;

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


	static Class* forName(std::string name);
private:
	Class* parent;
	std::string className;
	//map of name->member
	MemberMap members;
	std::vector<Object*> classInstances;
	static bool isAccessibleClass;
	static ClassMap classMap;

	void addMember(std::string name, Member* member);


	template<typename DYNAMIC_TYPE , typename STATIC_TYPE>
	static bool instanceof( const STATIC_TYPE *ptr ) {
		return dynamic_cast<const DYNAMIC_TYPE*>( ptr ) != nullptr;
	}


	//generic lookups for all members
	template <typename MEMBER>
	std::list<MEMBER> getMembersOfType() {
		Class* currentClass = this;
		std::list<MEMBER> list;
		while (nullptr != currentClass &&  currentClass->members.size()>0){

			for (auto it = currentClass->members.begin(); it != currentClass->members.end(); ++it){
				Member* member = it->second;
				if (instanceof<MEMBER>(member)){
					MEMBER* method = static_cast<MEMBER*>(member);
					list.push_back(*method);
				}
			}
			currentClass = currentClass->getSuperClass();
		}
		return list;
	}

	template <class MEMBER, class MEMBER_NOT_FOUND_EXCEPTION>
	MEMBER* getMember(std::string name) {
		Member* member = nullptr;

		Class* currentClass = this;
		while (currentClass != nullptr)
		{
			MemberMap::iterator iterator_result = currentClass->members.find(name);
			if (iterator_result == currentClass->members.end()) { currentClass = currentClass->getSuperClass(); }
			else
			{
				member = iterator_result->second;
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

	Field* fetchClassField(const std::string& fieldName);

	void updateInstancesAccess(bool flag);
};

#endif /* CLASS_H_ */
