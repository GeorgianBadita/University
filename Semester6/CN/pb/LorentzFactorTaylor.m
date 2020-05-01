function res=LorentzFactorTaylor(v)
  warning('off');
  syms x;
  f = (1 - x^2)^(-1/2);
  f_taylor = taylor(f, x, 0, 'order', 4);
  
  c = 299792458; % m/s
  v = (v * 5)/18; % m/s
  x = v/c;
  res = double(subs(f_taylor));
end