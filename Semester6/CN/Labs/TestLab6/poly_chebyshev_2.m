function x=poly_chebyshev_2(a, b, m)
  %[a, b]
  %m - numar de noduri
  %x - nodurile polinomului
  
  x = 1/2*(a+b) + 1/2*(b-a)*cos([0:m]*pi/m);
  
end