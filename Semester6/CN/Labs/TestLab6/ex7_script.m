a = -1;
b = 1;

m = 8;

puncte = [a:0.001:b];

noduri_echidist = poly_echidistant(a, b, m);
noduri_chebyshvev_1 = poly_chebyshev_1(a, b, m);
noduri_chebyshvev_2 = poly_chebyshev_2(a, b, m);



y_echidistant = eval_node_pol(puncte, noduri_echidist);
y_chebyshev_1 = eval_node_pol(puncte, noduri_chebyshvev_1);
y_chebyshev_2 = eval_node_pol(puncte, noduri_chebyshvev_2);

hold on;
plot(puncte, y_echidistant, 'Color', 'r'); 
plot(puncte, y_chebyshev_1, 'Color', 'b'); 
plot(puncte, y_chebyshev_2, 'Color', 'g'); 


% O interpretare matematica ar fi:
% Din curs avem ca eroare de interpolare depinde de
% um(x) = prod(0, m){(x-xi)}
% deci este logic ca dorim sa minimizam max(|prod(0, m){(x-xi)}|), iar
% din curs stim ca max(|prod(0, m){(x-xi)}|) <= 2^(-n+1), pentru noduri Cebi̧sev

% Interpretare grafica
% Alegerea optima a nodurilor se face asa incat oscilatiile sa fie de aceeasi
% marime

