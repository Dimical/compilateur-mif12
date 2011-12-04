/* 
 * File:   SymboleProg.hpp
 * Author: bilal
 *
 * Created on 1 novembre 2011, 15:59
 */

#ifndef SYMBOLEPROG_HPP
#define	SYMBOLEPROG_HPP

#include "Symbole.hpp"
#include <string>

class SymboleProg : public Symbole
{
public:
    SymboleProg();
    SymboleProg(const SymboleProg& orig);
    virtual ~SymboleProg();
    std::string toString();
    Type * getType();

private:

};

#endif	/* SYMBOLEPROG_HPP */

