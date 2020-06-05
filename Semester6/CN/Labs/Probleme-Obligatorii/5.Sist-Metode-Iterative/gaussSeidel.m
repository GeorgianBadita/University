function xx=gaussSeidel(A,b,x0,err,niter)
% A - matricea sistemului
% b - vectorul solutie
% x0 - valoarae initiala a lui x
% err - erroarea
% niter - numar de iteratii
% xx - solutia finala

[m,n] = size(A);
x = x0;
M = tril(A);
N = M-A;
for i=1:min(niter, 50)
    xn = M\(N*x+b);
    if norm(xn -x ,inf) < err * norm(xn, inf)
        xx = xn;
        return
    end
    x = xn;
end
xx = xn;
end

