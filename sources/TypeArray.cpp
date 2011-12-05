/* 
 * File:   TypeArray.cpp
 * Author: bart
 * 
 * Created on 26 novembre 2011, 10:15
 */

#include "../headers/TypeArray.hpp"
#include <vector>
#include <cstddef>
#include <cstdio>
#include <iostream>

using namespace std;

TypeArray::TypeArray() {
}

TypeArray::TypeArray(Type* _ty, vector <TypeInterval*> _listInterval) {
    typeArray = _ty;
    cout << "icicicicici" << &_listInterval <<endl;
    vector<TypeInterval*> *temp = new vector<TypeInterval*>(_listInterval);
    //vector <TypeInterval*> temp (_listInterval);
    listInterval = temp;
}

TypeArray::TypeArray(const TypeArray& orig) {
}

TypeArray::~TypeArray() {
}

std::string TypeArray::getClass() {
    string retour = "";

    cout << "après" << listInterval->size() << endl;
    for (unsigned int i=0;i<listInterval->size(); i++){
        retour += ",";
        retour += listInterval->at(i)->getClass();
    }
    return"array{"+typeArray->getClass()+retour+"}";
}
