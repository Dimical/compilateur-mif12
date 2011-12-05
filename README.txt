Notre groupe se compose:
-----------------------

	- AFKIR Bilal
	- D'ALESSANDRO David
	- CHAUMARTIN Remi
	- FAURE-VINCENT Pascal

Pour pouvoir executer notre programme, il vous suffit de :
--------------------------------------------------------

	- Compiler avec make
	- Executer avec ./prog < test/test-xx.pas

Ce qui a été développé:
----------------------

	- makefile générique fonctionnel pour compiler dans plusieurs dossiers 

	- gestion des identificateurs

	- types de base et déclarations de variables

	- les types construits (intervals, arrays, enum)

	- tables de symboles imbriquées
	
	- dérivations de la classe symbole:
			-  variable
			-  constante
			-  fonction
			-  procédure
			-  argument (fonctions/procédures)
			-  programme
			-  temporaire
			-  étiquette
			- symbole type

	- classe Operande

	- classe Instruction

	- classe CodeInstruction

	- classe ConteneurCode

	- classe Valeur


Problèmes rencontrés :
--------------------- 

	La gestion des étiquettes dans le code 3@ n'a pas été maitrisées totalement (mais vous pourrez voir une tentative dans le code notamment avec les branchements conditionnels). En effet, nous n'avons pas su gérer les flots de contrôle (incluant les étiquettes).












