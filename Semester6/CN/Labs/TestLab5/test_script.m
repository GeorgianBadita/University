
A = gen_input_matrix(500000);
b = gen_target_vector(500000);

x_jacobi = jacobi(A,b);
x_gauss = gaussSeidel(A,b);
x_relax = relax(A,b);



printf("norm(b-A*x_jacobi)/norm(b) = %d\n", norm(b-A*x_jacobi)/norm(b));
printf("norm(b-A*x_gauss)/norm(b) = %d\n", norm(b-A*x_gauss)/norm(b));
printf("norm(b-A*x_relax)/norm(b) = %d\n", norm(b-A*x_relax)/norm(b));