#include "../headers/Etiquette.hpp"


using namespace std;

Etiquette::Etiquette(int _id)
{

	std::string categorie = "etiquette";
	int id = _id;
	type = NULL;
	nomSymbole = new string("");	

	static int _numeroInstruction = 0;
	numeroInstruction = _numeroInstruction;
	_numeroInstruction++;

}


Etiquette::Etiquette(int _id, string _nomEtiquette){

	categorie = new string("etiquette"); 
	id = _id;
	type = NULL;
	nomSymbole = new string(_nomEtiquette);

	static int _numeroInstruction = 0;
	numeroInstruction = _numeroInstruction;
	_numeroInstruction++;
}


Etiquette::~Etiquette(){}


