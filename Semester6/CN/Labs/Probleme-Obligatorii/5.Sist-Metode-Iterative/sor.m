function x=sor(A,b,omega,x0,err,niter)
% A - matricea sistemului
% b - vectorul solutie
% x0 - valoarae initiala a lui x
% omega - omega pentru relaxare
% err - erroarea
% niter - numar de iteratii
%x - solutia finala

M = 1/omega * diag(diag(A)) + tril(A, -1);
N = M-A;
x = x0;
for i=1:min(niter, 50)
    x0 = x;
    x = M\(N * x0 + b);
    if norm(x - x0,inf) < err * norm(x, inf)
        return
    end
end
