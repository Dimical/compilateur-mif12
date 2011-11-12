/* 
 * File:   TypeEntier.cpp
 * Author: bilal
 * 
 * Created on 4 novembre 2011, 15:17
 */

#include <string>

#include "../headers/TypeEntier.hpp"

TypeEntier::TypeEntier() {
}

TypeEntier::TypeEntier(const TypeEntier& orig) {
}

TypeEntier::~TypeEntier() {
}

std::string Type::getClass() {
    return"integer";
}

//bool TypeEntier::operator ==(Type T1)
//{
////    if(this == T1)
////        return true;
//    return false;
//}

