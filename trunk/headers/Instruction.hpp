/* 
 * File:   Instruction.hpp
 * Author: bilal
 *
 * Created on 25 novembre 2011, 19:09
 */

#ifndef INSTRUCTION_HPP
#define	INSTRUCTION_HPP

//#include "Etiquette.hpp"
#include "CodeInstruction.hpp"
#include "Operande.hpp"
#include "TableId.hpp"


class Instruction {
public:
    Instruction();
    Instruction(const Instruction& orig);

    // constructeur d'instruction avec une étiquette et un codeInstruction
    Instruction(/*std::string Etiquette,*/ std::string Opera, Operande *Resultat, Operande *Arg1, Operande *Arg2, TableId *TI);
    Instruction(std::string Opera, int idResult, int idArgument, TableId *TI);
    Instruction(std::string Etiquette, std::string Opera);
    ~Instruction();

    std::string getOperateur(); // retourne simplement le nom de l'operateur


    std::string getaffichageLigne();

private:

    std::string Etiquette;
    CodeInstruction *CodeInstr; // va nous permettre d'utiliser les opérations

    Operande * Res;
    Operande * Operan1;
    Operande * Operan2;

    std::string Operateur;

    std::string Ligne3adresses;

};

#endif	/* INSTRUCTION_HPP */

