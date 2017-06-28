#pragma once
#ifndef CLASS_DS_H
#define CLASS_DS_H
#include <unordered_map>
#include "Member.h"
#include "Field.h"
typedef std::unordered_map<std::string , Member*> MemberMap;
typedef std::unordered_map<std::string , Field*>  FieldMap;
typedef std::unordered_map<std::string ,Class*> ClassMap;

typedef std::pair<std::string , Field*>  FieldMapPair;
typedef std::pair<std::string , Member*> ClassMemberPair;
typedef std::pair<std::string , Class*> ClassMapPair;
typedef std::list<Field> FieldList;

template<typename DYNAMIC_TYPE , typename STATIC_TYPE>
bool instanceof( const STATIC_TYPE *ptr ) {
	return dynamic_cast<const DYNAMIC_TYPE*>( ptr ) != nullptr;
}
#endif