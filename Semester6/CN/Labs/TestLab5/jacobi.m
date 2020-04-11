function x=jacobi(A,b)
%x - solutie
%A - mat sistemului
%b - solutia

err = 1e-7;
M = diag(diag(A));
N = M - A;
T = inv(M) * N;
c = inv(M) * b;
a = norm(T,inf);
x0 = zeros(size(b));
x = x0(:);
for i = 1:50
   x0 = x;
   x = T * x0 + c;
   if norm(x - x0,inf) < (1 - a)/a * err
      return
   end
end
