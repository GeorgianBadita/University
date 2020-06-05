function conditionare = conditionare_radacina(poly, root)
  warning('off');
  powers = [length(poly) - 1:-1:1];
  p_deriv = powers .* poly(1: end-1);
  conditionare = 1./(abs(polyval(p_deriv, root).*root)).*(polyval(abs(poly(2:end)),abs(root)));
  poz = find(root == 0);
  conditionare(poz) = 1; 
end