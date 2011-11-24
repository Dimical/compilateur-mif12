/* 
 * File:   Type.hpp
 * Author: bilal
 *
 * Created on 21 octobre 2011, 16:29
 */

#ifndef TYPE_HPP
#define	TYPE_HPP
#include <string>

#include <string>

class Type {
public:
    Type();
    Type(const Type& orig);
    virtual ~Type();
    virtual std::string getClass();
    bool operator==( Type const&T1);
    
private:
    
};

#endif	/* TYPE_HPP */

