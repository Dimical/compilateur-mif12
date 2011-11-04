/* 
 * File:   SymboleCst.hpp
 * Author: bilal
 *
 * Created on 21 octobre 2011, 16:53
 */

#ifndef SYMBOLECST_HPP
#define	SYMBOLECST_HPP

#include "Symbole.hpp"
#include "Type.hpp"
#include <string>


class SymboleCst : public Symbole
{
public:

    SymboleCst();
    SymboleCst(const SymboleCst& orig);
    virtual ~SymboleCst();
   // std::string toString();

private:
    
    // type, valeur, code 3@

};

#endif	/* SYMBOLECST_HPP */

