/* 
 * File:   SymboleFonction.hpp
 * Author: bilal
 *
 * Created on 1 novembre 2011, 16:23
 */

#ifndef SYMBOLEFONCTION_HPP
#define	SYMBOLEFONCTION_HPP

#include "Symbole.hpp"
#include "TableSymb.hpp"
#include "Type.hpp"

class SymboleFonction : public Symbole
{
public:
    SymboleFonction();
    SymboleFonction(const SymboleFonction& orig);
    virtual ~SymboleFonction();

private:
    Type value;
    //on fait une reference sur une autre table de symbole
    TableSymb * TabS;

};

#endif	/* SYMBOLEFONCTION_HPP */

