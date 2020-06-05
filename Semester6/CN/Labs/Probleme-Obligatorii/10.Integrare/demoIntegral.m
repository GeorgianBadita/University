f = @(t) exp(t .^2);
a = 0; b = 0.5;
tol = 1e-9;
N = 100;

integral_value_adquad2 = adquad(a, b, f, tol)
integral_value_romberg = Romberg(a, b, f, tol, N)
integral_value_matlab = integral(f, a, b)