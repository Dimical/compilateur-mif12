/* 
 * File:   Valeur.cpp
 * Author: bilal
 * 
 * Created on 24 novembre 2011, 19:49
 */

#include "../headers/Valeur.hpp"

Valeur::Valeur(Type* t){
    this->type= t;
}
Valeur::Valeur(Type* t, int i){
    this->type= t;
    this->i= i;
}
Valeur::Valeur(Type* t, float f){
    this->type= t;
    this->f= f;
}
Valeur::Valeur(Type* t, std::string* s){
    this->type= t;
    this->s= s;
}
Valeur::Valeur(Type* t, bool b){
    this->type= t;
    this->b= b;
}
Type* Valeur::getT(){
    return this->type;
}

bool Valeur::getValeurBool(){
    if(this->type.getClass() == "boolean")
        return b;
}
int Valeur::getValeurInteger(){
    if(this->type.getClass() == "integer")
        return i;
}
float Valeur::getValeurFloat(){
    if(this->type.getClass() == "float")
        return f;
}
std::string* Valeur::getValeurString(){
    if(this->type.getClass() == "string")
        return s;
}
