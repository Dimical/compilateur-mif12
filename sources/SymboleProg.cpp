/* 
 * File:   SymboleProg.cpp
 * Author: bilal
 * 
 * Created on 1 novembre 2011, 15:59
 */

#include <string.h>

#include "../headers/SymboleProg.hpp"

SymboleProg::SymboleProg(): Symbole() {
}

SymboleProg::SymboleProg(const SymboleProg& orig) {
}

SymboleProg::~SymboleProg() {
}

std::string SymboleProg::toString(){
    return "Programme\t[]";
}

Type * SymboleProg::getType()
{
    return this->T;
}