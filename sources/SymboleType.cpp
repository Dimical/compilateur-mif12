/* 
 * File:   SymboleType.cpp
 * Author: bilal
 * 
 * Created on 1 novembre 2011, 16:38
 */

#include "../headers/SymboleType.hpp"

SymboleType::SymboleType(): Symbole() {
}

SymboleType::SymboleType(const SymboleType& orig) {
}

SymboleType::~SymboleType() {
}

Type * SymboleType::getType()
{
    return this->T;
}

//std::string toString(){
//    return("");
//}
