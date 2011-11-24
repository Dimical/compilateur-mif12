#ifndef _ETIQUETTE_
#define _ETIQUETTE_

#include "Symbole.hpp"
#include <string>

class Etiquette : public Symbole {
       
	private: 
	
	int numeroInstruction;
 
	public:
        Etiquette(int _id);
	Etiquette(int _id, std::string _nomEtiquette);
        ~Etiquette();	
	
};


#endif

