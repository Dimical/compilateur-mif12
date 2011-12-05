/* 
 * File:   TypeInterval.cpp
 * Author: bart
 * 
 * Created on 26 novembre 2011, 10:43
 */
#include <cstdio>
#include <iostream>
#include <sstream>  
#include "../headers/TypeInterval.hpp"

using namespace std;

TypeInterval::TypeInterval() {
}

TypeInterval::TypeInterval(int _deb, int _fin){
    deb = _deb;
    fin = _fin;
}

TypeInterval::TypeInterval(const TypeInterval& orig) {
}

TypeInterval::~TypeInterval() {
}

int TypeInterval::getDeb(){
    return deb;
}
int TypeInterval::getFin(){
    return fin;
}


std::string TypeInterval::convertInt(int number)
{
   std::stringstream ss;//create a stringstream
   ss << number;//add number to the stream
   return ss.str();//return a string with the contents of the stream
}

std::string TypeInterval::getClass() {
    std::string retour = "interval{integer,";
    retour += convertInt(deb);
    retour += ",";
    retour += convertInt(fin);
    retour += "}";
    return retour;
}

