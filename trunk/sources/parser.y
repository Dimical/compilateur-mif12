%{

#include <cstddef>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <vector>
#include <stack>
#include <string>
#include "../headers/TableId.hpp"
#include "../headers/TableSymb.hpp"
#include "../headers/Symbole.hpp"
#include "../headers/SymboleVar.hpp"
#include "../headers/SymboleArg.hpp"
#include "../headers/SymboleProg.hpp"
#include "../headers/SymboleProcedure.hpp"
#include "../headers/SymboleFonction.hpp"
#include "../headers/SymboleTemp.hpp"
#include "../headers/Type.hpp"
#include "../headers/TypeEntier.hpp"
#include "../headers/TypeChar.hpp"
#include "../headers/TypeReel.hpp"
#include "../headers/TypeBool.hpp"
#include "../headers/TypeString.hpp"
#include "../headers/ConteneurCode.hpp"
#include "../headers/Instruction.hpp"
#include "../headers/Operande.hpp"
#include "../headers/Valeur.hpp"

using namespace std;


extern FILE* yyin;

extern TableId *tableid;
TableSymb *table;

int arite = 0; /* Pour remonter l'arite des fonctions et procedures */
Type* typeFuncGlobal; /* Pour remonter le type de retour d'une fonction */

Type *t = new TypeEntier();



//-----------

int tempoCourant= 0; // notre compteur de temporaire
 Operande* operandeTempo;

//------------------








vector <int> DeclVarMult; /*Pour les declaration multiples de variables */
vector <char *> Code3adresses; /* Pour le 3adresses pas besoin*/
vector <TableSymb*> tableSAffichage; /* Les tables de symboles imbriquees */

stack<TableSymb*> pushedSymbolTables; /* la pile pour gérer plusieurs tables de symboles */
TableSymb * tableTemp; /* */



// notre conteneur (passer à un conteneur generale)
ConteneurCode* ContenCodeCourant = new ConteneurCode();



extern int yyparse();
extern int yyerror ( char* );
extern int yylex ();

%}

%union{
Type* typeIdent;
char* id;
int numid;

int valueint;
float valuefloat;
bool valuebool;
char *valuestring;



Type* type;
Operande* operande;
}

%token KW_PROGRAM
%token KW_CONST
%token KW_TYPE
%token KW_VAR
%token KW_ARRAY
%token KW_OF
%token KW_RECORD
%token KW_BEGIN
%token KW_END
%token KW_DIV
%token KW_MOD
%token KW_AND
%token KW_OR
%token KW_XOR
%token KW_NOT
%token KW_IF
%token KW_THEN
%token KW_ELSE
%token KW_WHILE
%token KW_DO
%token KW_REPEAT
%token KW_UNTIL
%token KW_FOR
%token KW_TO
%token KW_DOWNTO
%token KW_PROC
%token KW_FUNC
%token KW_NIL
%token KW_INTEGER
%token KW_REAL
%token KW_BOOLEAN
%token KW_CHAR
%token KW_STRING

%token SEP_SCOL
%token SEP_DOT
%token SEP_DOTS
%token SEP_DOTDOT
%token SEP_COMMA
%token SEP_CO
%token SEP_CF
%token SEP_PO
%token SEP_PF

%token OP_EQ
%token OP_NEQ
%token OP_LT
%token OP_LTE
%token OP_GT
%token OP_GTE
%token OP_ADD
%token OP_SUB
%token OP_MUL
%token OP_SLASH
%token OP_EXP
%token OP_PTR
%token OP_AFFECT

%type <typeIdent> Type
%type <typeIdent> BaseType


%token <numid> TOK_IDENT
%token <valueint> TOK_INTEGER
%token <valuefloat> TOK_REAL
%token <valuebool> TOK_BOOLEAN
%token <valuestring> TOK_STRING

%type <numid> ProcIdent
%type <numid> ProcHeader
%type <numid> ProcDecl
%type <numid> FuncIdent
%type <typeIdent> FuncResult
%type <numid> FuncHeader
%type <numid> FuncDecl

%start Program

%nonassoc OP_EQ OP_NEQ OP_GT OP_LT OP_GTE OP_LTE
%left OP_ADD OP_SUB KW_OR KW_XOR
%left OP_MUL OP_SLASH KW_AND KW_DIV KW_MOD
%right KW_NOT OP_NEG OP_POS
%left OP_EXP
%nonassoc OP_PTR
%nonassoc OP_DOT
%left SEP_CO

%nonassoc KW_IFX
%nonassoc KW_ELSE

%type<operande> AtomExpr
%type<operande> VarExpr
%type<operande> Expression
%type<operande> MathExpr
%type<operande> CompExpr
%type<operande> BoolExpr





