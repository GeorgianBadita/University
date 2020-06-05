function [nodes,coeff]=gauss_hermite(n)

beta=[sqrt(pi),[1:n-1]/2];
alpha=zeros(n,1);
[nodes,coeff]=gauss_quad(alpha,beta);
end