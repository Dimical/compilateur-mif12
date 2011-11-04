PROGRAM assorti;
TYPE
humain_t = Record age, taille : integer; riche	: boolean END;
couple_t = Record homme, femme : humain_t; nb_enfant : integer END;

VAR amis : couple_t;

FUNCTION difference_age (h, f : humain_t) : integer;
BEGIN
res := abs (h.age - f.age);
difference_age := res;
END;
FUNCTION couple_assorti (c : couple_t) : boolean;
VAR res : boolean;
BEGIN
res := false;
if difference_age (c.homme, c.femme) < 10 then res := true;
if (c.homme.age > 75) and c.homme.riche then res := true;
couple_assorti := res;
END;
BEGIN
{ ... }
write ('Ce couple avec ', amis.nb_enfant, ' enfant(s) est ');
if couple_assorti (amis) then writeln ('assorti.')
else writeln ('non assorti.');
END.