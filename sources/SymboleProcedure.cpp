/* 
 * File:   SymboleProcedure.cpp
 * Author: bilal
 * 
 * Created on 1 novembre 2011, 16:03
 */

#include <sstream>  
#include "../headers/SymboleProcedure.hpp"

SymboleProcedure::SymboleProcedure(): Symbole() {
}

SymboleProcedure::SymboleProcedure(int arit) {
    /*std::cout<< "SymboleProcedure::SymboleProcedure(int arit) a=" << arit << std::endl;*/
    this->arite=arit;
}

SymboleProcedure::SymboleProcedure(const SymboleProcedure& orig) {
}

SymboleProcedure::~SymboleProcedure() {
}

std::string convertInt(int number)
{
   std::stringstream ss;//create a stringstream
   ss << number;//add number to the stream
   return ss.str();//return a string with the contents of the stream
}

std::string SymboleProcedure::toString(){
    std::string s = "Procedure\t[arity:" + convertInt(this->arite) + (std::string)"]";
    return s;
}

void SymboleProcedure::setArite(int a){
    this->arite = a;
}

Type * SymboleProcedure::getType()
{
    return this->T;
}