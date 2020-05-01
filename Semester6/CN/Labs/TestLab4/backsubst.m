function x = backsubst(U, b)
  n=length(b);
  x=zeros(size(b));
  for k=n:-1:1
    x(k)=(b(k)-U(k,k+1:n)*x(k+1:n))/U(k,k);
  end
end