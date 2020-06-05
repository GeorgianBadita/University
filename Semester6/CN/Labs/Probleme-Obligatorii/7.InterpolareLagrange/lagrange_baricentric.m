function y=lagrange_baricentric(X, Y, x, w)
  %X - puncte pentru care se stie f(x)
  %Y - yi pentru care f(X(i)) = y(i)
  %x - puncte pentru care trebuie sa apriximam functia
  %y - rezultatele
  
  n = length(X);
 
  num = zeros(size(x));
  den = zeros(size(x));
  exact = zeros(size(x));
  for i=1:n
    x_diff = x-X(i);
    
    new_w = w(i) ./ x_diff;
    num = num + new_w * Y(i);
    den = den + new_w;
    exact(x_diff==0) = i;
  end
  
  y = num ./ den;
  ii = find(exact);
  y(ii) = Y(exact(ii));
end