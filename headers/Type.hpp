/* 
 * File:   Type.hpp
 * Author: bilal
 *
 * Created on 21 octobre 2011, 16:29
 */

#ifndef TYPE_HPP
#define	TYPE_HPP

class Type {
public:
    Type();
    Type(const Type& orig);
    virtual ~Type();
private:
    bool operator==( Type const&T1);
};

#endif	/* TYPE_HPP */