%%

Program				:	ProgramHeader SEP_SCOL Block SEP_DOT { cout<<"DEBUG Program"<<endl; table->Ajout(new SymboleProg(),0);}
				;

ProgramHeader			:	KW_PROGRAM TOK_IDENT    {   
                                                                    cout<<"DEBUG ProgramHeader"<<endl;
                                                                    table= new TableSymb(tableid->getidTOnum($2), NULL);
                                                                    tableSAffichage.push_back(table);
                                                                    pushedSymbolTables.push(table);
                                                                }
				;

Block				:	 {cout<<"DEBUG Block"<<endl;}   BlockDeclConst BlockDeclType BlockDeclVar BlockDeclFunc BlockCode
				;

BlockDeclConst			:	{cout<<"DEBUG BlockDeclConst"<<endl;}   KW_CONST ListDeclConst
			 	|
			 	;

ListDeclConst			:	{cout<<"DEBUG ListDeclConst"<<endl;}    ListDeclConst DeclConst
			 	|	{cout<<"DEBUG ListDeclConst"<<endl;}    DeclConst
			 	;

DeclConst			:	TOK_IDENT OP_EQ Expression SEP_SCOL {   cout<<"DEBUG DeclConst"<<endl;/*il faut ajouter une constante a la table des symboles*/}
			 	;

BlockDeclType			:	KW_TYPE ListDeclType
			 	|
			 	;

ListDeclType			:	ListDeclType DeclType
			 	|	DeclType
			 	;

DeclType			:	TOK_IDENT OP_EQ Type SEP_SCOL {/*il faut ajouter un type a la table des symboles*/}
			 	;

BlockDeclVar			:	KW_VAR ListDeclVar
			 	|
			 	;

ListDeclVar			:	ListDeclVar DeclVar
			 	|	DeclVar
			 	;

DeclVar				:	ListIdent SEP_DOTS Type SEP_SCOL{
                                                                            for (unsigned int i=0;i<DeclVarMult.size(); i++){

                                                                                Symbole *temp = new SymboleVar($3);
                                                                                table->Ajout(temp, DeclVarMult[i]);
                                                                          }
                                                                          DeclVarMult.clear();
                                                                        }
			 	;

ListIdent			:	ListIdent SEP_COMMA TOK_IDENT { DeclVarMult.push_back($3);
                                                                        arite++;}
			 	|	TOK_IDENT { DeclVarMult.push_back($1);
                                                    arite++;}
			 	;

BlockDeclFunc			:	{cout<<"DEBUG BlockDeclFunc"<<endl;}   ListDeclFunc SEP_SCOL
			 	|
			 	;

ListDeclFunc			:	ListDeclFunc SEP_SCOL DeclFunc
			 	|	DeclFunc
			 	;

DeclFunc			:	{arite=0;}  ProcDecl    {
                                                        if (!pushedSymbolTables.empty())
                                                        {
                                                                /*table = pushedSymbolTables.top();*/
                                                                pushedSymbolTables.pop();
                                                                table = pushedSymbolTables.top();
                                                                table->Ajout( new SymboleProcedure(arite),$2);                                                              
                                                       }
                                                        else
                                                                cout << "no symbol table to pop" << endl;
                                                    }
			 	|	{arite=0;}  FuncDecl    {
                                                        if (!pushedSymbolTables.empty())
                                                        {
                                                                pushedSymbolTables.pop();
                                                                table = pushedSymbolTables.top();
                                                                /////ICI truite
                                                                table->Ajout( new SymboleFonction(typeFuncGlobal,arite-1),$2);

                                                       }
                                                        else
                                                                cout << "no symbol table to pop" << endl;
                                                    }
			 	;

ProcDecl			:	ProcHeader SEP_SCOL Block {$$ = $1;}
			 	;

ProcHeader			:	ProcIdent   {
                                                        /*on remonte l'identifiant*/
                                                        $$ = $1;
                                                    }
			 	|	ProcIdent   FormalArgs  {
                                                                    /*on remonte l'identifiant*/
                                                                    $$ = $1;
                                                                }
			 	;

ProcIdent			:	KW_PROC TOK_IDENT   {
                                                                $$=$2;
                                                                table = new TableSymb(tableid->getidTOnum($2), pushedSymbolTables.top());tableSAffichage.push_back(table);
                                                                pushedSymbolTables.push(table);
                                                            }
			 	;

FormalArgs			:	SEP_PO ListFormalArgs SEP_PF {/*cout << "formal arg arite = "<<arite<<endl;*/}
			 	;

ListFormalArgs			:	ListFormalArgs SEP_SCOL FormalArg
			 	|	FormalArg
			 	;

