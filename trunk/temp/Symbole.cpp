/* 
 * File:   Symbole.cpp
 * Author: p0700785
 * 
 * Created on 14 octobre 2011, 10:11
 */

#include "../headers/Symbole.hpp"

using namespace std;

Symbole::Symbole() {
}

Symbole::Symbole(Type t){
    this->T = t;
}

Symbole::Symbole(const Symbole& orig) {
}

Symbole::~Symbole() {
}

//std::string toString(){
//    return "";
//}

std::ostream& operator<<(std::ostream& s, const Symbole& sym)
{
s << sym.toString();
}
