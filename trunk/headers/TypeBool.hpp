/* 
 * File:   TypeBool.hpp
 * Author: bilal
 *
 * Created on 4 novembre 2011, 17:02
 */

#ifndef TYPEBOOL_HPP
#define	TYPEBOOL_HPP

#include "Type.hpp"

class TypeBool : public Type{
public:
    TypeBool();
    TypeBool(const TypeBool& orig);
    std::string getClass();
    ~TypeBool();
private:

};

#endif	/* TYPEBOOL_HPP */

