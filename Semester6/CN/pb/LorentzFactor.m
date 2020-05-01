function res=LorentzFactor(v)
  %v in km/h
  c = 299792458; % m/s
  v = (v * 5)/18; % m/s
  res = 1/sqrt(1 - v^2/c^2);
end