FormalArg			:	ValFormalArg
			 	|	VarFormalArg
			 	;

ValFormalArg			:	ListIdent SEP_DOTS BaseType     {
                                                                            for (unsigned int i=0;i<DeclVarMult.size(); i++){
                                                                                Symbole *temp = new SymboleArg($3, true, 1);
                                                                                table->Ajout(temp, DeclVarMult[i]);
                                                                            }
                                                                            DeclVarMult.clear();
                                                                        }
			 	;

VarFormalArg			:	KW_VAR ListIdent SEP_DOTS BaseType
			 	;

FuncDecl			:	FuncHeader SEP_SCOL Block   {
                                                                        $$=$1;
                                                                    }
			 	;

FuncHeader			:	FuncIdent FuncResult    {/* on remonte l'identifiant et on met le type en variable globale */
                                                                    typeFuncGlobal = $2;
                                                                    $$ = $1;
                                                                }
			 	|	FuncIdent FormalArgs FuncResult {/* on remonte l'identifiant et on met le type en variable globale */
                                                        typeFuncGlobal = $3;
                                                                    $$ = $1;
                                                    }
			 	;

FuncIdent			:	KW_FUNC TOK_IDENT   { $$=$2;                                                                
                                                                table = new TableSymb(tableid->getidTOnum($2), pushedSymbolTables.top());tableSAffichage.push_back(table);
                                                                pushedSymbolTables.push(table);
                                                            }
			 	;

FuncResult			:	SEP_DOTS BaseType {$$ = $2}
			 	;

Type				:	UserType
			 	|	BaseType {$$ = $1;
                                            }
			 	;

UserType			:	EnumType
			 	|	InterType
			 	|	ArrayType
			 	|	RecordType
			 	|	PointerType
			 	;

BaseType			:	TOK_IDENT {$$=NULL;}
			 	|	KW_INTEGER {$$ = new TypeEntier();}
				|	KW_REAL {$$ = new TypeReel();}
				|	KW_BOOLEAN {$$ = new TypeBool();}
				|	KW_CHAR {$$ = new TypeChar();}
				|	KW_STRING {$$ = new TypeString();}
				;

EnumType			:	SEP_PO ListEnumValue SEP_PF
			 	;

ListEnumValue			:	ListEnumValue SEP_COMMA TOK_IDENT
			 	|	TOK_IDENT
			 	;

InterType			:	InterBase SEP_DOTDOT InterBase
			 	;

InterBase			:	NSInterBase
			 	|	OP_SUB NSInterBase
			 	;

NSInterBase			:	TOK_IDENT
			 	|	TOK_INTEGER
			 	;

ArrayType			:	KW_ARRAY SEP_CO ListArrayIndex SEP_CF KW_OF Type
			 	;

ListArrayIndex			:	ListArrayIndex SEP_COMMA ArrayIndex
				|	ArrayIndex
				;

ArrayIndex			:	TOK_IDENT
			 	|	InterType
			 	;

RecordType			:	KW_RECORD RecordFields KW_END
			 	;

RecordFields			:	RecordFields SEP_SCOL RecordField
			 	|	RecordField
			 	;

RecordField			:	ListIdent SEP_DOTS Type
			 	;

PointerType			:	OP_PTR Type
			 	;

BlockCode			:	KW_BEGIN ListInstr KW_END {/*cout << "jai un blok" << endl;*/}
				|	KW_BEGIN ListInstr SEP_SCOL KW_END
				|	KW_BEGIN KW_END
			 	;

ListInstr			:	ListInstr SEP_SCOL Instr
			 	|	Instr
			 	;

Instr				:	KW_WHILE Expression KW_DO Instr
			 	|	KW_REPEAT ListInstr KW_UNTIL Expression
			 	|	KW_FOR TOK_IDENT OP_AFFECT Expression ForDirection Expression KW_DO Instr
			 	|	KW_IF Expression KW_THEN Instr %prec KW_IFX
			 	|	KW_IF Expression KW_THEN Instr KW_ELSE Instr
			 	|	VarExpr OP_AFFECT Expression {
                                        Instruction* Instr= new Instruction(/*etiquette1,*/ "CPY", $1,$3, NULL, tableid);
                                        ContenCodeCourant->ajouterInstruct(Instr);
                                        /////////ici ici ici ////////////////////
                                }
			 	|	Call
			 	|	BlockCode
			 	;

ForDirection			:	KW_TO
			 	|	KW_DOWNTO
			 	;

Expression			:	MathExpr {
                                                   

                                                       }
			 	|	CompExpr
			 	|	BoolExpr
			 	|	AtomExpr
			 	|	VarExpr
				|	Call
			 	;

