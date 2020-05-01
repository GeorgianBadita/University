function PlotNormalTaylorLorentz
  xd = 1:10:170005;
  yd = arrayfun(@LorentzFactor, xd);
  yd_taylor = arrayfun(@LorentzFactorTaylor, xd);
  hold on
  plot(xd, yd, 'r-.', xd, yd_taylor, '..')
  title('Taylor approximation  vs actual function')
  legend('Taylor', 'Function')
end