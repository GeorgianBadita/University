function [aprox, iter] = Newton(f, f_deriv, aprox_i, eroare_abs, eroare_rel, maxIter)
%Functie ce utilizeaza metoda lui Newton pentru ecuatii neliniare 
%pentru a returna aproximatia radacinii si numarul de iteratii

if nargin < 5, eroare_rel =0; end
if nargin < 4, eroare_abs = 1e-3; end
aprox_prec = aprox_i(:);
for k = 1:maxIter
    aprox_k = aprox_prec - f_deriv(aprox_prec)\f(aprox_prec);
    if norm(aprox_k - aprox_prec, inf) < eroare_abs + eroare_rel*norm(aprox_k, inf)
        aprox = aprox_k;
        iter = k;
        return
    end
    aprox_prec = aprox_k;
end
