%Sa se testeze daca o lista are aspect de vale

%Functie care verifica daca o lista e crescatoare
%checkInc(L:Lista)- true daca lista e crescatoare, fals altfel
%flux(i)
checkInc([]).
checkInc([_]).

checkInc([H|[H1|T]]):-
  H1>H,
  checkInc([H1|T]).

%Functie care verifica daca o lista e descrescatoare
%checkDnc(L:Lista)- true daca lista e descrescatoare, fals altfel
%flux(i)
checkDec([]).
checkDec([_]).

checkDec([H|[H1|T]]):-
  H1<H,
  checkDec([H1|T]).


%Model flux (i)
%check_valley(L:lista)
check_valley([]).
check_valley(L):-
  not(checkInc(L)), %sa nu fie lista strict crescatoare
  not(checkDec(L)), %sa nu fie lista strict descrescatoare
  change_sign(L,0).


change_sign([_|T],1):-T=[],!. %daca lista e vida si semnul s-a schimbat odata

%Model de flux(i, i)
change_sign([H|[H1|T]],N):-
  H>H1,     %daca l1 > l2
  N=0,      %si semnul nu s-a schimbat
  change_sign([H1|T],N). %suntem pe coborare

change_sign([H|[H1|T]],N):-
  H<H1,     %daca l1 < l2
  N=0,      %si nu am schimbat semnul
  change_sign([H1|T],1). %incepem urcarea

change_sign([H|[H1|T]],N):-
  H<H1,     %daca l1<l2
  N=1,      %si am schimbat semnul
  change_sign([H1|T],N). %continuam urcarea

change_sign([H|[H1|_]],N):-
  H>H1, %daca l1 > l2
  N=1,  %si am schimbat deja semnul
  fail. %faillll


%Functie de test
  test_valley:-
    check_valley([3,2,3,5]),
    check_valley([]),
    check_valley([5,4,3,2,1,2,3,4,5]),
    not(check_valley([3,2,1])),
    not(check_valley([1,2,3])),
    not(check_valley([3,2,1,2,1])).
