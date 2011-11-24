/* 
 * File:   TypeChar.hpp
 * Author: bart
 *
 * Created on 19 novembre 2011, 22:41
 */

#ifndef TYPECHAR_HPP
#define	TYPECHAR_HPP

#include "Type.hpp"

class TypeChar : public Type
{
public:
    TypeChar();
    TypeChar(const TypeChar& orig);
    ~TypeChar();
    std::string getClass();
    bool operator ==(Type const& T1);
private:

};

#endif	/* TYPECHAR_HPP */

