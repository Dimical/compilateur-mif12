/* 
 * File:   SymboleEtiquette.cpp
 * Author: bilal
 * 
 * Created on 1 novembre 2011, 15:59
 */

#include <string.h>

#include "../headers/SymboleEtiquette.hpp"

SymboleEtiquette::SymboleEtiquette(): Symbole() {
}

SymboleEtiquette::SymboleEtiquette(const SymboleEtiquette& orig) {
}

SymboleEtiquette::~SymboleEtiquette() {
}

std::string SymboleEtiquette::toString(){
    return "Etiquette\t[]";
}

Type * SymboleEtiquette::getType()
{
    return this->T;
}