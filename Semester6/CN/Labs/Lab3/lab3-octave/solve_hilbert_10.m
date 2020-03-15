function solve_hilbert_10
  A = hilb(10)
  b = A*ones(10, 1)
  x = A\b