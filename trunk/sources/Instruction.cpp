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
Instruction::Instruction(std::string Etiquette, std::string Opera)
{
    this->Operateur = Opera;
    if(this->Operateur == "DEB")
    {
        this->Ligne3adresses = Etiquette + " : " + "\t" + this->CodeInstr->Deb();
    }
    
}
Instruction::Instruction(/*std::string Etiquette, */std::string Opera, Operande *Resultat, Operande *Arg1, Operande *Arg2, TableId *TI)
{
    //this->Eti= new Etiquette(Et);
    // on teste si nos expressions sont correctes

    this->Res= Resultat;
    this->Operan1= Arg1;
    this->Operan2= Arg2;

    this->Operateur = Opera;

    //this->Etiquette = Etiquette;
    
    if(this->Operateur == "ADD")
    {
        //if(Et != NULL)
        //{
            this->Ligne3adresses = /*Et->toString() +*/ "\t" + this->CodeInstr->Add(TI, this->Res, this->Operan1, this->Operan2);
                                                    // on teste si nos expressions sont correctes

        //}
    }
    else if(this->Operateur == "SUB")
    {
        //if(Et != NULL)
        //{
            this->Ligne3adresses = /*Et->toString() + */"\t" + this->CodeInstr->Sub(TI, this->Res, this->Operan1, this->Operan2);
        //}
    }
    else if(this->Operateur == "CPY")
    {
        //if(Et != NULL)
        //{
            this->Ligne3adresses = /*Et->toString() + */"\t" + this->CodeInstr->Cpy(TI, this->Res, this->Operan1);
        //}
    }
    else if(this->Operateur == "MUL")
    {
        this->Ligne3adresses = "\t" + this->CodeInstr->Mul(TI, this->Res, this->Operan1, this->Operan2);
    }
    else if(this->Operateur == "DIV")
    {
        this->Ligne3adresses = "\t" + this->CodeInstr->Div(TI, this->Res, this->Operan1, this->Operan2);
    }
    else if(this->Operateur == "MOD")
    {
        this->Ligne3adresses = "\t" + this->CodeInstr->Mod(TI, this->Res, this->Operan1, this->Operan2);
    }
    else if(this->Operateur == "AND")
    {
        this->Ligne3adresses = "\t" + this->CodeInstr->And(TI, this->Res, this->Operan1, this->Operan2);
    }
    else if(this->Operateur == "IF")
    {
        this->Ligne3adresses = /*this->Etiquette + "\t" +*/ "\t" + this->CodeInstr->If(TI, this->Res, NULL);

    }
        else if(this->Operateur == "OR")
    {
        this->Ligne3adresses = "\t" + this->CodeInstr->Or(TI, this->Res, this->Operan1, this->Operan2);
    }
    else if(this->Operateur == "XOR")
    {
        this->Ligne3adresses = "\t" + this->CodeInstr->Xor(TI, this->Res, this->Operan1, this->Operan2);
    }
    else if(this->Operateur == "NOT")
    {
        this->Ligne3adresses = "\t" + this->CodeInstr->Not(TI, this->Res, this->Operan1);
    }
    else if(this->Operateur == "EQ")
    {
        this->Ligne3adresses = "\t" + this->CodeInstr->Eq(TI, this->Res, this->Operan1, this->Operan2);
    }
    else if(this->Operateur == "NEQ")
    {
        this->Ligne3adresses = "\t" + this->CodeInstr->Neq(TI, this->Res, this->Operan1, this->Operan2);
    }
    else if(this->Operateur == "LT")
    {
        this->Ligne3adresses = "\t" + this->CodeInstr->Lt(TI, this->Res, this->Operan1, this->Operan2);
    }
    else if(this->Operateur == "LTE")
    {
        this->Ligne3adresses = "\t" + this->CodeInstr->Lte(TI, this->Res, this->Operan1, this->Operan2);
    }
    else if(this->Operateur == "GT")
    {
        this->Ligne3adresses = "\t" + this->CodeInstr->Gt(TI, this->Res, this->Operan1, this->Operan2);
    }
    else if(this->Operateur == "GTE")
    {
        this->Ligne3adresses = "\t" + this->CodeInstr->Gte(TI, this->Res, this->Operan1, this->Operan2);
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

