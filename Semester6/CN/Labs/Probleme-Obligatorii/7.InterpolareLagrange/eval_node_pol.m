function yy=eval_node_pol(puncte, noduri)
  %Functie care evalueaza polinomul nodurilor in punctele [puncte]
  %Polinomul nodurilor are forma: Produs(i=1,n)(x-noduri[i])
  
  yy = ones(size(puncte));
  n = length(noduri);  
  for j=1:n
    yy = yy.*(puncte - noduri(j)); 
  end
end