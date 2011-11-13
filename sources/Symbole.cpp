/* 
 * File:   Symbole.cpp
 * Author: p0700785
 * 
 * Created on 14 octobre 2011, 10:11
 */

#include "../headers/Symbole.hpp"

Symbole::Symbole() {
}

Symbole::Symbole(Type t){
    this->T = t;
}

Symbole::Symbole(const Symbole& orig) {
}

Symbole::~Symbole() {
}

void Symbole::toString(std::ostream &flux) const
{
    flux << "tests";
}


std::ostream &operator<<(std::ostream &flux, Symbole const& sym)
{
    sym.toString(flux) ; // <- Changement ici
    return flux;
}


