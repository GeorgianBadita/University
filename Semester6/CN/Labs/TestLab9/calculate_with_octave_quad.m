function y = calculate_with_octave_quad(x, f, tol)
  %
  % Functie care calculeaza integrala f pe toate
  % intervalele de forma [a, x(i)], folosind proprietatea de 
  % aditivitate a integralei cu functia quad din octave
  %
  n = length(x);
  int = 0;
  y = zeros(1, n);

  for i=1:n
    y(i) = exp(-x(i)^2) * int;
    if i == n
      break;
    end
    int = int + quad(f, x(i), x(i+1), tol);
  end
  
end