/* 
 * File:   SymboleFonction.cpp
 * Author: bilal
 * 
 * Created on 1 novembre 2011, 16:23
 */

#include "../headers/SymboleFonction.hpp"
#include <sstream>  

SymboleFonction::SymboleFonction(): Symbole() {
}
SymboleFonction::SymboleFonction(Type *t, int ar) {
    this->T=t;
    this->arite=ar;
}

std::string SymboleFonction::convertInt(int number)
{
   std::stringstream ss;//create a stringstream
   ss << number;//add number to the stream
   return ss.str();//return a string with the contents of the stream
}


SymboleFonction::SymboleFonction(const SymboleFonction& orig) {
}

SymboleFonction::~SymboleFonction() {
}

std::string SymboleFonction::toString(){
    std::string s = "Function\t[arity:" + convertInt(this->arite) + " type:" + T->getClass() +(std::string)"]";
    return s;
}

Type * SymboleFonction::getType()
{
    return this->T;
}

