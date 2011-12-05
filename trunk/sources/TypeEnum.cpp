/* 
 * File:   TypeEnum.cpp
 * Author: bart
 * 
 * Created on 5 décembre 2011, 17:30
 */

#include "../headers/TypeEnum.hpp"
#include <vector>

using namespace std;
/*

    std::string getClass();
*/
TypeEnum::TypeEnum(vector<string> v) {
    listEnum = new vector<string> (v);
}

TypeEnum::~TypeEnum() {
}

std::string TypeEnum::getClass(){
    string retour="";
    for (unsigned int i=0;i<listEnum->size(); i++){
        if(i!=0) retour += ",";
        retour += listEnum->at(i);
    }
    return "enumeration{"+retour+"}]";


}


TypeEnumValue::TypeEnumValue(vector<string> v) {
    listEnum = new vector<string> (v);
}

TypeEnumValue::~TypeEnumValue() {
}

std::string TypeEnumValue::getClass(){
    string retour="";
    for (unsigned int i=0;i<listEnum->size(); i++){
        if(i!=0) retour += ",";
        retour += listEnum->at(i);
    }
    return "enumeration{"+retour+"},value:]";


}




/*std::string TypeArray::getClass() {
    for (unsigned int i=0;i<listInterval->size(); i++){
        retour += ",";
        retour += listInterval->at(i)->getClass();
    }
    return"array{"+typeArray->getClass()+retour+"}";
}
*/