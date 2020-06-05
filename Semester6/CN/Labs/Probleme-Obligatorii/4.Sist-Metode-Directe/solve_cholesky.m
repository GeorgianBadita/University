function x = solve_cholesky(A,b)
%Functie care rezolva un sistem de forma Ax = b folosind
%descompunerea Cholesky, pentru existenta descompunerii matricea A
%trebuie sa fie Hermiteana Pozitiv definita

R = transpose(cholesky_decomposition(A));
y = forwardsubst(R, b);
x = backsubst(R', y);
end