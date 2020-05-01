function SimHigham()
  x = logspace(0, 1, 2013);
  y = Higham(x);
  plot( x, y, 'k.', x, x, '..' );
end