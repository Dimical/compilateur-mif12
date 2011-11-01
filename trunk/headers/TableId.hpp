/* 
 * File:   TableID.hpp
 * Author: josh
 *
 * Created on 14 octobre 2011, 09:00
 */

#ifndef TABLEID_HPP
#define	TABLEID_HPP


#include <map>
#include <string>
#include <iostream>
//#include "boost/config.h"
//#include "boost/bimap/bimap.h"

class TableId
{
    std::map<int, std::string> Champ; // Notre map
public:
    int Ajout(std::string id); // fonction d'ajout d'un identificateur
    void Affichage(); // méthode d'affichage

    // Nos accesseurs
    int getnumTOid(std::string id);
    std::string getidTOnum(int num);

    TableId(void);
    ~TableId(void);
};


#endif	/* TABLEID_HPP */

