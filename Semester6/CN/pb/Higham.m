function x=Higham(x)
  for i=1:52
    x = sqrt(x);
  endfor
  
  for i = 1:52
    x = x.^2;
  endfor
end