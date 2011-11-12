/* 
 * File:   TypeEntier.hpp
 * Author: bilal
 *
 * Created on 4 novembre 2011, 15:17
 */

#ifndef TYPEENTIER_HPP
#define	TYPEENTIER_HPP

#include "Type.hpp"


class TypeEntier : public Type
{
public:
    TypeEntier();
    TypeEntier(const TypeEntier& orig);
    ~TypeEntier();
    bool operator ==(Type const& T1);
private:
    
};

#endif	/* TYPEENTIER_HPP */

