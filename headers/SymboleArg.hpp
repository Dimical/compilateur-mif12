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
#include <string>

class SymboleArg : public Symbole
{
public:
    SymboleArg();
    SymboleArg(const SymboleArg& orig);
    SymboleArg(Type t, bool b, int pos);
    virtual ~SymboleArg();
   // std::string toString();

private:
    bool variable;
    int position;


};

#endif	/* SYMBOLEARG_HPP */

