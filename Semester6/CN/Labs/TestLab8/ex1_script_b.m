a = -pi;
b = pi;
xx = linspace(a, b, 200);
n = 10;

f = @(x) x + sin(x .^ 2);
x = linspace(a, b, n);
y = f(x);


phi = @(x)[ones(1, length(x)); x; x.^2; x.^3];

yy_echidist = leat_sq_approx(x, y, phi, xx);


figure(1);
hold on;
plot(x, y, 'o');
plot(xx, f(xx));
plot(xx, yy_echidist);
legend('noduri echidist', 'f(x)', 'least sq approx', 'Location', 'BestOutside');



x = sort(cos((0:n)*pi/n))*(b-a)/2+(a+b)/2;

y = f(x);
phi = @(x)[ones(1, length(x)); x; x .^2; x .^ 3];

yy_chebyshev = leat_sq_approx(x, y, phi, xx);

figure(2);
hold on;
plot(x, y, 'o');
plot(xx, f(xx));
plot(xx, yy_chebyshev);
legend('noduri chebyshev', 'f(x)', 'least sq approx', 'Location', 'BestOutside');