function E = ex5_rec(n, k)
  E = 0;
  for j = n + k: - 1: n + 1
    E = (1-E)/j;
  end