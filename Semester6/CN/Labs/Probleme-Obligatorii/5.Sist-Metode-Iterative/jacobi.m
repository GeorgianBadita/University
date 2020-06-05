function x=jacobi(A,b,x0,err,niter)
% A - matricea sistemului
% b - vectorul solutie
% x0 - valoarae initiala a lui x
% err - erroarea
% niter - numar de iteratii
%x - solutia finala
M = diag(diag(A));
N = M - A;
x = x0(:);
for i=1:min(niter, 50)
    x0 = x;
    x = M\(N * x0 + b);
    if norm(x - x0, inf) < err * norm(x, inf)
        return
    end
end
end