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
#include <string>


class SymboleVar : public Symbole
{
public:
    
    SymboleVar();
    SymboleVar(const SymboleVar& orig);
    virtual ~SymboleVar();
    std::string toString();
    SymboleVar(Type *t);
private:
    
    // type, valeur, code 3@

};

#endif	/* SYMBOLEVAR_HPP */

