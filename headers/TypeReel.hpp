/* 
 * File:   TypeReel.hpp
 * Author: bilal
 *
 * Created on 4 novembre 2011, 16:52
 */

#ifndef TYPEREEL_HPP
#define	TYPEREEL_HPP

#include "Type.hpp"

class TypeReel : public Type{
public:
    TypeReel();
    TypeReel(const TypeReel& orig);
    std::string getClass();
    ~TypeReel();
private:

};

#endif	/* TYPEREEL_HPP */

