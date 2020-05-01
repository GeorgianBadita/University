function A=construct_matrix_A(n)
  A = diag(3*ones(n, 1));
    for i = 1:n
      A(i, n - i + 1) = 1/2;
    end
  if mod(n, 2) == 1
    poz = idivide(n, 2) + 1;
    A(poz, poz) = 3;
  end
  A(2:n+1:end) = -1;
  A(n+1:n+1:end) = -1;
end

%!assert (construct_matrix_A(2) == [3, -1; -1, 3]);
%!assert (construct_matrix_A(3) == [3, -1, 1/2; -1, 3, -1; 1/2, -1, 3]);
%!assert (construct_matrix_A(5) == [3, -1, 0, 0, 1/2; -1, 3, -1, 1/2, 0; 0, -1, 3, -1, 0; 0, 1/2, -1, 3, -1; 1/2, 0, 0, -1, 3]);