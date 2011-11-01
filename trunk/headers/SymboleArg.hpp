/* 
 * File:   SymboleArg.hpp
 * Author: bilal
 *
 * Created on 1 novembre 2011, 16:32
 */

#ifndef SYMBOLEARG_HPP
#define	SYMBOLEARG_HPP

#include "Symbole.hpp"
#include "Type.hpp"

class SymboleArg : public Symbole
{
public:
    SymboleArg();
    SymboleArg(const SymboleArg& orig);
    virtual ~SymboleArg();

private:
    Type value;


};

#endif	/* SYMBOLEARG_HPP */

