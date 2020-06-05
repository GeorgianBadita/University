function q = eval_integral(nodes, coeff, f, a, b)
    %nodes - noduri
    %coeff - coeficienti
    %f - functia de integrat
    %a - capatul stang al intervalului
    %b - capatul drept al intervalului
    
    scale = 1;
    if nargin == 5
        scale = (b-a)/2;
    end
    q = scale*sum(coeff*f(nodes));
end
