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
    TableSymb(std::string, TableSymb*);
    void Ajout(Symbole* Sym, int i);
    //void AjoutVar(SymboleVar Sym);
    //void AjoutProg(SymboleProg Sym);
    void Afficher(TableId Tid);
     TableSymb(const TableSymb& orig);
    ~TableSymb(void);
    std::string getName();

    Symbole * getSymbole(int id);
    void Test();

    int getNbrsym();
private:
    std::map<int, Symbole *> TS; // Notre map
    //le nom de la table (nom de fonction/procedure ou programme principal)
    std::string nom;
    //le pointeur sur la table de symbole mere, null si programme principal
    TableSymb * tSymbMere;
    
};

#endif	/* TABLESYMB_HPP */

