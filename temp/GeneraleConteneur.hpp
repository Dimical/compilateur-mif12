/* 
 * File:   GeneraleConteneur.hpp
 * Author: bilal
 *
 * Created on 26 novembre 2011, 00:03
 */

#ifndef GENERALECONTENEUR_HPP
#define	GENERALECONTENEUR_HPP

//#include "Code3ad.hpp"
#include "ConteneurCode.hpp"


class GeneraleConteneur {
public:
    GeneraleConteneur();
    GeneraleConteneur(const GeneraleConteneur& orig);
    ~GeneraleConteneur();

    void ajouterConteneurCode(ConteneurCode Conteneur);
    void initialiser(); // on initialise notre Conteneur de code courant


    void affichage(); // affichage de nos conteneurs de code
private:

    ConteneurCode *CourantConteneur; // correspond à notre conteneur courant
    std::vector<ConteneurCode*> listeConteneurCode; // on peut passer par une pile aussi "stack"

    

};

#endif	/* GENERALECONTENEUR_HPP */

