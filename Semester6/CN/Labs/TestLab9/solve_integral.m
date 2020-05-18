f = @(t) exp(t .^2);
a = 0; b = 0.5;
err = 1e-9;

x = [a:0.1:b];


adquad_implementation = calculate_with_adquad(x, f, err)
octave_quad_implementation = calculate_with_octave_quad(x, f, err)

absolute_error = norm(adquad_implementation - octave_quad_implementation);

printf("Difference between adquad and octave quad: %d\n", absolute_error);