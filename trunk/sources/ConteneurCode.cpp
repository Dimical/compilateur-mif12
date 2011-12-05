/* 
 * File:   ConteneurCode.cpp
 * Author: bilal
 * 
 * Created on 24 novembre 2011, 19:27
 */

#include <vector>

#include "../headers/ConteneurCode.hpp"

using namespace std;

ConteneurCode::ConteneurCode() {

}

ConteneurCode::ConteneurCode(const ConteneurCode& orig) {

}

ConteneurCode::~ConteneurCode() {

}
void ConteneurCode::ajouterInstruct(Instruction* instr)
{
    if(instr != NULL)
        listeInstruction.push_back(instr);
    else{
        cout<<"error: instruction is null"<<endl;
    }
}
void ConteneurCode::ajouterBlocInstruct(std::vector <Instruction*> blocInstr)
{
    if(!blocInstr.empty())
    {
        std::vector <Instruction*>::iterator it;
        for(it= blocInstr.begin(); it!= blocInstr.end(); it++)
        {
               this->listeInstruction.push_back(*it);
        }
    }
    else{
        cout<<"error: instruction is empty";
    }

}
void ConteneurCode::affichage()
{
    cout<< "----- Code 3 adresses "<<endl;
    for(int i=0; i < listeInstruction.size(); i++)
    {
        
        cout << listeInstruction.at(i)->getaffichageLigne()<<endl;
    }
     cout<< "-----------------------"<<endl;

}
Operande* ConteneurCode::getValeurCourante(std::string nomVar)
{
    return 0 ;
}
