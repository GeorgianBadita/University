function x = DiffNormalTaylorLorentz()
  v = 1;
  while LorentzFactor(v) - LorentzFactorTaylor(v) <= eps
    v += 100;
  end
  x = v - 1;
end