%returns the difference between 2 sets
%(i, i, o)

lists:subtract([], _, []) :- !.
lists:subtract([A|C], B, D) :-
    memberchk(A, B), !,
    subtract(C, B, D).

lists:subtract([A|C], B, [A|D]):-
    subtract(C, B, D).
