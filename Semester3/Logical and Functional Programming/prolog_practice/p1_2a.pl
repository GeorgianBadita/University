%Cmmdc pentru un sir
%cmmdc_nr(A:int, B:int, Res:int).
%flux(i,i,o)

cmmdc_nr(A,0,A):-!.
cmmdc_nr(0,A,A):-!.

cmmdc_nr(A,B,Res):-
  A1 is A mod B,
  cmmdc_nr(B,A1,Res).

cmmdc_lst([],0):-!.
cmmdc_lst([A],A):-!.

cmmdc_lst([H|T],Res):-
  cmmdc_lst(T,Res1),
  cmmdc_nr(H,Res1,Res).
