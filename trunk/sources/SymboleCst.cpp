/* 
 * File:   SymboleCst.cpp
 * Author: bilal
 * 
 * Created on 21 octobre 2011, 16:53
 */

#include "../headers/SymboleCst.hpp"
#include "../headers/Type.hpp"

using namespace std;

SymboleCst::SymboleCst(Type *t, string v){
    this->T=t;
    this->value = v;
}

SymboleCst::SymboleCst(const SymboleCst& orig) {
}

SymboleCst::~SymboleCst() {
}

Type * SymboleCst::getType()
{
    return this->T;
}

string SymboleCst::toString(){
    return "Constant\t[type:"+this->T->getClass()+"]";
}
