/* 
 * File:   TypeInterval.hpp
 * Author: bart
 *
 * Created on 26 novembre 2011, 10:43
 */

#ifndef TYPEINTERVAL_HPP
#define	TYPEINTERVAL_HPP

#include"Type.hpp"

class TypeInterval : public Type{
public:
    TypeInterval();
    TypeInterval(int _deb, int _fin);
    TypeInterval(const TypeInterval& orig);
    virtual ~TypeInterval();
    std::string convertInt(int number);
    std::string getClass();
    int getDeb();
    int getFin();

private:
    int deb;
    int fin;

};

#endif	/* TYPEINTERVAL_HPP */

