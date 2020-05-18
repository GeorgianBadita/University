f = @(x) 1./(1+x.^2);          % define function f
a = -5; b = 5;                 % endpoints of interval
n = 11;                        % number of nodes for interpolation
xt = linspace(-5,5,1000);      % use these x values for plotting

xe = a + (0:n-1)*(b-a)/(n-1);  % equidistant nodes, same as  xe = linspace(a,b,n)
ye = f(xe);                    % find values of f at nodes xe

d = divdiff(xe,ye);            % use divided difference algorithm to find coefficients d

pt = evnewt(d,xe,xt);          % evaluate interpolating polynomial at points xt
plot(xt,f(xt),xt,pt,xe,ye,'o'); grid on  % plot function f and interpolating polynomial
                                         % mark given points with 'o'