function x = backsubst(U, b)
% Functie care rezolva un sistem triunghiular superior
% U - matrice de sistem triangular superioara
% b - vector de solutii
% exemplu de parametrii
%U = [1 2 3 4     b = [1
%     0 1 3 4          2
%     0 0 2 3          3
%     0 0 0 3]         4]
n=length(b);
x=zeros(size(b));
for k=n:-1:1
    x(k)=(b(k)-U(k,k+1:n)*x(k+1:n))/U(k,k);
end
end