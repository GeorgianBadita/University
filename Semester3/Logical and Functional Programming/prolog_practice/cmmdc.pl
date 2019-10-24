%(i, i)(i, o)

cmmdc(0, X, X) :- X > 0, !.
cmmdc(X, Y, Z) :- X >= Y, X1 is X - Y, cmmdc(X1, Y, Z).
cmmdc(X, Y, Z) :- X < Y, X1 is Y - X, cmmdc(X1, X, Z).