MathExpr			:	Expression OP_ADD Expression
                                        {

                                        // on va s'occuper de nos temporaire ici
                                        // AJoute d'une temporaire dans les tables
                                        std::stringstream out;
                                        out<<tempoCourant;
                                        tableid->Ajout("__Temp000"+out.str()); cout << "ajout" <<endl;
                                        cout <<endl << "TAILLE DE LA TABLE DES SYMBOLES " << table->getNbrsym() <<endl;
                                        table->Ajout(new SymboleTemp(), tableid->getnumTOid("__Temp000"+out.str()));/*4*//*table->getNbrsym()*/
                                        tempoCourant ++;
                                        

                                        operandeTempo = new Operande((tableid->getnumTOid("__Temp000"+out.str())), new Valeur(), false);



                                            if(($1 != NULL) && ($3 !=NULL))
                                            {
                                                //Etiquette* etiquette1= new Etiquette();

                                                // on créer une nouvelle instruction
                                        // on teste si nos expressions sont correctes

                                                Instruction* nvelleInstr= new Instruction(/*etiquette1,*/ "ADD", operandeTempo, $1, $3, tableid);
                                        // on teste si nos expressions sont correctes

                                                // faire l'operation de l'operande (addition) -> il se fait dans l'instruction (codeInstruction.cpp)

                                                ContenCodeCourant->ajouterInstruct(nvelleInstr);

                                                // on retourne le résultat
                                                $$ = operandeTempo;

                                                //string t1= $1;
                                                //cout<<"Test : " << t1<<endl;
                                            }



                                        }
			 	|	Expression OP_SUB Expression
			 	|	Expression OP_MUL Expression
			 	|	Expression OP_SLASH Expression
			 	|	Expression KW_DIV Expression
			 	|	Expression KW_MOD Expression
			 	|	Expression OP_EXP Expression
			 	|	OP_SUB Expression %prec OP_NEG
			 	|	OP_ADD Expression %prec OP_POS
			 	;

CompExpr			:	Expression OP_EQ Expression
			 	|	Expression OP_NEQ Expression
			 	|	Expression OP_LT Expression
			 	|	Expression OP_LTE Expression
			 	|	Expression OP_GT Expression
			 	|	Expression OP_GTE Expression
			 	;

BoolExpr			:	Expression KW_AND Expression
			 	|	Expression KW_OR Expression
			 	|	Expression KW_XOR Expression
			 	|	KW_NOT Expression
			 	;

AtomExpr			:	SEP_PO Expression SEP_PF
			 	|	TOK_INTEGER {// -1 qui correspond au fait que l'entier n'a pas de id sur la TI
                                                        $$ = new Operande(-1 , new Valeur(new TypeEntier, $1), true);
                                                    }
			 	|	TOK_REAL
			 	|	TOK_BOOLEAN
			 	|	KW_NIL
			 	|	TOK_STRING
			 	;

VarExpr				:	TOK_IDENT { // on construit notre operande sans valeur
                                                    cout<<"DEBUG VarExpr DEBUT"<<endl;
                                                    cout<<"DEBUG1 "<<table->getSymbole($1)<<endl;
                                                    cout<<"TOK_IDENT = "<< $1 <<endl;
                                                    cout<<"DEBUG2 "<< endl;
                                                    if(table->getSymbole($1)!=NULL){
                                                        cout<<"DEBUG3 "<<   table->getSymbole($1)->getType()    <<endl;
                                                        $$ = new Operande($1 , new Valeur(table->getSymbole($1)->getType()), false);
                                                        cout<<"DEBUG VarExpr FIN"<<endl;
                                                    }
                                                    else{cout<<"DEBUG else "<< endl;}
                                                  }
				|	VarExpr SEP_CO ListIndices SEP_CF
				|	VarExpr SEP_DOT TOK_IDENT %prec OP_DOT
				|	VarExpr OP_PTR
				;

Call			 	:	TOK_IDENT Parameters
				;

Parameters			:	SEP_PO ListParameters SEP_PF
				|	SEP_PO SEP_PF
				;

ListIndices			:	ListIndices SEP_COMMA Expression
				|	Expression
				;

ListParameters			:	ListParameters SEP_COMMA Expression
				|	Expression
				;

%%

using namespace std;
int main ( int argc, char** argv )
{
	yyin = fopen ( argv [ 1 ], "r" );
	tableid=new TableId();
	yyparse ();
	tableid->Affichage();
        for (unsigned int i=0;i<tableSAffichage.size(); i++){
            tableSAffichage[i]->Afficher(*tableid);
        }
	//table->Afficher(*tableid);
        ContenCodeCourant->affichage();
        fclose ( yyin );
}
