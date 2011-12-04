%{

#include <cstddef>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include "../headers/TableId.hpp"
#include "../headers/TableSymb.hpp"
#include "../headers/Symbole.hpp"
#include "../headers/SymboleVar.hpp"
#include "../headers/SymboleProg.hpp"
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
TableSymb *table = new TableSymb();

Type *t = new TypeEntier();

Symbole *prog = new SymboleProg();

//-----------

int tempoCourant= 0; // notre compteur de temporaire
 Operande* operandeTempo;

//------------------

vector <int> DeclVarMult;

vector <char *> Code3adresses; // pas besoin

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

Program				:	ProgramHeader SEP_SCOL Block SEP_DOT { table->Ajout(prog,0);printf("Prog");}
				;

ProgramHeader			:	KW_PROGRAM TOK_IDENT
				;

Block				:	BlockDeclConst BlockDeclType BlockDeclVar BlockDeclFunc BlockCode
				;

BlockDeclConst			:	KW_CONST ListDeclConst
			 	|
			 	;

ListDeclConst			:	ListDeclConst DeclConst
			 	|	DeclConst
			 	;

DeclConst			:	TOK_IDENT OP_EQ Expression SEP_SCOL {cout << "il faut ajouter une constante a la table des symboles" << endl;}
			 	;

BlockDeclType			:	KW_TYPE ListDeclType
			 	|
			 	;

ListDeclType			:	ListDeclType DeclType
			 	|	DeclType
			 	;

DeclType			:	TOK_IDENT OP_EQ Type SEP_SCOL {cout << "il faut ajouter un type a la table des symboles" << endl;}
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

ListIdent			:	ListIdent SEP_COMMA TOK_IDENT {DeclVarMult.push_back($3);}
			 	|	TOK_IDENT {DeclVarMult.push_back($1); }
			 	;

BlockDeclFunc			:	ListDeclFunc SEP_SCOL
			 	|
			 	;

ListDeclFunc			:	ListDeclFunc SEP_SCOL DeclFunc
			 	|	DeclFunc
			 	;

DeclFunc			:	ProcDecl
			 	|	FuncDecl
			 	;

ProcDecl			:	ProcHeader SEP_SCOL Block
			 	;

ProcHeader			:	ProcIdent
			 	|	ProcIdent FormalArgs
			 	;

ProcIdent			:	KW_PROC TOK_IDENT
			 	;

FormalArgs			:	SEP_PO ListFormalArgs SEP_PF
			 	;

ListFormalArgs			:	ListFormalArgs SEP_SCOL FormalArg
			 	|	FormalArg
			 	;

FormalArg			:	ValFormalArg
			 	|	VarFormalArg
			 	;

ValFormalArg			:	ListIdent SEP_DOTS BaseType
			 	;

VarFormalArg			:	KW_VAR ListIdent SEP_DOTS BaseType
			 	;

FuncDecl			:	FuncHeader SEP_SCOL Block
			 	;

FuncHeader			:	FuncIdent FuncResult
			 	|	FuncIdent FormalArgs FuncResult
			 	;

FuncIdent			:	KW_FUNC TOK_IDENT
			 	;

FuncResult			:	SEP_DOTS BaseType
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

BlockCode			:	KW_BEGIN ListInstr KW_END {cout << "jai un blok" << endl;}
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
                                        table->Ajout(new SymboleTemp(), table->getNbrsym()+1);
                                        tempoCourant ++;

                                        operandeTempo = new Operande(table->getNbrsym(), new Valeur(), false);


                                        // on teste si nos expressions sont correctes
                                            if(($1 != NULL) && ($3 !=NULL))
                                            {
                                                //Etiquette* etiquette1= new Etiquette();

                                                // on créer une nouvelle instruction
                                                Instruction* nvelleInstr= new Instruction(/*etiquette1,*/ "ADD", operandeTempo, $1, $3, tableid);

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
			 	|	TOK_INTEGER { // -1 qui correspond au fait que l'entier n'a pas de id sur la TI
                                                        $$ = new Operande(-1 , new Valeur(new TypeEntier, $1), true);
                                                    }
			 	|	TOK_REAL
			 	|	TOK_BOOLEAN
			 	|	KW_NIL
			 	|	TOK_STRING
			 	;

VarExpr				:	TOK_IDENT { // on construit notre operande sans valeur 
                                                    $$ = new Operande($1 , new Valeur(table->getSymbole($1)->getType()), false);
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
	table->Afficher(*tableid);
        ContenCodeCourant->affichage();
        fclose ( yyin );
}