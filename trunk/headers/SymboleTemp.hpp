/* 
 * File:   SymboleTemp.hpp
 * Author: bilal
 *
 * Created on 3 décembre 2011, 18:11
 */

#ifndef SYMBOLETEMP_HPP
#define	SYMBOLETEMP_HPP

#include "Symbole.hpp"
#include <string>


class SymboleTemp : public Symbole
{
public:
    SymboleTemp();

    
    SymboleTemp(const SymboleTemp& orig);
    virtual ~SymboleTemp();
    std::string toString();
private:


};

#endif	/* SYMBOLETEMP_HPP */

