function cond=ex1
  %Matricea initiala
  A = [10, 7, 8, 7; 7, 5, 6, 5; 8, 6, 10, 9; 7, 5, 9, 10];
  b = [32; 23; 33; 31];
  %Perturbam matricea rezultat
  bp = [32.1; 22.9; 33.1; 30.9];
  xe = A\b
  xp1 = A\bp
  %Calculam erorile
  eri1 = norm(b-bp)/norm(b)
  ero1 = norm(xe - xp1)/norm(xe)
  ero1/eri1
  
  %Perturbam Matricea initiala
  Ap = [10, 7, 8.1, 7.2; 7.08, 5.04, 6, 5; 8, 5.98, 9.89, 9; 6.99, 4.99, 9, 9.98];
  xp2 = Ap\b
  eri2 = norm(A-Ap)/norm(A)
  ero2 = norm(xe-xp2)/norm(xe)
  ero2/eri2
  
  cond(A)