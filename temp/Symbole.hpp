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
using namespace std;

class Symbole{

protected:
    Type T;
    
public:
    // classe abstraite
    Symbole();
    Symbole(Type t);
    Symbole(const Symbole& orig);
    virtual ~Symbole();
    virtual ostream & toString(ostream &flux) const=0;
    friend inline ostream & operator <<(ostream &flux,const Symbole & sym);

};

#endif	/* SYMBOLE_HPP */

