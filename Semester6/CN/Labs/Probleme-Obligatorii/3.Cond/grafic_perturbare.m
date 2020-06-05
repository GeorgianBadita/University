function grafic_perturbare(max_coeff)

pol=poly(-max_coeff:max_coeff);
h_plot=plot([-max_coeff:max_coeff],zeros(1,max_coeff*2 + 1),'.');
set(h_plot,'Markersize',30, 'color', 'black');
hold on
for m=1:1000
    normal_dis=normrnd(0,10^(-5),[1,2*max_coeff + 2]);
    perturbed_poly=pol .* normal_dis;
    poly_roots=roots(perturbed_poly);
    interm_plot=plot(poly_roots,'k.');
    set(interm_plot,'Markersize',8, 'color', 'blue')
end
axis equal
end