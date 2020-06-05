function [nodes, coeff] = gauss_quad(a, b)
  %a - alpha
  %b - beta
  %nodes - noduri
  %coeff - coeficienti
  
  n = length(a); 
  rb = sqrt(b(2:n));
  jacobi = diag(a) + diag(rb, -1) + diag(rb, 1);
  [V, D] = eig(jacobi);
  nodes = diag(D);
  coeff = b(1)*V(1,:).^2;
end