%Functie care adauga dupa primul, al 2-lea.. al 4-lea element al unei liste o valoare v
%adaugaPos(L, Pos, E, R) (i, i, i, o)
%L - lista initiala
%Pos - pozitia de adaugare
%E - elementul ce trebuie adaugat
%R - Rezultatul

adauga(L, 0, E, [E|L]):-!. %daca pozitia e 0 inseram elementul in capatul listei

adauga([H|L], Pos, E, [H|R]):-
  Pos1 is Pos - 1,
  adauga(L, Pos1, E, R).

%check2Pow(El) - calculeaza daca un numar este putere a lui 2
%El - numar intreg

check2Pow(El):-
  El > 0,
  El is El /\ (-El).

%addPos2Pow(L, El, Pos, R)
%L - lista initiala
%El - elementul de adaugat
%R - rezultatul
%Pos - pozitia curenta

addPos2Pow([], _, _, _):-!.

addPos2Pow([H|T], El, Pos, [H, El|R]):-
  check2Pow(Pos),
  Pos1 is Pos + 1, !,
  addPos2Pow(T, El, Pos1, R).

addPos2Pow([H|T], El, Pos, [H|R]):-
  Pos1 is Pos + 1, !,
  addPos2Pow(T, El, Pos1, R).
