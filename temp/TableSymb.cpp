/* 
 * File:   TableSymb.cpp
 * Author: p0700785
 * 
 * Created on 14 octobre 2011, 11:20
 */

#include "../headers/TableSymb.hpp"
#include <iostream>
#include <string>
#include <sstream>
#include <map>
using namespace std;

TableSymb::TableSymb(void) {
}

void TableSymb::Ajout(Symbole Sym, int id) {
    cout << "ajout " << TS.size() << endl;
    this->TS[TS.size()] = Sym;
}

void TableSymb::Afficher() {
    std::map<int, Symbole>::iterator iter;
    for(iter= TS.begin(); iter != TS.end(); ++iter)
    {
        //cout << iter->first << "\t" << iter->second << "\n" << endl;
         cout << iter->first << " " << iter->second << "." << endl;
    }
    

}



TableSymb::~TableSymb(void)
{

}

