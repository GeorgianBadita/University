a = -2*pi;
b = 2*pi;
x = linspace(a, b, 200);
f = @(x) x.^2 .* sin(x);
df = @(x) 2*x.*sin(x) + x.^2 .* cos(x);
y = f(x);
dy = df(x);
err = 1e-6;

y_norm = norm(y);

m_echi = 1;
xx = linspace(a, b, m_echi);
yy_echi = hermite(xx, f(xx), df(xx), x);


while norm(yy_echi - y)/y_norm > err
  m_echi = m_echi + 1;
  xx = linspace(a, b, m_echi);
  yy_echi = hermite(xx, f(xx), df(xx), x);
end

fprintf("Interpolare Hermite cu noduri duble, noduri echidistante, nr_necesar noduri: %d\n", m_echi);

m_che = 1;
xx = noduri_cebisev_2(a, b, m_che);
yy_che = hermite(xx, f(xx), df(xx), x);

while norm(yy_che - y)/y_norm > err
  m_che = m_che + 1;
  xx = noduri_cebisev_2(a, b, m_che);
  yy_che = hermite(xx, f(xx), df(xx), x);
end


fprintf("Interpolare Hermite cu noduri duble, noduri Cebisev, nr_necesar noduri: %d\n", m_che);

hold on;
plot(x, y, 'Color', 'r');

plot(x, yy_che, 'Color', 'g');

plot(x, yy_echi, 'Color', 'b');

legend('x^2*sin(x)', 'hermite che', 'hermite echi');