function s=sin_taylor(x)  
  s = 0;
  t = x;
  n = 1;
  while s + t ~= s
    s = s+ t;
    t = -t * x^2 *1/((n + 1)*(n + 2));
    n = n+ 2;
  end
  