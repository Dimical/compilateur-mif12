/* 
 * File:   TableSymb.hpp
 * Author: p0700785
 *
 * Created on 14 octobre 2011, 11:20
 */

#ifndef TABLESYMB_HPP
#define	TABLESYMB_HPP

#include "Symbole.hpp"
#include "SymboleVar.hpp"
#include "TableId.hpp"
#include "Type.hpp"
#include "TypeEntier.hpp"

class TableSymb {

public:
    TableSymb();
    void Ajout(Symbole *Sym, int i);
    //void AjoutVar(SymboleVar Sym);
    //void AjoutProg(SymboleProg Sym);
    void Afficher(TableId Tid);
     TableSymb(const TableSymb& orig);
    ~TableSymb(void);

    Symbole * getSymbole(int id);
    void Test();

    int getNbrsym();

    std::map<int, Symbole *> TS; // Notre map
private:
    
};

#endif	/* TABLESYMB_HPP */

