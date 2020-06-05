f = @(t) exp(t .^2);
a = 0; b = 0.5;
tol = 1e-9;

x = [a:0.1:b];


adquad_implementation = calculate_with_adquad(x, f, tol)
octave_quad_implementation = calculate_with_octave_quad(x, f, tol)

absolute_error = norm(adquad_implementation - octave_quad_implementation);

printf("Difference between adquad and octave quad: %d\n", absolute_error);