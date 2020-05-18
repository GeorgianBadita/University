function q=adquad(a, b, f, err)
  q1 = simpson(a, b, f);
  q2 = simpson(a, (a+b)/2, f) + simpson((a+b)/2, b, f);
  
  if abs(q1 - q2) < 15 * err
    q = q2;
    return;
  else
    q = adquad(a, (a+b)/2, f, err/2) + adquad((a+b)/2, b,f, err/2);
  end
end


