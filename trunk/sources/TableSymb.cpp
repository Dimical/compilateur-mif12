/* 
 * File:   TableSymb.cpp
 * Author: p0700785
 * 
 * Created on 14 octobre 2011, 11:20
 */

#include "../headers/TableSymb.hpp"

using namespace std;

TableSymb::TableSymb(string n, TableSymb* t) {
    this->nom = n;
    this->tSymbMere = t;
}

void TableSymb::Ajout(Symbole *Sym, int i) {
    this->TS[i] = Sym;
}
void TableSymb::Afficher(TableId Tid)
{
    string tSymM;
    if (this->tSymbMere == NULL)
        tSymM = "None";
    else
        tSymM = this->tSymbMere->getName();
    
    cout << "+++SymbolTable(" << this->getName() << ": "<< tSymM << ")" << endl;
    for (map<int, Symbole*>::iterator it = TS.begin(); it != TS.end(); ++it){
        cout << Tid.getidTOnum(it->first) <<"\t" << TS.at(it->first)->toString()<<endl;
    }

    cout << "---SymbolTable(" << this->getName() << ": "<< tSymM << ")" << endl;

}
TableSymb::~TableSymb(void)
{

}

string TableSymb::getName(void){
    return nom;
}

Symbole *TableSymb::getSymbole(int id)
{
    return this->TS[id];
}
int TableSymb::getNbrsym()
{
    return this->TS.size();
}
