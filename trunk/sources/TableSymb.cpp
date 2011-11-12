/* 
 * File:   TableSymb.cpp
 * Author: p0700785
 * 
 * Created on 14 octobre 2011, 11:20
 */

#include "../headers/TableSymb.hpp"

using namespace std;

TableSymb::TableSymb(void) {
}

void TableSymb::Ajout(Symbole Sym) {
    cout << "ajout " << TS.size() << endl;
    this->TS[TS.size()] = Sym;
}
void TableSymb::Afficher(TableId Tid)
{
    for(int i=0; i < TS.size(); i++)
    {
        cout << Tid.getidTOnum(i) <<"\t"<< TS.at(i).toString() <<endl;
    }
    /*std::map<int, Symbole>::iterator iter;
    for(iter= TS.begin(); iter != TS.end(); ++iter)
    {
        //cout << iter->first << "\t" << iter->second << "\n" << endl;
         cout << iter->first <<"\t"<< iter->second.toString()<< endl;
    }*/
}
TableSymb::~TableSymb(void)
{

}

