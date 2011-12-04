/* 
 * File:   GeneraleConteneur.cpp
 * Author: bilal
 * 
 * Created on 26 novembre 2011, 00:03
 */

#include "../headers/GeneraleConteneur.hpp"

GeneraleConteneur::GeneraleConteneur() {
}

GeneraleConteneur::GeneraleConteneur(const GeneraleConteneur& orig) {
}

GeneraleConteneur::~GeneraleConteneur() {
}
void GeneraleConteneur::ajouterConteneurCode(ConteneurCode Conteneur){
    //if(Conteneur != NULL)
    //    listeConteneurCode.push_back(Conteneur);

}
void GeneraleConteneur::initialiser(){

    CourantConteneur = new ConteneurCode(); // on initialise notre conteneur courant

}
void GeneraleConteneur::affichage(){
    

}
