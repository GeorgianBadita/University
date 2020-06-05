function y = calculate_with_adquad(x, f, tol)
  %
  % Functie care calculeaza integrala f pe toate
  % intervalele de forma [a, x(i)], folosind proprietatea de 
  % aditivitate a integralei, folosind o cuadratura adaptiva
  %
  n = length(x);
  int = 0;
  y = zeros(1, n);

  for i=1:n
    y(i) = exp(-x(i)^2) * int;
    if i == n
      break;
    end
    int = int + adquad(x(i), x(i+1), f, tol);
  end
  
end