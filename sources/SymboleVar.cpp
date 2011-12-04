/* 
 * File:   SymboleVar.cpp
 * Author: bilal
 * 
 * Created on 21 octobre 2011, 16:48
 */

#include "../headers/SymboleVar.hpp"

SymboleVar::SymboleVar(): Symbole() {
}

SymboleVar::SymboleVar(Type *t) {
    this->T=t;
}

SymboleVar::SymboleVar(const SymboleVar& orig) {
}

SymboleVar::~SymboleVar() {
}

std::string SymboleVar::toString(){
    return "Variable\t[type:"+this->T->getClass()+"]";
}

Type * SymboleVar::getType()
{
    return this->T;
}