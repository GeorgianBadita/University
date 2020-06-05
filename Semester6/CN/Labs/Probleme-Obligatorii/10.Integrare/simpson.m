function y = simpson(a, b, f)
  %a - capat stang interval
  %b - capat drept interval
  %f - functia a carui integrala vrem sa o calculam
  
  y = (b-a)/6*(f(a) + f(b) + 4*f(a + (b-a)/2));
end
