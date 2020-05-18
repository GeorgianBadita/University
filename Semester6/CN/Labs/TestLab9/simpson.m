function y = simpson(a, b, f)
  y = (b-a)/6*(f(a) + f(b) + 4*f(a + (b-a)/2));
end
