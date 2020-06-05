function [aprox, iter] = Secant(f, aprox_0, aprox_1, eroare_abs, eroare_rel)
%Funtie ce foloseste metoda secantei pentru a returna aproximatia
%radacinei si numarul de iteratii

if nargin <5, eroare_rel = 0; end
if nargin <4, eroare_abs = 1e-3; end
aprox_v = aprox_0;
y_v = feval(f,aprox_v);
aprox_c = aprox_1;
y_c = feval(f,aprox_c);
for k=1:50
    aprox_k = aprox_c - y_c*(aprox_c-aprox_v)/(y_c-y_v);
    if abs(aprox_k-aprox_c) < eroare_abs+eroare_rel*abs(aprox_k)
        aprox = aprox_k;
        iter = k;
        return
    end
    aprox_v = aprox_c;
    y_v = y_c;
    aprox_c = aprox_k;
    y_c = feval(f, aprox_k);
end