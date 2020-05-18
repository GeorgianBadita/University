function w = weights_echidist(x)
  n = length(x);
  w = ones(1,n);
  for i=1:n
      w(i) = prod(x(i) - x([1:i-1,i+1:n]));
  end
  w=1./w;
end