function [nodes, coeff]=gauss_laguerre(n,a)
k=1:n-1;
alpha=[a+1, 2*k+a+1];
beta=[gamma(1+a),k.*(k+a)];
[nodes, coeff]=gauss_quad(alpha,beta);
end