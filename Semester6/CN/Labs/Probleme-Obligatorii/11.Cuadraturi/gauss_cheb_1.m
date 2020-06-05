function [nodes, coeff]=gauss_cheb_1(n)
coeff = pi/n*ones(1,n);
nodes = sort(cos(pi*([1:n]'-0.5)/n));
end