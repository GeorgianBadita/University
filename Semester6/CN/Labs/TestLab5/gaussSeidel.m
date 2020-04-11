function x=gaussSeidel(A,b)
  %x - solutie
  %A - mat sistemului
  %b - solutia
  err=1e-7; 
  x = zeros(size(b));
  M = tril(A);
  N = b - A*x;
  for i=1:50
      T = M\N; 
      x = x + T; 
      N = b - A * x;  
     if norm(N, inf) < err && norm(T, inf) < err
       return; 
     end
  end
 end