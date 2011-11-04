PROGRAM Ecole;
CONST
MaxEleves = 35;
MaxNotes = 10;
TYPE
note_t = array [1..MaxNotes] of real;
eleve_t = Record
	age, nb_notes : integer;
	notes : note_t;
	moyenne : real;
	End;
classe_t = array [1..MaxEleves] of eleve_t;
VAR
c : classe_t;
nb_eleves, i, j : integer;
PROCEDURE affi_eleve (e : eleve_t);
VAR j : integer;
BEGIN
writeln (Õ age : Õ, e.age); write (Õ notes : Õ); for j := 1 to e.nb_notes do write (e.notes[j]); writeln; writeln (Õ moy : Õ, e.moyenne);
END;

PROCEDURE affi_classe (c : classe_t ; nb : integer);
VAR i : integer;
BEGIN
for i := 1 to nb do begin
writeln (ÕEleve n.Õ, i);
affi_eleve (c[i]); end;
END;

BEGIN
{ ... }
affi_classe ( c, nb_eleves )
END.