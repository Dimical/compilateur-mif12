/* 
 * File:   TableSymb.hpp
 * Author: p0700785
 *
 * Created on 14 octobre 2011, 11:20
 */

#ifndef TABLESYMB_HPP
#define	TABLESYMB_HPP

#include "Symbole.hpp"
#include "TableId.hpp"

class TableSymb {

public:
    TableSymb();
    TableSymb(const TableSymb& orig);
    ~TableSymb();
private:
    std::map<int, Symbole> TS; // Notre map

};

#endif	/* TABLESYMB_HPP */

