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
#include <string>

class SymboleFonction : public Symbole
{
public:
    SymboleFonction();
    SymboleFonction(const SymboleFonction& orig);
    virtual ~SymboleFonction();
   // std::string toString();

private:
    //on fait une reference sur une autre table de symbole
    TableSymb * TabS;
    int arite; //nombre d'arguments

};

#endif	/* SYMBOLEFONCTION_HPP */

