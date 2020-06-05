function [nodes, coeff] = gauss_quad(alpha, beta)
    %functie care calculeaza noduri si coeficienti
    %in functie de alpha si beta
    
    n = length(alpha);
    rb = sqrt(beta(2:n));
    J = diag(alpha) + diag(rb, -1) + diag(rb, 1);
    [V,D] = eig(J);
    nodes = diag(D);
    coeff = beta(1)*V(1,:).^2;
end