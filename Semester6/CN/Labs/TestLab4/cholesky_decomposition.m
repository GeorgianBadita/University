function R=cholesky_decomposition(A)
  [m,n]=size(A);
  R = A;
  for k=1:m
      for j=k+1:m
          R(j,j:m)=R(j,j:m)-R(k,j:m)*R(k,j)/R(k,k);
      end
      R(k,k:m)=R(k,k:m)/sqrt(R(k,k));
  end
  R = triu(R);
end