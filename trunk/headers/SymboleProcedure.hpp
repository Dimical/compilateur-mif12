/* 
 * File:   SymboleProcedure.hpp
 * Author: bilal
 *
 * Created on 1 novembre 2011, 16:03
 */

#ifndef SYMBOLEPROCEDURE_HPP
#define	SYMBOLEPROCEDURE_HPP

#include "Symbole.hpp"
#include "TableSymb.hpp"
#include <string>

class SymboleProcedure : public Symbole
{
public:
    SymboleProcedure();
    SymboleProcedure(const SymboleProcedure& orig);
    virtual ~SymboleProcedure();
  //  std::string toString();

private:
    //on fait une reference sur une autre table de symbole
    TableSymb * TabS;
    int arite; //nombre d'arguments
};

#endif	/* SYMBOLEPROCEDURE_HPP */

