function x=relax(A,b)
  %x - solutie
  %A - mat sistemului
  %b - solutia
  omega = 1.5;
  err=1e-7; 
  x = zeros(size(b));
  M = M=1/omega*diag(diag(A))+tril(A,-1);
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