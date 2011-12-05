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

using namespace std;


class SymboleCst : public Symbole
{
public:

    SymboleCst(Type *t, string v);
    SymboleCst(const SymboleCst& orig);
    virtual ~SymboleCst();
    Type * getType();
    std::string toString();

private:
    string value;
    // type, valeur, code 3@

};

#endif	/* SYMBOLECST_HPP */

