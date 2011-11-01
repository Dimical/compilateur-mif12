/* 
 * File:   SymboleVar.hpp
 * Author: bilal
 *
 * Created on 21 octobre 2011, 16:48
 */

#ifndef SYMBOLEVAR_HPP
#define	SYMBOLEVAR_HPP

#include "Symbole.hpp"


class SymboleVar : public Symbole
{
public:
    Type value;
    // type, valeur, code 3@
    
    SymboleVar();
    SymboleVar(const SymboleVar& orig);
    virtual ~SymboleVar();
private:

};

#endif	/* SYMBOLEVAR_HPP */

