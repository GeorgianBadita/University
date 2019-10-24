%sa se insereze dupa fiecare element par, 1
%Flux (i,i,o).

insert_par([],[]).

insert_par([H|T],[H|[1|Res]]):-
  H mod 2 =:= 0,
  insert_par(T,Res),!.

insert_par([H|T],[H|Res]):-
  insert_par(T,Res).
