/* 
 * File:   SymboleCst.cpp
 * Author: bilal
 * 
 * Created on 21 octobre 2011, 16:53
 */

#include "../headers/SymboleCst.hpp"
#include "../headers/Type.hpp"

SymboleCst::SymboleCst(): Symbole() {
}

SymboleCst::SymboleCst(Type *t){

}

SymboleCst::SymboleCst(const SymboleCst& orig) {
}

SymboleCst::~SymboleCst() {
}

Type * SymboleCst::getType()
{
    return this->T;
}

//std::string toString(){
//    return("");
//}

