/*
 * File:   Operande.cpp
 * Author: bilal
 *
 * Created on 24 novembre 2011, 19:41
 */

#include "../headers/Operande.hpp"

Operande::Operande() {
}


Operande::Operande(int numeroId, Valeur *valeur, bool Calculee){
    this->numeroIdentificateur = numeroId;
    this->val = valeur;
    this->Calculee = Calculee;
}

Operande::Operande(const Operande& orig) {
}

Operande::~Operande() {
}

int Operande::getId(){
    int id;
    id = this->numeroIdentificateur;
    return id;
}

Valeur * Operande::getValeur(){
    Valeur *v;
    v = this->val;
    return v;
}
bool Operande::EstCalculee()
{
    return this->Calculee;

}
