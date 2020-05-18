function [ res ] = leat_sq_approx( x, y, functions, points )
% metoda celor mai mici patrate
% x noduri
% y - f(x)
% functions - functiile de baza
% points - punctele de aproxiamt

phi = functions(x);
phiApprox = functions(points);

n = length(x); 
[n m] = size(phi); 
nAprox = length(points); 


for i=1:n
    for j=1:n
        A(i,j) = phi(i,:) * phi(j,:)';
    end
    B(i,1) = phi(i,:) * y';
end


a=linsolve(A,B);

res = a' * phiApprox;
end
