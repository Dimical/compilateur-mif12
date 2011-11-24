/* 
 * File:   TypesString.hpp
 * Author: bilal
 *
 * Created on 4 novembre 2011, 16:58
 */

#ifndef TYPESTRING_HPP
#define	TYPESTRING_HPP

class TypeString {
public:
    TypeString();
    TypeString(const TypeString& orig);
    std::string getClass();
    virtual ~TypeString();
private:

};

#endif	/* TYPESSTRING_HPP */

