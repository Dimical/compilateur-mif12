/* 
 * File:   TypeArray.hpp
 * Author: bart
 *
 * Created on 26 novembre 2011, 10:15
 */

#ifndef TYPEARRAY_HPP
#define	TYPEARRAY_HPP

#include <vector>
#include "Type.hpp"
#include "TypeInterval.hpp"

using namespace std;

class TypeArray : public Type{
public:
    TypeArray();
    TypeArray(const TypeArray& orig);
    TypeArray(Type* _ty, vector <TypeInterval*> _listInterval);
    std::string getClass();
    ~TypeArray();
private:
    Type* typeArray;
    vector <TypeInterval*> *listInterval;

};


#endif	/* TYPEARRAY_HPP */

