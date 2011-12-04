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
    SymboleFonction(Type * tretour, int ar);
    SymboleFonction(const SymboleFonction& orig);
    virtual ~SymboleFonction();
    std::string toString();
    Type * getType();

private:
    std::string convertInt(int number);
    //on fait une reference sur une autre table de symbole
    TableSymb * TabS;
    Type * typeRetour;
    int arite; //nombre d'arguments

};

#endif	/* SYMBOLEFONCTION_HPP */

