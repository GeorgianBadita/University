
A = construct_matrix_A(100);
b = construct_b_vector(100);
xe = A\b;

x_lup = solveLUP(A, b);
x_choleksy = solve_cholesky(A, b);

printf("Err sol LUP %d, cond(A)*eps = %d\n", norm(x_lup - xe)/norm(xe), cond(A)*eps);
printf("Err sol Cholesky %d, cond(A)*eps = %d\n", norm(x_choleksy - xe)/norm(xe), cond(A)*eps);
