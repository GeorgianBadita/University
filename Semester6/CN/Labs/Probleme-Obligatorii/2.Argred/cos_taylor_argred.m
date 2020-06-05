function rez = cos_taylor_argred(x)
  twoOverPi = sym(2)/sym(pi);
  y = sym(x) * vpa(twoOverPi, 200);
  k = floor(y);
  r = double((y - k) * pi / 2);
  lastBits = mod(k, 4);
 
  if lastBits == 0
    rez = cos_taylor(r);
  elseif lastBits == 1
    rez = -sin_taylor(r);
  elseif lastBits == 2
    rez = -cos_taylor(r);
  else
    rez = sin_taylor(r);
  end