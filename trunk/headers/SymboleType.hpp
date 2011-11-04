/* 
 * File:   SymboleType.hpp
 * Author: bilal
 *
 * Created on 1 novembre 2011, 16:38
 */

#ifndef SYMBOLETYPE_HPP
#define	SYMBOLETYPE_HPP

#include "Symbole.hpp"
#include "Type.hpp"
#include <string>

class SymboleType : public Symbole
{
public:
    SymboleType();
    SymboleType(const SymboleType& orig);
    virtual ~SymboleType();
   // std::string toString();

private:
    
};

#endif	/* SYMBOLETYPE_HPP */

