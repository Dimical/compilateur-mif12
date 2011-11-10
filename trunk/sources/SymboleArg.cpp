/* 
 * File:   SymboleArg.cpp
 * Author: bilal
 * 
 * Created on 1 novembre 2011, 16:32
 */


#include "../headers/SymboleArg.hpp"

SymboleArg::SymboleArg() {
}

SymboleArg::SymboleArg(Type t, bool b, int pos){
    this->T=t;
    this->variable=b;
    this->position=pos;
}

SymboleArg::SymboleArg(const SymboleArg& orig) {
}

SymboleArg::~SymboleArg() {
}
/*std::string toString(){
    return("");
}*/
