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


class SymboleCst : public Symbole
{
public:

    SymboleCst();
    SymboleCst(const SymboleCst& orig);
    virtual ~SymboleCst();

private:
    Type value;
    // type, valeur, code 3@

};

#endif	/* SYMBOLECST_HPP */

