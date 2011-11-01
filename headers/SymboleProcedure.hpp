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

class SymboleProcedure : public Symbole
{
public:
    SymboleProcedure();
    SymboleProcedure(const SymboleProcedure& orig);
    virtual ~SymboleProcedure();

private:
    //on fait une reference sur une autre table de symbole
    TableSymb * TabS;
};

#endif	/* SYMBOLEPROCEDURE_HPP */

