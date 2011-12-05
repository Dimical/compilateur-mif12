/* 
 * File:   CodeInstruction.hpp
 * Author: bilal
 *
 * Created on 26 novembre 2011, 10:10
 */

#ifndef CODEINSTRUCTION_HPP
#define	CODEINSTRUCTION_HPP

#include "Operande.hpp"
#include "TableId.hpp"

class CodeInstruction {
public:
    CodeInstruction();
    CodeInstruction(const CodeInstruction& orig);
    ~CodeInstruction();


    // Le debut de prog 3 adresses
    std::string Deb();


    // LES FONCTIONS DE L'OP ADD ----------------------------

    // ligne code 3 adresses avec 3 operandes
    std::string Add(TableId *TI, Operande *resultat, Operande *Arg1, Operande *Arg2);
    // ligne code 3 adresses avec 2 operandes
    std::string Add(TableId *TI, Operande *Arg1, Operande *Arg2);


    // LES FONCTIONS DE L'OP SUB ----------------------------
    // ligne code 3 adresses avec 3 operandes
    std::string Sub(TableId *TI, Operande *resultat, Operande *Arg1, Operande *Arg2);
    // ligne code 3 adresses avec 2 operandes
    std::string Sub(Operande *Arg1, Operande *Arg2);


    std::string Cpy(TableId *TI, Operande* Res, Operande* Arg1);
    std::string If(TableId *TI, Operande* Res, Operande* Arg2);

    // LES EXPRESSIONS BOOLEENES
    std::string And(TableId *TI, Operande* Res, Operande* Arg1, Operande* Arg2);
    std::string Or(TableId *TI, Operande* Res, Operande* Arg1, Operande* Arg2);
    std::string Xor(TableId *TI, Operande* Res, Operande* Arg1, Operande* Arg2);
    std::string Not(TableId *TI, Operande* Res, Operande* Arg1);

    // LES FONCTIONS DE L'OP MUL
    std::string Mul(TableId *TI, Operande *resultat, Operande *Arg1, Operande *Arg2);

    // LES FONCTIONS DE L'OP DIV
    std::string Div(TableId* TI, Operande* resultat, Operande* Arg1, Operande* Arg2);

    // LES FONCTIONS DE L'OP MOD
    std::string Mod(TableId* TI, Operande* resultat, Operande* Arg1, Operande* Arg2);

private:

};

#endif	/* CODEINSTRUCTION_HPP */

