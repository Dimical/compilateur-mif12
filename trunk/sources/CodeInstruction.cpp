/* 
 * File:   CodeInstruction.cpp
 * Author: bilal
 * 
 * Created on 26 novembre 2011, 10:10
 */

#include <iosfwd>
#include <sstream>

#include "../headers/CodeInstruction.hpp"


using namespace std;

CodeInstruction::CodeInstruction() {
}

CodeInstruction::CodeInstruction(const CodeInstruction& orig) {
}

CodeInstruction::~CodeInstruction() {
}
std::string CodeInstruction::Deb()
{
    std::string retour = "nop" ;
    return retour;
}
std::string CodeInstruction::Add(TableId *TI, Operande* resultat, Operande* Arg1, Operande* Arg2)
{
    std::string retour;
    std::ostringstream out1;
    std::ostringstream out2;
    
    retour = TI->getidTOnum(resultat->getId()) + " = ";
    if(Arg1->EstCalculee())
    {
        if(Arg1->getValeur()->getT()->getClass() == "integer")
            out1 << Arg1->getValeur()->getValeurInteger();
        else{
            if(Arg1->getValeur()->getT()->getClass() == "real")
                out1 << Arg1->getValeur()->getValeurFloat();
            else{
                if(Arg1->getValeur()->getT()->getClass() == "string")
                        out1 << Arg1->getValeur()->getValeurString();
            }
        }
        
        retour += out1.str()+ " + ";
       

    }
    else{
        cout << "debugelse" << endl;
        cout <<endl << "ce ne sont pas des calculées" <<TI->getidTOnum(Arg1->getId()) <<endl;
        retour += TI->getidTOnum(Arg1->getId()) + " + ";
    }
    if(Arg2->EstCalculee()){
        if(Arg2->getValeur()->getT()->getClass() == "integer")
            out2 << Arg2->getValeur()->getValeurInteger();
        else{
            if(Arg2->getValeur()->getT()->getClass() == "real")
                out2 << Arg2->getValeur()->getValeurFloat();
            else{
                if(Arg2->getValeur()->getT()->getClass() == "string")
                        out2 << Arg2->getValeur()->getValeurString();
            }
        }
        retour += out2.str();
    }
    else{
        retour += TI->getidTOnum(Arg2->getId());
    }
    //retour = TI->getidTOnum(resultat->getId()) + " = " + out1.str() + " + " + out2.str();
    return retour;
}

