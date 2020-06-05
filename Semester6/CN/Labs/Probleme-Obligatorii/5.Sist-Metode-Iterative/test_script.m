
A = gen_input_matrix(500000);
b = gen_target_vector(500000);

x0 = zeros(size(b));
niter = 50;
omega = 1.5;
err = 1e-6;

x_jacobi = jacobi(A,b, x0, err, niter);
x_gauss = gaussSeidel(A, b, x0, err, niter);
x_relax = sor(A, b, omega, x0, err, niter);



fprintf("norm(b-A*x_jacobi)/norm(b) = %d\n", norm(b-A*x_jacobi)/norm(b));
fprintf("norm(b-A*x_gauss)/norm(b) = %d\n", norm(b-A*x_gauss)/norm(b));
fprintf("norm(b-A*x_relax)/norm(b) = %d\n", norm(b-A*x_relax)/norm(b));

