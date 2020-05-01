function rez_new=lorentzTaylorConv(x)
  rez_old=1; 
  term=x^2/2; 
  rez_new=rez_old+term;
  k=2;
  while rez_old~=rez_new
   rez_old=rez_new;
   term=term*(2*k-1)/(2*k)*x^2;
   rez_new=rez_old+term;
   k=k+1;
  end
end
