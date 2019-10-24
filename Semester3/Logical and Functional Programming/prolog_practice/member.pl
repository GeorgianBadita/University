%check if ane element is in a list
%(i, i)(o, i)

member(E, []) :- false.
member(E, [E|_]) :- true.
member(E, [_|L]) :- member(E, L).
