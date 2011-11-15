/* 
 * File:   Symbole.cpp
 * Author: p0700785
 * 
 * Created on 14 octobre 2011, 10:11
 */

#include "../headers/Symbole.hpp"
using namespace std;

Symbole::Symbole() {
}

Symbole::Symbole(Type t){
    this->T = t;
}

Symbole::Symbole(const Symbole& orig) {
}

Symbole::~Symbole() {
}

std::ostream & Symbole::toString(std::ostream &flux) const
{
    return flux << "testSymb";
}


inline ostream &operator<<(ostream &flux,const Symbole& sym)
{
    
     // <- Changement ici
    return sym.toString(flux) ;
}


