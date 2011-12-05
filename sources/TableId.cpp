/* 
 * File:   TableID.cpp
 * Author: josh
 * 
 * Created on 14 octobre 2011, 09:00
 */

#include "../headers/TableId.hpp"

using namespace std;

TableId::TableId(void)
{
    //this->Champ.insert( std::map<int, std::string>::value_type(0, "a"));
    //this->Champ.insert( std::map<int, std::string>::value_type(1, "b"));
}
int TableId::Ajout(std::string id)
{
    // On recupere le numéro correspondant à notre identificateur
    int valeur= getnumTOid(id);
    if(valeur==-2) // Si l'identificateur n'a pas été trouvé, il doit renvoyer -2
    {
        //cout<<"Valeur non trouvé"<<endl;
        // Ensuite on renvoi son nouveau numéro correspondant
        this->Champ[Champ.size()]= id;
        return Champ.size()-1;

    }
    else
    {
        // L'identificateur a été trouvé, on renvoi son numéro
        return valeur;
    }


}
void TableId::Affichage()
{
    // On créer notre itérateur sur notre map
    std::map<int, std::string>::const_iterator iter;
    cout << "+++IdentificatorTable" <<endl;
    for (iter= Champ.begin(); iter !=Champ.end(); ++iter)
    {
        // on affichage le numéro avec son identifiant
        cout<< "\t    " << (iter->first)+1 << " : " << iter->second <<endl;
    }
    cout << "---IdentificatorTable" <<endl;

}
int TableId::getnumTOid(std::string id) // Dans tous les cas, on est obligé de tester si un identificateur est dans la table
{
    // On créer notre itérateur sur notre map
    std::map<int, std::string>::const_iterator iter;
    for (iter= Champ.begin(); iter !=Champ.end(); ++iter)
    {
        if(id == iter->second) // On teste s'il a trouvé notre élement
        {
            //cout<<"Valeur trouvee au num : "<<iter->first<<endl;
            return iter->first;
        }

    }
    return -2; // il ne l'a pas trouvé


}
std::string TableId::getidTOnum(int num)
{
    return this->Champ[num];

}

TableId::~TableId(void)
{

}

