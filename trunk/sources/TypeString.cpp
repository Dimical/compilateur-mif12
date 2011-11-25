/* 
 * File:   TypesString.cpp
 * Author: bilal
 * 
 * Created on 4 novembre 2011, 16:58
 */

#include "../headers/TypeString.hpp"

TypeString::TypeString() {
}

TypeString::TypeString(const TypeString& orig) {
}

TypeString::~TypeString() {
}

std::string TypeString::getClass() {
    return"string";
}