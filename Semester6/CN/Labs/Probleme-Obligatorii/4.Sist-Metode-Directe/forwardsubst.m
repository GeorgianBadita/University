function x = forwardsubst(L, b)
% Functie care rezolva un sistem triunghiular inferior
% L - matrice de sistem triangular inferioara
% b - vector de solutii
% exemplu de parametrii
%L = [1 0 0 0     b = [1
%     2 3 0 0          2
%     1 3 4 0          3
%     1 2 3 3]         4]
x=zeros(size(b));
n=length(b);
for k=1:n
    x(k)=(b(k)-L(k,1:k-1)*x(1:k-1))/L(k,k);
end
end