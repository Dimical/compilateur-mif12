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

class Symbole{

private:
    Type T;
    
public:
    Symbole();
    Symbole(const Symbole& orig);
    ~Symbole();

};

#endif	/* SYMBOLE_HPP */
