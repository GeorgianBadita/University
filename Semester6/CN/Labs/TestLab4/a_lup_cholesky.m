
A = construct_matrix_A(12);

[L, U, P] = LUP_decomposition(A);

printf("L*U - P*A = %d\n", norm(L*U-P*A));

R = cholesky_decomposition(A);

printf("R*R - A = %d\n", norm(R'*R - A));