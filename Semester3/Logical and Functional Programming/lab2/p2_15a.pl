%len(L, N) - functie care calculeza lungimea unei liste
%L - Lista
%N - Intreg, lungimea listei
%Flux (i, 0) (i, i)
len([], 0):-!.

len([_|T], N):-
  len(T, N1),
  N is N1 + 1.

%longer(L1, L2, R) - functie care returneaza lista mai lunga dintre listele L1 si L2
%L1 - Lista de numere intregi
%L2 - lista de numere intregi
%R - L1, daca length(L1) > length(L2), L2 altfel
%Flux (i, i, o) (i, i, i)
longer(L1,L2,L1):-
    len(L1,Len1),
    len(L2,Len2),
    Len1>Len2,!.

longer(_,L2,L2).

%checkFirst(L, Res) - il leaga pe Res la secventa cea mai lunga de numere pare de
%la inceputul listei
%L - lista de numere intregi
%Res - lista rezultat
%Flux (i, o)
checkFirst([],[]):-!.
checkFirst([H|T],[H|Res]):-
    H mod 2 =:=0,!,
    checkFirst(T,Res).

checkFirst(_,[]).

%longestEven(L, Res) - il leaga pe Res la secventa cea mai lunga de numere pare
%din lista L
%L lista de numere intregi
%Res - lista rezultat
%Flux (i, o) (i, i)
longestEven([],[]):-!.
longestEven([H|T],Res):-
    checkFirst([H|T],R1),
    longestEven(T,R2),
    longer(R1,R2,Res).

test:-
  longestEven([], R),
  R = [],
  longestEven([1, 2], R1),
  R1 = [2],
  longestEven([1, 2, 3, 4, 4], R2),
  R2 = [4, 4],
  longestEven([1, 2, 3, 2, 2, 7, 4, 6, 8, 5, 8, 8, 8], R3),
  R3 = [8, 8, 8].
