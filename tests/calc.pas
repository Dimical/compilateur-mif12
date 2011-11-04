program calc;
VAR ga, gb : integer; gk, gs : real;
FUNCTION calc (	x : integer; y : real;
var z : real ) : boolean;
VAR ok : boolean;
d : real;
BEGIN
ok := true; { init pas d’erreur }
d := cos (x-y); if d = 0.0 then ok := false	{ division par 0 } else z := (x+y) / d; { resultat numerique }
calc := ok;
END;

FUNCTION somme ( a, b : integer; k	: real	) : real;
VAR res, f : real;
i : integer;
BEGIN 
res :=0.0; { init somme a O }
for i := a to b do if calc (i, k, f)
then res := res + f;
somme := res;
END;
BEGIN readln (ga, gb, gk); gs := somme (ga, gb, gk); writeln (gs);
END.