std::string CodeInstruction::Add(TableId *TI, Operande* Arg1, Operande* Arg2)
{

}
std::string CodeInstruction::Sub(TableId *TI, Operande* resultat, Operande* Arg1, Operande* Arg2)
{
    std::string retour;
    std::ostringstream out1;
    std::ostringstream out2;

    retour = TI->getidTOnum(resultat->getId()) + " = ";
    if(Arg1->EstCalculee())
    {
        if(Arg1->getValeur()->getT()->getClass() == "integer")
            out1 << Arg1->getValeur()->getValeurInteger();
        else{
            if(Arg1->getValeur()->getT()->getClass() == "real")
                out1 << Arg1->getValeur()->getValeurFloat();
        }

        retour += out1.str()+ " - ";


    }
    else{
        retour += TI->getidTOnum(Arg1->getId()) + " - ";
    }
    if(Arg2->EstCalculee()){
        if(Arg2->getValeur()->getT()->getClass() == "integer")
            out2 << Arg2->getValeur()->getValeurInteger();
        else{
            if(Arg2->getValeur()->getT()->getClass() == "real")
                out2 << Arg2->getValeur()->getValeurFloat();
        }
        retour += out2.str();
    }
    else{
        retour += TI->getidTOnum(Arg2->getId());
    }
    //retour = TI->getidTOnum(resultat->getId()) + " = " + out1.str() + " + " + out2.str();
    return retour;

}
std::string CodeInstruction::Sub(Operande* Arg1, Operande* Arg2)
{

}
std::string CodeInstruction::Cpy(TableId *TI, Operande* Res, Operande* Arg1)
{
    std::string retour;
    retour = TI->getidTOnum(Res->getId()) + " = " + TI->getidTOnum(Arg1->getId());
    return retour;
}
std::string CodeInstruction::Mul(TableId* TI, Operande* resultat, Operande* Arg1, Operande* Arg2)
{
    std::string retour;
    std::ostringstream out1;
    std::ostringstream out2;

    retour = TI->getidTOnum(resultat->getId()) + " = ";
    if(Arg1->EstCalculee())
    {
        if(Arg1->getValeur()->getT()->getClass() == "integer")
            out1 << Arg1->getValeur()->getValeurInteger();
        else{
            if(Arg1->getValeur()->getT()->getClass() == "real")
                out1 << Arg1->getValeur()->getValeurFloat();
        }

        retour += out1.str()+ " x ";


    }
    else{
        retour += TI->getidTOnum(Arg1->getId()) + " x ";
    }
    if(Arg2->EstCalculee()){
        if(Arg2->getValeur()->getT()->getClass() == "integer")
            out2 << Arg2->getValeur()->getValeurInteger();
        else{
            if(Arg2->getValeur()->getT()->getClass() == "real")
                out2 << Arg2->getValeur()->getValeurFloat();
        }
        retour += out2.str();
    }
    else{
        retour += TI->getidTOnum(Arg2->getId());
    }
    return retour;
}
std::string CodeInstruction::Div(TableId* TI, Operande* resultat, Operande* Arg1, Operande* Arg2)
{
    std::string retour;
    std::ostringstream out1;
    std::ostringstream out2;

    retour = TI->getidTOnum(resultat->getId()) + " = ";
    if(Arg1->EstCalculee())
    {
        if(Arg1->getValeur()->getT()->getClass() == "integer")
            out1 << Arg1->getValeur()->getValeurInteger();
        else{
            if(Arg1->getValeur()->getT()->getClass() == "real")
                out1 << Arg1->getValeur()->getValeurFloat();
        }

        retour += out1.str()+ " / ";


    }
    else{
        retour += TI->getidTOnum(Arg1->getId()) + " / ";
    }
    if(Arg2->EstCalculee()){
        if(Arg2->getValeur()->getT()->getClass() == "integer")
            out2 << Arg2->getValeur()->getValeurInteger();
        else{
            if(Arg2->getValeur()->getT()->getClass() == "real")
                out2 << Arg2->getValeur()->getValeurFloat();
        }
        retour += out2.str();
    }
    else{
        retour += TI->getidTOnum(Arg2->getId());
    }
    return retour;
}
std::string CodeInstruction::Mod(TableId* TI, Operande* resultat, Operande* Arg1, Operande* Arg2)
{
    std::string retour;
    std::ostringstream out1;
    std::ostringstream out2;

    retour = TI->getidTOnum(resultat->getId()) + " = ";
    if(Arg1->EstCalculee())
    {
        if(Arg1->getValeur()->getT()->getClass() == "integer")
            out1 << Arg1->getValeur()->getValeurInteger();

        retour += out1.str()+ " % ";
    }
    else{
        retour += TI->getidTOnum(Arg1->getId()) + " % ";
    }
    if(Arg2->EstCalculee()){
        if(Arg2->getValeur()->getT()->getClass() == "integer")
            out2 << Arg2->getValeur()->getValeurInteger();
        
        retour += out2.str();
    }
    else{
        retour += TI->getidTOnum(Arg2->getId());
    }
    return retour;
}
std::string CodeInstruction::If(TableId *TI, Operande* Res, Operande* Arg1)
{
    std::string retour;
    retour = " si " + TI->getidTOnum(Res->getId()) + " aller a ";
    return retour;
}
std::string CodeInstruction::And(TableId* TI, Operande* Res, Operande* Arg1, Operande* Arg2)
{
    std::string retour;
    std::ostringstream out1;
    std::ostringstream out2;

    retour = TI->getidTOnum(Res->getId()) + " = ";
    if(Arg1->EstCalculee())
    {
        if(Arg1->getValeur()->getT()->getClass() == "boolean")
            out1 << Arg1->getValeur()->getValeurInteger();

        retour += out1.str()+ " & ";
    }
    else{
        retour += TI->getidTOnum(Arg1->getId()) + " & ";
    }
    if(Arg2->EstCalculee()){
        if(Arg2->getValeur()->getT()->getClass() == "boolean")
            out2 << Arg2->getValeur()->getValeurInteger();

        retour += out2.str();
    }
    else{
        retour += TI->getidTOnum(Arg2->getId());
    }
    return retour;

}
std::string CodeInstruction::Or(TableId* TI, Operande* Res, Operande* Arg1, Operande* Arg2)
{
    std::string retour;
    std::ostringstream out1;
    std::ostringstream out2;

    retour = TI->getidTOnum(Res->getId()) + " = ";
    if(Arg1->EstCalculee())
    {
        if(Arg1->getValeur()->getT()->getClass() == "boolean")
            out1 << Arg1->getValeur()->getValeurInteger();

        retour += out1.str()+ " || ";
    }
    else{
        retour += TI->getidTOnum(Arg1->getId()) + " || ";
    }
    if(Arg2->EstCalculee()){
        if(Arg2->getValeur()->getT()->getClass() == "boolean")
            out2 << Arg2->getValeur()->getValeurInteger();

        retour += out2.str();
    }
    else{
        retour += TI->getidTOnum(Arg2->getId());
    }
    return retour;

}
std::string CodeInstruction::Xor(TableId* TI, Operande* Res, Operande* Arg1, Operande* Arg2)
{
    std::string retour;
    std::ostringstream out1;
    std::ostringstream out2;

    retour = TI->getidTOnum(Res->getId()) + " = ";
    if(Arg1->EstCalculee())
    {
        if(Arg1->getValeur()->getT()->getClass() == "boolean")
            out1 << Arg1->getValeur()->getValeurInteger();

        retour += out1.str()+ " xor ";
    }
    else{
        retour += TI->getidTOnum(Arg1->getId()) + " xor ";
    }
    if(Arg2->EstCalculee()){
        if(Arg2->getValeur()->getT()->getClass() == "boolean")
            out2 << Arg2->getValeur()->getValeurInteger();

        retour += out2.str();
    }
    else{
        retour += TI->getidTOnum(Arg2->getId());
    }
    return retour;
    
}
std::string CodeInstruction::Not(TableId* TI, Operande* Res, Operande* Arg1)
{
    std::string retour;
    std::ostringstream out1;
    std::ostringstream out2;

    retour = TI->getidTOnum(Res->getId()) + " = ";
    cout <<endl<< " Pour la temporaire son id c'est : "<< TI->getidTOnum(Res->getId()) <<endl;
    if(Arg1->EstCalculee())
    {
        if(Arg1->getValeur()->getT()->getClass() == "boolean")
            out1 << Arg1->getValeur()->getValeurInteger();

        retour += out1.str()+ " ! ";
    }
    else{
        cout << "ON rentre iciciciciciicicicic : " <<TI->getidTOnum(Arg1->getId())<<endl;
        retour +=  " ! " + TI->getidTOnum(Arg1->getId());
    }

    return retour;

}