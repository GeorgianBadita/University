function [nodes, coeff]=gauss_cheb_2(n)

beta=[pi/2,1/4*ones(1,n-1)];
alpha=zeros(n,1);
[nodes,coeff]=gauss_quad(alpha,beta);

end
