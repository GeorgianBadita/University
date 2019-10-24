%len(L, N) - functie care calculeza lungimea unei liste
%L - Lista
%N - Intreg, lungimea listei
%Flux (i, o) (i, i)
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

%interChange(L, Rez) - schimba toate sublistele cu subsecventa maxima de numere
%pare din fiecare
%L - lista eterogena
%Rez - lista eterogena, lista rezultat
%Flux (i, o) (i, i)
interChange([], _):- !.
interChange([A], [Rez]):- is_list(A), longestEven(A, Rez), !.
interChange([A], [A]):-!.

interChange([H|T], [L|Rez]):-
  is_list(H), !,
  longestEven(H, L),
  interChange(T, Rez).

interChange([H|T], [H|Rez]):-
  interChange(T, Rez).

test:-
  interChange([1, 2, 3], R),
  R = [1, 2, 3],
  interChange([1, [1, 3, 5, 7], [2, 2, 5, 4, 4, 4], 3], R1),
  R1 = [1, [], [4, 4, 4], 3],
  interChange([1, [2, 2], [1, 3, 6, 8], 8, 7], R2),
  R2 = [1, [2, 2], [6, 8], 8, 7],
  interChange([], R3),
  R3 = [].
