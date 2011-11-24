/* 
 * File:   Valeur.hpp
 * Author: bilal
 *
 * Created on 24 novembre 2011, 19:49
 */

#ifndef VALEUR_HPP
#define	VALEUR_HPP

#include "TableId.hpp"
#include "Type.hpp"


class Valeur {
public:
    Valeur(Type* t);
    Valeur(Type* t, int i);
    Valeur(Type* t, float f);
    Valeur(Type* t, std::string* s);
    Valeur(Type* t, bool b);
    ~Valeur();

private:
    Type* type;
    int i;
    float f;
    bool b;
    std::string* s;
        
    Type* getT();

    bool getValeurBool();
    int getValeurInteger();
    float getValeurFloat();
    std::string* getValeurString();

    void setType(Type* _type);


};

#endif	/* VALEUR_HPP */

