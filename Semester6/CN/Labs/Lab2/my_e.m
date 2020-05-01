function res = my_e(x)
  s = 0;
  n = 1;
  t = 1;
  while s + t ~= s
    s = s + t;
    t = t * x/n;
    n = n + 1;
  end
  res = s;
end