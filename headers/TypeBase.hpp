/* 
 * File:   Type.hpp
 * Author: p0700785
 *
 * Created on 14 octobre 2011, 10:37
 */

#ifndef TYPEBASE_HPP
#define	TYPEBASE_HPP

class TypeBase: public Type
{
public:
    TypeBase();
    TypeBase(const TypeBase& orig);
    virtual ~TypeBase();
private:
    TypeBase operator+( TypeBase &T1, TypeBase &T2 );
    bool operator==( TypeBase const&T1, TypeBase const&T2);

};

#endif	/* TYPE_HPP */

