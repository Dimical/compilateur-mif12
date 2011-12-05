/* 
 * File:   TypeEnum.hpp
 * Author: bart
 *
 * Created on 5 décembre 2011, 17:19
 */

#ifndef TYPEENUM_HPP
#define	TYPEENUM_HPP


#include"Type.hpp"
#include <vector>

using namespace std;

class TypeEnum : public Type{
public :
    TypeEnum(vector<string> v);
    ~TypeEnum();
    std::string getClass();

private:
    vector<string> * listEnum;

};



#endif	/* TYPEENUM_HPP */

