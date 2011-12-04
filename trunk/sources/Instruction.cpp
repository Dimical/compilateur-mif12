/* 
 * File:   Instruction.cpp
 * Author: bilal
 * 
 * Created on 25 novembre 2011, 19:09
 */

#include "../headers/Instruction.hpp"
using namespace std;


Instruction::Instruction() {
}

Instruction::Instruction(const Instruction& orig) {
}

Instruction::~Instruction() {
}
Instruction::Instruction(/*Etiquette* Et,*/ std::string Opera, Operande *Resultat, Operande *Arg1, Operande *Arg2, TableId *TI){
    //this->Eti= new Etiquette(Et);
                                        // on teste si nos expressions sont correctes

    this->Res= Resultat;
    this->Operan1= Arg1;
    this->Operan2= Arg2;

    this->Operateur = Opera;
    
    if(this->Operateur == "ADD")
    {
        //if(Et != NULL)
        //{
            this->Ligne3adresses = /*Et->toString() +*/ this->CodeInstr->Add(TI, this->Res, this->Operan1, this->Operan2);
                                                    // on teste si nos expressions sont correctes

        //}
    }
    else if(this->Operateur == "SUB")
    {
        //if(Et != NULL)
        //{
            this->Ligne3adresses = /*Et->toString() + */this->CodeInstr->Add(TI, this->Res, this->Operan1, this->Operan2);
        //}
    }
    else if(this->Operateur == "CPY")
    {
        //if(Et != NULL)
        //{
            this->Ligne3adresses = /*Et->toString() + */this->CodeInstr->Cpy(TI, this->Res, this->Operan1);
        //}
    }

}
std::string Instruction::getaffichageLigne()
{
    return this->Ligne3adresses;
}
std::string Instruction::getOperateur()
{
    if(Operateur != "")
        return Operateur;
}

