function [nodes, coeff] = gauss_legendre(n)
    
  beta=[2,(4-([1:n-1]).^(-2)).^(-1)]; 
  alpha=zeros(n,1);
  [nodes,coeff]=gauss_quad(alpha,beta);
end