/* 
 * File:   Symbole.hpp
 * Author: p0700785
 *
 * Created on 14 octobre 2011, 10:11
 */

#ifndef SYMBOLE_HPP
#define	SYMBOLE_HPP

#include "TableId.hpp"


class Symbole{

private:
    int identif; // notre numéro de la classe TableID


public:
    Symbole();
    Symbole(const Symbole& orig);
    ~Symbole();

};

#endif	/* SYMBOLE_HPP */

