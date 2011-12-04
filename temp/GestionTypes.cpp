/* 
 * File:   GestionTypes.cpp
 * Author: bilal
 * 
 * Created on 25 novembre 2011, 22:18
 */
#include "../headers/GestionTypes.hpp"

using namespace std;

GestionTypes::GestionTypes() {
}

GestionTypes::GestionTypes(const GestionTypes& orig) {
}

GestionTypes::~GestionTypes() {
}

/*Type GestionTypes::ExpressionCompare(std::string operation, Type* t1, Type* t2)
{
    if(operation == "ADD")
    {
        if(t1.getClass() == "integer")
        {
            if(t2.getClass() == "integer")
            {
                return (new TypeEntier); // on retourne le type du résultat
            }
            else if(t2.getClass() == "real")
            {

                return (new TypeReel); // on retourne le type du résultat
            }
            else // un autre type impossible
            {
                cout<<"error: T'es bête ou quoi? Les types sont incompatibles!"<<endl;
                return NULL;
            }
        }
        if(t1.getClass() == "real")
        {
            if(t2.getClass() == "integer")
            {
                return (new TypeReel); // on retourne le type du résultat
            }
            else if(t2.getClass() == "real")
            {

                return (new TypeReel); // on retourne le type du résultat
            }
            else // un autre type impossible
            {
                cout<<"error: T'es bête ou quoi? Les types sont incompatibles!"<<endl;
                return NULL;
            }
        }
        if(t1.getClass() == "string")
        {
            if(t2.getClass() == "string")
            {
                return (new TypeString);// on retourne le type du résultat
            }
            else // un autre type impossible
            {
                cout<<"error: T'es bête ou quoi? Les types sont incompatibles!"<<endl;
                return NULL;
            }
        }
        else
        {
            cout<<"error: Types incompatibles de l'expression";
        }
    }
}*/
