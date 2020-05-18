function yy = hermite(X, y, dy, x)
  %X - puncte stiute
  %y - f(X)
  %dy - f'(X)
  %x - puncte care trebuie aproximate
  %yy - approximarea lui f in punctele x
  
  [z, Q] = double_nodes_diff(X, y, dy);
  
  nx = length(x);
  nX = length(z);
  
  for i = 1:nx
    x_diff = x(i) - z;
    y(i) = [1, cumprod(x_diff(1:nX-1))]*Q';
  end
  yy = y;
end