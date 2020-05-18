function x=poly_chebyshev_1(a, b, m)
  %[a, b]
  %m - numar de noduri
  %x - nodurile polinomului
  
  x = 1/2*(a+b) + 1/2*(b-a)*cos(((2*[0:m] + 1)*pi/(2*m + 2)));
  
end