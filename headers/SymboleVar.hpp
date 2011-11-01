/* 
 * File:   SymboleVar.hpp
 * Author: bilal
 *
 * Created on 21 octobre 2011, 16:48
 */

#ifndef SYMBOLEVAR_HPP
#define	SYMBOLEVAR_HPP

#include "Symbole.hpp"
#include "Type.hpp"


class SymboleVar : public Symbole
{
public:
    
    SymboleVar();
    SymboleVar(const SymboleVar& orig);
    virtual ~SymboleVar();

private:
    Type value;
    // type, valeur, code 3@

};

#endif	/* SYMBOLEVAR_HPP */

