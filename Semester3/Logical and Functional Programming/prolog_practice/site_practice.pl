%Practice simple recursive problems

%Function to delete an element from a list
del(_,[],[]).

del(E,[H|T],Result):-
  H=:=E,
  del(E,T,Result).

del(E,[H|T],[H|Result]):-
  del(E,T,Result).

%Function to replace an element with anoter
replace([],_,_,[]).
replace([A],A,B,[B]).

replace([H|T],E,E1,[E1|Result]):-
  H=:=E,
  replace(T,E,E1,Result).

replace([H|T],E,E1,[H|Result]):-
  replace(T,E,E1,Result).
