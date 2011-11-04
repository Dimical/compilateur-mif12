/* 
 * File:   TypeEntier.cpp
 * Author: bilal
 * 
 * Created on 4 novembre 2011, 15:17
 */

#include "../headers/TypeEntier.hpp"

TypeEntier::TypeEntier() {
}

TypeEntier::TypeEntier(const TypeEntier& orig) {
}

TypeEntier::~TypeEntier() {
}
bool TypeEntier::operator ==(Type const&T1)
{
    /*if(this->getClass() == T1->getClass())
        return true;
    return false;*/
    return false;
}
std::string TypeEntier::getClass()
{
    return "toto";
}
