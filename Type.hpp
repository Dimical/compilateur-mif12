/* 
 * File:   Type.hpp
 * Author: p0700785
 *
 * Created on 14 octobre 2011, 10:37
 */

#ifndef TYPE_HPP
#define	TYPE_HPP

class Type
{
public:
    Type();
    Type(const Type& orig);
    virtual ~Type();
private:
    Type operator+( Type &T1, Type &T2 );
    bool operator==( Type const&T1, Type const&T2);

};

#endif	/* TYPE_HPP */

