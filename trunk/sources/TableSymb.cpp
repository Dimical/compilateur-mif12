/* 
 * File:   TableSymb.cpp
 * Author: p0700785
 * 
 * Created on 14 octobre 2011, 11:20
 */

#include "../headers/TableSymb.hpp"

using namespace std;

TableSymb::TableSymb(void) {
}

void TableSymb::Ajout(Symbole Sym, int id) {
    this->TS[id] = Sym;
}

void TableSymb::Afficher() {
    std::map<int, Symbole>::const_iterator iter;
    for(iter= TS.begin(); iter != TS.end(); ++iter)
    {
     //   cout<<iter->first<<"\t"<< iter->second<<"\n"<<endl;
    }
}

TableSymb::~TableSymb(void)
{

}

