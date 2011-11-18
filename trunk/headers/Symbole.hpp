/* 
 * File:   Symbole.hpp
 * Author: p0700785
 *
 * Created on 14 octobre 2011, 10:11
 */

#ifndef SYMBOLE_HPP
#define	SYMBOLE_HPP

#include "TableId.hpp"
#include "Type.hpp"
#include <iostream>

class Symbole{

protected:
    Type T;
    
public:
    // classe abstraite
    Symbole();
    Symbole(Type t);
    Symbole(const Symbole& orig);
    virtual ~Symbole();
    virtual std::string toString();

    //friend std::ostream &operator<<(std::ostream &flux, Symbole const& sym);

};

#endif	/* SYMBOLE_HPP */

