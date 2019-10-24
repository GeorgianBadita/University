%Sa se calculeze suma alternanta a elementelor unei liste
%SumaAlternanta(L: lista, S:suma alternanta)
%flux: (i, i), (i, o)

sumaAlternanta([],_,0):-!. %daca lista e vida suma este 0
sumaAlternanta([A|B],I,S):- %impartim lista in doua, Head-A si Tail-B
  I mod 2 =:= 0, %daca suntem pe pozitie para
  I1 is I+1, %apelam pentru urmatoarea iteratie
  sumaAlternanta(B,I1,S1), %calculam suma alternanta din restul lisei
  S is A+S1,!. %actualizam suma
sumaAlternanta([A|B],I,S):-
  I1 is I+1,
  sumaAlternanta(B,I1,S1),
  S is -A+S1,!.

suma(L, S):-sumaAlternanta(L, 0, S),!. %Wrapper function pentru suma alternanta

%Functie de test
test_suma:-
  suma([1,2,3,4],S),
  S=:=(-2),
  suma([11,5,7],S1),
  S1=:=13,
  suma([1,2,3,4],-2),
  true,
  not(suma([11,5,7],-1)),
  true.
