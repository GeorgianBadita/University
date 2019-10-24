%Predicat care intoarce diferenta a 2 multimi

%exists(E:element, L: lista)
%flux(i, i)
exists(E, [E|_]):-!.

exists(E, [_|B]):-
  exists(E, B).


diff_set([H|T],L,[H|Col]):-
  not(exists(H,L)),
  diff_set(T,L,Col),!.

diff_set([_|T],L,Col):-
  diff_set(T,L,Col),!.

diff_set([],_,[]):-!.
