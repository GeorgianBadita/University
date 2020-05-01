function [x,y, z] = gauss33(a, b, c, m, d, e, f, n, g, h, i, o)
  
    
   %ax + by + cz = m
   %dx + ey + fz = n
   %gx + hy + iz = o
   
  fact = d/a;  % 1 flop
  fact1 = g/a; % 1 flop

  e = e - fact * b; % 2 flop
  f = f - fact * c; % 2 flop
  n = n - fact * m; % 2 flop

  h = h - fact1 * b; % 2 flop
  i = i - fact1 * c; % 2 flop
  o = o - fact1 * m; % 2 flop
  
  
  fact2 = h/e; % 1 flop
  i = i - fact2 * f; % 2 flop
  o = o - fact2 * n; % 2 flop

  z = o/i; % 1 flop
  y  = (n - f*z)/e; % 3 flop
  x = (m - b*y - c*z)/a; % 5 flop
  
  %total 28 flops
    
end