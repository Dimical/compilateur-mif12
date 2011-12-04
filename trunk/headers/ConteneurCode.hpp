/* 
 * File:   ConteneurCode.h
 * Author: bilal
 *
 * Created on 24 novembre 2011, 19:27
 */

#ifndef CONTENEURCODE_H
#define	CONTENEURCODE_H

#include "Instruction.hpp"

class ConteneurCode {
public:
    ConteneurCode();
    ConteneurCode(const ConteneurCode& orig);// copie de conteneur
    ~ConteneurCode();

    void ajouterInstruct(Instruction* instr);
    void ajouterBlocInstruct(std::vector <Instruction*> blocInstr);
    void affichage();
    Operande* getValeurCourante(std::string nomVar);
private:

    int nbrInstru; // notre nombre d'instructions dans notre vecteur
    std::vector<Instruction*> listeInstruction; // notre liste d'instruction
};

#endif	/* CONTENEURCODE_H */

