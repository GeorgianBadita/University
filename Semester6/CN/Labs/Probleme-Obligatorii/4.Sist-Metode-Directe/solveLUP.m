function x = solveLUP(A,b)
%Functie care rezolva un sistem de form Ax = b prin descompunerea LUP

[m,n] = size(A);
[L, U, P] = LUP_decomposition(A);
b = P*b;
y = zeros(n, 1);
y(1) = b(1)/L(1,1);
for i=2:n
    y(i)= (b(i) - L(i, 1:i-1)*y(1:i-1))/L(i,i);
end
x = zeros(n, 1);
x(n) = y(n)/U(n,n);
for i=n-1:-1:1
    x(i)= (y(i) - U(i, i+1:n)*x(i+1:n))/U(i,i);
end

end