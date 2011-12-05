/* 
 * File:   SymboleEtiquette.hpp
 * Author: remi
 *
 * Created on 1 novembre 2011, 15:59
 */

#ifndef SYMBOLEETIQUETTE_HPP
#define	SYMBOLEETIQUETTE_HPP

#include "Symbole.hpp"
#include <string>

class SymboleEtiquette : public Symbole
{
public:
    SymboleEtiquette();
    SymboleEtiquette(const SymboleEtiquette& orig);
    virtual ~SymboleEtiquette();
    std::string toString();
    Type * getType();

private:

};

#endif	/* SymboleEtiquette_HPP */

