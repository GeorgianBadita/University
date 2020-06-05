a = 0;
b = pi;

f = @(x) cos(x);

n = 10;

[nodes, coeff] = gauss_legendre(n);

nodes = (nodes + 1)*(b-a)/2

coeff * f(nodes)
