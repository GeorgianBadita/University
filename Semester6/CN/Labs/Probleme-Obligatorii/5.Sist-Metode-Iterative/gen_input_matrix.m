function matrix = gen_input_matrix(n)
  matrix = sparse_teoplitz([5, -1, 0, -1, zeros(1, n-4)]);
end