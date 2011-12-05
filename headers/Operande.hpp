/*
 * File:   Operande.hpp
 * Author: bilal
 *
 * Created on 24 novembre 2011, 19:41
 */

#ifndef OPERANDE_HPP
#define	OPERANDE_HPP

#include "Valeur.hpp"


class Operande {
public:
    Operande();
    Operande(int numeroId, Valeur *valeur, bool Calculee);
    Operande(const Operande* orig);
    virtual ~Operande();
    int getId();
    Valeur * getValeur();

    bool EstCalculee();


private:

    int numeroIdentificateur; // notre identifiant de la table identificateur
    Valeur *val;// notre valeur correspondante

    bool Calculee;




};

#endif	/* OPERANDE_HPP */
